#include<iostream>
using namespace std;

class stack
{
    public:

    int size=100;
    int top=-1;
    char a[100];

    bool isFull()
    {
        if(top==size-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(char x)
    {
        if(isFull())
        {
            cout<<endl;
            cout<<"Stack Overflow!!"<<endl;
        }
        else
        {
            a[++top]=x;
        }
    }

    char pop()
    {
        if(isEmpty())
        {
            cout<<endl;
            cout<<"Stack Underflow!!"<<endl;
            return '0';
        }
        else
        {
            return a[top--];
        }
    }

    char peek()
    {
        if(isEmpty())
        {
            cout<<endl;
            cout<<"Stack Underflow"<<endl;
            return '0';
        }
        else
        {
            return a[top];
        }
    }

    void display()
    {
        for(int i=0;i<=size;i++)
        {
            cout<<a[i]<<" ";
        }
    }
};

int main()
{
    stack stk;
    string s;
    bool isBalanced=1;

    cout<<endl;
    cout<<"* * * * * Parenthesis Checker * * * * *"<<endl;
    cout<<"Enter the string to be checked :"<<endl;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stk.push(s[i]);
        }

        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(stk.isEmpty())
            {
                isBalanced=0;
                cout<<endl;
                cout<<s<<" is not balanced!!"<<endl;
                return 0;
            }

            else
            {
                char last_bracket=stk.peek();
                if(s[i]==')' && last_bracket=='(')
                {
                    char c= stk.pop();
                }
                else if(s[i]=='}' && last_bracket=='{')
                {
                    char c= stk.pop();
                }
                else if(s[i]==']' && last_bracket=='[')
                {
                    char c= stk.pop();
                }
            }
        }
    }

    if(stk.isEmpty())
    {
        isBalanced=1;
    }
    else
    {
        isBalanced=0;
    }

    if(isBalanced)
    {
        cout<<endl;
        cout<<s<<" is balanced!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<s<<" is not balanced!!"<<endl;
    }
    return 0;
}