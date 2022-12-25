def partition(a,lb,ub):
    start=lb
    end=ub
    pivot=a[lb]

    while(start<end):
        while(start<=ub and a[start]<=pivot):  #Imp and condition or else out of bounds error occurs
            start+=1

        while(end>=lb and a[end]>pivot):        #Imp and condition or else out of bounds error occurs
            end-=1

        if(start<end):
            a[start],a[end]=a[end],a[start]

    a[lb],a[end]=a[end],a[lb]    # Very Imp Step
    return end

def quicksort(a,lb,ub):
    if(lb<ub):
        loc=partition(a,lb,ub)
        quicksort(a,lb,loc-1)
        quicksort(a,loc+1,ub)

print()
print("* * * * * Quick Sort * * * * *")
n=int(input("Enter number of students :"))
a=[]

for i in range(n):
    y=float(input(f"Enter Percentage of Student {i+1} : "))
    a.append(y)

quicksort(a,0,n-1)

ans=[]
for i in range(-1,-6,-1):
    ans.append(a[i])

print()
print("Top Five Scorers of the Department :")
print(ans)


