def addition(m1, m2, r, c):
    m3 = [[0 for i in range(c)] for i in range(r)]

    for i in range(r):
        for j in range(c):
            m3[i][j] = m1[i][j] + m2[i][j]

    print("Matrix 1: ", end="")
    print(m1)
    print("Matrix 2: ", end="")
    print(m2)
    print("Addition Matrix 3: ", end="")
    print(m3)


def subraction(m1, m2, r, c):
    m3 = [[0 for i in range(c)] for i in range(r)]

    for i in range(r):
        for j in range(c):
            m3[i][j] = m1[i][j] - m2[i][j]

    print("Matrix 1: ", end="")
    print(m1)
    print("Matrix 2: ", end="")
    print(m2)
    print("Subraction Matrix 3: ", end="")
    print(m3)


def transpose(m1, r, c):
    m2 = [[0 for i in range(r)] for i in range(c)]

    for i in range(r):
        for j in range(c):
            m2[j][i] = m1[i][j]

    print("Matrix : ", end="")
    print(m1)
    print("Transpose Matrix : ", end="")
    print(m2)


def multiplication(m1, m2, r1, c1, r2, c2):
    if (c1 == r2):
        print("Multiplication Possible!!")
        r3 = r1
        c3 = c2
        m3 = [[0 for i in range(c3)] for i in range(r3)]

        for i in range(r3):
            for j in range(c3):
                for k in range(c1):  # c1 or r2  both are fine
                    m3[i][j] += m1[i][k] * m2[k][j]

        print("Matrix 1: ", end="")
        print(m1)
        print("Matrix 2: ", end="")
        print(m2)
        print("Multiplication Matrix 3: ", end="")
        print(m3)

    else:
        print("Mulitpication Not Possible !!")


while (True):
    print()
    print("* * * * * Matrix Operations * * * * *")
    print('''1) Addition of Two Matrices
2) Subraction of Two Matrices
3) Multiplication of Two Matrices
4) Transpose of a Matrix
5) Exit''')
    print("Enter a choice :")
    ch = int(input())

    if (ch == 1):
        print()
        rows = int(input("Enter number of Rows for Both Matrices :"))
        cols = int(input("Enter number of Columns for Both Matrices :"))
        print()
        m1 = [[0 for i in range(cols)] for i in range(rows)]
        m2 = [[0 for i in range(cols)] for i in range(rows)]
        print("Matrix 1")
        print("Enter Elements in Matrix 1 :")
        for i in range(rows):
            for j in range(cols):
                m1[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        print("Enter Elements in Matrix 2 :")
        for i in range(rows):
            for j in range(cols):
                m2[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        addition(m1, m2, rows, cols)

    elif ch == 2:
        print()
        rows = int(input("Enter number of Rows for Both Matrices :"))
        cols = int(input("Enter number of Columns for Both Matrices :"))
        print()
        m1 = [[0 for i in range(cols)] for i in range(rows)]
        m2 = [[0 for i in range(cols)] for i in range(rows)]
        print("Matrix 1")
        print("Enter Elements in Matrix 1 :")
        for i in range(rows):
            for j in range(cols):
                m1[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        print("Enter Elements in Matrix 2 :")
        for i in range(rows):
            for j in range(cols):
                m2[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        subraction(m1, m2, rows, cols)

    elif ch == 3:
        print()
        r1 = int(input("Enter number of Rows for Matrix 1 :"))
        c1 = int(input("Enter number of Columns for Matrix 1 :"))
        print()
        m1 = [[0 for i in range(c1)] for i in range(r1)]
        print("Matrix 1")
        print("Enter Elements in Matrix 1 :")
        for i in range(r1):
            for j in range(c1):
                m1[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        r2 = int(input("Enter number of Rows for Matrix 2 :"))
        c2 = int(input("Enter number of Columns for Matrix 2 :"))
        print()
        m2 = [[0 for i in range(c2)] for i in range(r2)]
        print("Matrix 2")
        print("Enter Elements in Matrix 2 :")
        for i in range(r2):
            for j in range(c2):
                m2[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        multiplication(m1, m2, r1, c1, r2, c2)

    elif ch == 4:
        print()
        rows = int(input("Enter number of Rows for Matrix :"))
        cols = int(input("Enter number of Columns for  Matrix :"))
        print()
        m1 = [[0 for i in range(cols)] for i in range(rows)]
        print("Matrix ")
        print("Enter Elements in Matrix  :")
        for i in range(rows):
            for j in range(cols):
                m1[i][j] = int(input(f"Enter value for element of Row:{i + 1} and Column:{j + 1} :"))

        transpose(m1, rows, cols)

    else:
        exit(0)
