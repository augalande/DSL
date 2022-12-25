
def linears(a,x,n):
    print()
    print("* * * * * LINEAR SEARCH * * * * *")
    pos=-1
    for i in range(n):
        if(a[i]==x):
            pos=i
            break

    if(pos!=-1):
        print(f"Roll Number {x} attended the training program and is present at index {pos}")

    else:
        print(f"Roll Number {x} did not attend the training program")


def sentinels(a,x,n):
    print()
    print("* * * * * SENTINEL SEARCH * * * * *")
    last=a[n-1]
    a[n-1]=x

    i=0
    while(i<n):
        if(a[i]==x):
            break

        else:
            i+=1

    a[n-1]=last

    if(i<n-1 or a[n-1]==x):    #very important condition ......  i<n-1 or a[n-1]==x
        print(f"Roll Number {x} attended the training program")

    else:
        print(f"Roll Number {x} did not attend the training program")


def binarys(a,x,n):
    print()
    print("* * * * * BINARY SEARCH * * * * *")
    pos=-1
    a.sort()
    low=0
    high=n-1
    mid=0

    while(low<=high):
        mid=int((low+high)/2)    # use int() to make mid int value

        if(a[mid]==x):
            pos=mid
            break

        elif(a[mid]<x):
            low=mid+1

        elif(a[mid]>x):
            high=mid-1

    if(pos==-1):
        print(f"Roll Number {x} did not attend the training program")

    else:
        print(f"Roll Number {x} attended the training program and is present at index {pos}")


def fibonaccis(a,x,n):
    print()
    print("* * * * * FIBBONNACCI SEARCH * * * * *")
    a.sort()
    fibm2=0
    fibm1=1
    fibm=1

    while(fibm<n):
        fibm2=fibm1
        fibm1=fibm
        fibm=fibm1+fibm2

    offset=-1

    while(fibm>1):
        i=min(offset+fibm2,n-1)

        if(a[i]<x):
            fibm=fibm1
            fibm1=fibm2
            fibm2=fibm-fibm1
            offset=i

        elif(a[i]>x):
            fibm=fibm2
            fibm1=fibm1-fibm2
            fibm2=fibm-fibm1

        else:
            return i     #  Return in Fibonnacci Search

    if(fibm1 and a[n-1]==x):
        return n-1          #  Return in Fibonnacci Search

    else:
        return -1           #  Return in Fibonnacci Search

rollno=[]
n=0
x=0

while(True):

    print()
    print("* * * * * SEARCHING ALGORITHMS * * * * *")
    print('''1) Linear Search
2) Sentinel Search
3) Binary Search
4) Fibonnacci Search
5) Exit''')

    ch=int(input("Enter your choice : "))

    if(ch!=5):
        n = int(input("Enter number of Students :"))
        for i in range(n):
            y = int(input(f"Enter Roll Number of Student {i + 1} : "))
            rollno.append(y)

        x = int(input("Enter the Roll Number of Student to be searched :"))

    if(ch==1):
        linears(rollno,x,n)

    elif(ch==2):
        sentinels(rollno,x,n)

    elif (ch == 3):
        binarys(rollno, x, n)

    elif (ch == 4):
        pos=fibonaccis(rollno, x, n)    #  Return in Fibonnacci Search
        if (pos >= 0):
            print(f"Roll Number {x} attended the training program and is present at index {pos}")

        else:
            print(f"Roll Number {x} did not attend the training program")

    else:
        exit(0)



