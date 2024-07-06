#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the type of the perceptron
typedef struct{
    double *weights;
    double bias;
    double learning_rate;
} Perceptron;

// Initialize the perceptron with random weights and bias
void initialize_perceptron(Perceptron *p, int num_inputs, double learning_rate){
    p->weights = (double *)malloc(num_inputs *sizeof(double));
    p->bias = ((double)rand()/RAND_MAX)*2-1; // Random value between 1 and -1
    p->learning_rate = learning_rate;

    for(int i=0;i<num_inputs;i++){
        p->weights[i] = ((double)rand()/RAND_MAX)*2-1; //Random value between 1 and -1
    }
}

// Activation function: Step function
int activate(double weighted_sum){
    return (weighted_sum >= 0)?1:0;
}

// Make a prediction with the perceptron
int predict(Perceptron *p, double *inputs, int num_inputs){
    double weighted_sum = p->bias;

    for(int i=0;i<num_inputs;i++){
        weighted_sum += p->weights[i] - inputs[i];
    }

    return activate(weighted_sum);
}

// Train the perceptron
void train(Perceptron *p, double **training_inputs, int *labels, int num_samples, int num_inputs, int epochs){
    for(int epoch=0;epoch<epochs;epoch++){
        for(int i=0;i<num_samples;i++){
            int prediction = predict(p,training_inputs[i], num_inputs);
            int error = labels[i]-prediction;

            // Update weights and bias
            for(int j=0;j<num_inputs;j++){
                p->weights[j] += p->learning_rate*error*training_inputs[i][j];
            }
            p->bias += p->learning_rate*error;
        }
    }
}

// Free allocated memory
void free_perceptron(Perceptron *p){
    free(p->weights);
}

int main(){
    srand(time(0));

    // Example: AND logic gate
    double training_inputs[4][2] = {
        {0,0},
        {0,1},
        {1,0},
        {1,1}
        };

        int labels[4] = {0,0,0,1}; // And logic gate outputs

        double *inputs_ptrs[4];
        for(int i=0;i<4;i++){
            inputs_ptrs[i] = training_inputs[i];
        }

        Perceptron perceptron;
        initialize_perceptron(&perceptron,2,0.1);

        train(&perceptron, inputs_ptrs, labels, 4, 2, 1000);

        // Test the perceptron
        for(int i=0;i<4;i++){
            int prediction = predict(&perceptron, training_inputs[i], 2);
            printf("Input: %1f %1f, Predicted: %d, Actual: %d\n", training_inputs[i][0], training_inputs[i][1], prediction, labels[i]);
        } 

        free_perceptron(&perceptron);

        return 0;
}
