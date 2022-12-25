#include<iostream>
using namespace std;

class queue
{
    public:

    int size=100;
    int a[100];
    int start=-1;
    int end=-1;

    void enqueue(int x)
    {
        if(end==size-1)
        {
            cout<<endl;
            cout<<"Queue Overflow!!"<<endl;
        }
        else if(start==-1)
        {
            start=end=0;
            a[end]=x;
        }
        else
        {
            a[++end]=x;
            cout<<endl;
            cout<<"Job "<<x<<" added!!"<<endl;
        }
    }

    void dequeue()
    {
        if(start==-1 || start==end+1)
        {
            cout<<endl;
            cout<<"Queue Underflow !!"<<endl;
        }
        else
        {
            start++;
            cout<<endl;
            cout<<"Job Deleted!!"<<endl;
        }
    }

    void display()
    {
        if(start<=end)
        {
            cout<<endl;
            cout<<"Jobs in Queue :"<<endl;
            for(int i=start;i<=end;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Empty Queue !!"<<endl;
        }

    }
};

int main()
{
    int ch=0;

    queue q;

    do
    {
        cout<<endl;
        cout<<"* * * * * JOB QUEUE SYSTEM * * * * *"<<endl;
        cout<<"1) Add Job"<<endl;
        cout<<"2) Delete Job"<<endl;
        cout<<"3) Display Jobs"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: 
            cout<<endl;
            cout<<"Enter a job you want to add in the Queue :"<<endl;
            int x;
            cin>>x;
            q.enqueue(x);
            break;

            case 2:
            q.dequeue(); 
            break;

            case 3: 
            q.display();
            break;

            case 4: exit(0);
            break;

            default:cout<<endl;
            cout<<"Invalid Choice !!"<<endl;
            break;
        }
    } while (ch!=4);
    return 0;
}