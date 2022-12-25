class string_operations:
    def longest_word(self):
        sentence=str(input("Enter a string :"))
        sentence=sentence+" "
        word=""
        words=[]
        for i in sentence:
            if i==" ":
                words.append(word)
                word=""
            else:
                word+=i

        max_len=0;
        max_word=""
        for word in words:
            if len(word)>max_len:
                max_len=len(word)
                max_word=word

        print("Word with the Longest Length in string : "+max_word)

    def freq_character(self):
        s=str(input("Enter a string :"))
        ch=str(input("Enter the character whose occurence is to be found :"))
        count=0
        for i in s:
            if i==ch:
                count+=1
        print("Occurence of character in string is :"+str(count))

    def palindrome(self):
        s=str(input("Enter a string :"))
        rev=""
        for i in s:
            rev=i+rev

        if s==rev:
            print("String is Palindrome")
        else:
            print("String is Not Palindrome")

    def sstring_occur(self):
        s=str(input("Enter a string :"))
        ss=str(input("Enter a substring :"))

        print("First Occurence of substring in string :")
        print(s.find(ss))

    def eachword_occur(self):
        sentence = str(input("Enter a string :"))
        sentence = sentence + " "
        word = ""
        words = []
        for i in sentence:
            if i == " ":
                words.append(word)
                word = ""
            else:
                word += i

        occur={}
        for i in range(0,len(words)):
            if words[i] in occur.keys():
                occur[words[i]]+=1
            else:
                occur[words[i]]=1

        print("Occurences of each word in the string :"+str(occur))


s1=string_operations();

while(True):
    print()
    print("* * * * * STRING OPERATIONS * * * * *")
    print('''1) Longest Word in String
2) Frequency of Particular Character in String
3) Check whether String is Palindrome or Not
4) First Occurence of Substring in String
5) Frequency of Each Word in String
6) Exit''')
    print()

    ch=int(input("Enter your choice :"))

    if(ch==1):
        s1.longest_word()

    elif ch==2:
        s1.freq_character()

    elif ch==3:
        s1.palindrome()

    elif ch==4:
        s1.sstring_occur()

    elif ch==5:
        s1.eachword_occur()

    elif ch==6:
        exit(0)





