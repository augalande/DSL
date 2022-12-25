nc=int(input("Enter number of students playing Cricket :"))
nb=int(input("Enter number of students playing Badminton :"))
nf=int(input("Enter number of students playing Football :"))

cricket=[]
badminton=[]
football=[]

print("Enter names of students playing Cricket :")
for i in range(0,nc):
    name=str(input())
    cricket.append(name)

print("Enter names of students playing Badminton :")
for i in range(0,nb):
    name=str(input())
    badminton.append(name)

print("Enter names of students playing Football :")
for i in range(0,nf):
    name=str(input())
    football.append(name)

def intersection(lst1,lst2):
    lst3=[]
    for name in lst1:
        if name in lst2:
            lst3.append(name)
    return lst3

def union(lst1,lst2):
    lst3=lst1.copy()
    for name in lst2:
        if name not in lst1:
            lst3.append(name)
    return lst3

def difference(lst1,lst2):
    lst3=[]
    for name in lst1:
        if name not in lst2:
            lst3.append(name)
    return lst3

print("List of students who play both Cricket and Badminton :")
lst4=intersection(cricket,badminton)
print(lst4)

print("List of students who play either Cricket or Badminton but not both :")
lst5=difference(union(cricket,badminton),intersection(cricket,badminton))
print(lst5)

lst6=difference(football,union(cricket,badminton))
print("Number of students who play neither Cricket nor Badminton :",end="")
print(len(lst6))

lst7=difference(intersection(cricket,football),badminton)
print("Number of students who play Cricket and Football but not Badminton :",end="")
print(len(lst7))

