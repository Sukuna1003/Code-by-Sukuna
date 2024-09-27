x=[]
choosing= True 
while choosing == True:
    number= input("add numbers to the list")
    x.append(int(number))
    print("--list--")
    for n in x:
        print(n)
    ask=str(input("do you want to add more numbers? Yes or No"))
    if ask=="No":
        choosing= False 
    
print("--Even Numbers That You Chose--")
for item in x:
    if item % 2 == 0:
        print(str(item))
