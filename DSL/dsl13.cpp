#include<iostream>
using namespace std;

class deque
{
    public:

    int start=-1;
    int end=-1;
    int a[100];
    int size=100;

    void enqueue_start(int x)
    {
        if(start==-1||start==0)
        {
            cout<<endl;
            cout<<"Deque Overflow !!"<<endl;
        }
        else
        {
            a[--start]=x;
            cout<<endl;
            cout<<"Element added from Front!!"<<endl;
        }
    }

    void enqueue_end(int x)
    {
        if(end==size-1)
        {
            cout<<endl;
            cout<<"Deque Overflow!!"<<endl;
        }
        else if(start==-1)
        {
            start=end=0;
            a[end]=x;
            cout<<endl;
            cout<<"Element added from Rear!!"<<endl;
        }
        else
        {
            a[++end]=x;
            cout<<endl;
            cout<<"Element added from Rear!!"<<endl;
        }  
    }

    void dequeue_start()
    {
        if(start==-1||start==end+1)
        {
            cout<<endl;
            cout<<"Deque Underflow!!"<<endl;
        }
        else
        {
            start++;
            cout<<endl;
            cout<<"Element deleted from Front!!"<<endl;
        }
    }

    void dequeue_end()
    {
        if(start==-1||start==end+1)
        {
            cout<<endl;
            cout<<"Deque Underflow !!"<<endl;
        }
        else
        {
            end--;
            cout<<endl;
            cout<<"Element deleted from Rear!!"<<endl;
        }
    }

    void display()
    {
        if(start<=end)
        {
            cout<<endl;
            cout<<"Deque is as follows :"<<endl;
            for(int i=start;i<=end;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Empty Deque !!"<<endl;
        }
    }
};

int main()
{
    int ch=0;

    deque d;

    do
    {
        cout<<endl;
        cout<<"* * * * * Deque System * * * * *"<<endl;
        cout<<"1) Enqueue Front"<<endl;
        cout<<"2) Enqueue Rear"<<endl;
        cout<<"3) Dequeue Front"<<endl;
        cout<<"4) Dequeue Rear"<<endl;
        cout<<"5) Dislay Deque"<<endl;
        cout<<"6) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            int x;
            cout<<endl;
            cout<<"Enter element to be entered from Front :"<<endl;
            cin>>x;
            d.enqueue_start(x);
            break;

            case 2:
            cout<<endl;
            cout<<"Enter element to be entered from Rear :"<<endl;
            cin>>x;
            d.enqueue_end(x);
            break;

            case 3:
            d.dequeue_start();
            break;

            case 4:
            d.dequeue_end();
            break;

            case 5:
            d.display();
            break;

            case 6:
            exit(0);
            break;

            default:
            cout<<endl;
            cout<<"Invalid Choice !!"<<endl;
            break;
        }
    } while (ch!=6);
    return 0;
}
