#include <bits/stdc++.h>
using namespace std;

void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int mini(int a[],int i,int j)
{
    if(i==j)
    return i;
    int k=mini(a,i+1,j);
    if(a[i]<=a[k])
        return i;
    else
        return k;
}

void selection_sort_recursively(int a[],int n,int ind=0)
{
    if(ind==n)
        return;
    int k=mini(a,ind,n-1);
    if(k!=ind)
        //int temp=a[ind];
        //a[ind]=a[k];
        //a[k]=temp;
        swap(&a[ind],a[k]);
    recurselection(a,n,ind+1);
}


void insertion_sort_recursively(int a[],int n)
{
    if(n<=1)
        return;
    recurinsertion(a,n-1);
    int k=a[n-1],j=n-2;
     while(k<a[j] && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
}

void bubble_sort_recursively(int a[],int n)
{
     if(n==1)
        return;
    int c=0;
    for (int j=0;j<n-1;j++){
        if (a[j]>a[j+1])
            //int temp=a[j];
            //a[j]=a[j+1];
            //a[j+1]=temp;
            //swap(&a[j],&a[j+1]);
            c++;
    }
    if(c==0)
        return;
    recurbubble(a,n-1);
}

void merge(int arr[],int p,int q,int r)
{
    int i,j,k;
    int n1=m-l+1,n2=r-m;
    int l1[n1],r1[n2];
    for(int i=0;i<n1;++i)
        l1[i]=arr[l+i];
    for(int j=0;j<n2;j++)
        r1[j]=arr[m+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if(l1[i]<=r1[j]){
            arr[k]=l1[i];
            i++;
        }else{
            arr[k]=r1[j];
            j++;
        }
        k++;
    }
    while(j<n2){
        arr[k]=r1[j];
        j++;
        k++;
    }
}

void merge_sort_recursively(int arr[],int p,int r)
{
    if(p<r){
        int q=(p+r)/2;
        merge_sort_recursively(arr,p,q);
        merge_sort_recursively(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void Bubble_Sort(int A[],int n)
{
    int flag=0;
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            return;
    }

}

void Selection_Sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++ ){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
}

void Insertion_Sort(int arr[],int n)
{
    for(int i=1;i<n;i++){
        int temp=arr[i],j;
        for(j=i-1;j>=0;j--){
            if(arr[j] > temp)
                arr[j+1]=arr[j]; // shift
            else //wait
                break;

        }
        //copy temp value
        arr[j+1]=temp;
    }
}

int main()
{
    int n=1000;
    int arr[n],brr[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
        brr[i]=arr[i];
    }
    cout<<endl<<"After sorting : "<<endl;
    while(1){
        cout<<"Select the Sort:"<<endl;
        cout<<"1.Bubble Sort"<<endl;
        cout<<"2.Selection Sort"<<endl;
        cout<<"3.Insertion Sort"<<endl;
        cout<<"4.Recursive Bubble Sort"<<endl;
        cout<<"5.Recursive Selection Sort"<<endl;
        cout<<"6.Recursive Insertion Sort"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter choice : ";
        int m;
        cin>>m;
        clock_t t;
        double time_taken;
        for(int i=0;i<n;i++)
            arr[i]=brr[i];
        switch(m){
        case 1: t=clock();
                Bubble_Sort(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken=((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 2: t=clock();
                selection_Sort(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken=((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 3: t=clock();
                Insertion_Sort(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 4: t=clock();
                bubble_sort_recursively(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 5: t=clock();
                selection_sort_recursively(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 6: t=clock();
                insertion_sort_recursively(arr,n);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 7: t=clock();
                merge_sort_recursively(arr,0,n-1);
                t=clock()-t;
                for(int i=0;i<n;i++)
                        cout<<arr[i]<<" ";
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                cout<<endl<<"Time Taken :"<<time_taken<<endl;
                break;
        case 8: exit(0);
        }
    }
    return 0;


}
