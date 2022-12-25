def insertions(a):
    n=len(a)

    i=1
    j=0

    while(i<=n-1):
        temp=a[i]
        j=i-1
        while(j>=0):
            if(a[j]>temp):
                a[j+1]=a[j]

            else:
                break

            j-=1
        a[j+1]=temp
        i+=1

    ans=[]
    for i in range(-1,-6,-1):
        ans.append(a[i])

    print()
    print("Top Five Scorers in Department using Insertion Sort :")
    print(ans)


def shells(a):
    n=len(a)

    g=n//2
    while g>0:
        j=g
        while j<n:
            i=j-g
            while i>=0:
                if(a[i+g]>a[i]):
                    break

                else:
                    a[i+g],a[i]=a[i],a[i+g]
                i=i-g
            j+=1
        g=g//2

    ans = []
    for i in range(-1, -6, -1):
        ans.append(a[i])

    print()
    print("Top Five Scorers in Department using Shell Sort :")
    print(ans)

a=[]
while(True):
    print()
    print("* * * * * Percentage Sorting System * * * * *")
    print('''1) Insertion Sort
2) Shell Sort
3) Exit''')
    print("Enter your choice :")
    ch=int(input())

    if(ch!=3):
        print()
        n=int(input("Enter number of Students :"))

        for i in range(n):
            y=float(input(f"Enter percentage of Student {i+1} : "))
            a.append(y)

    if(ch==1):
        insertions(a)

    elif(ch==2):
        shells(a)

    else:
        exit(0)





