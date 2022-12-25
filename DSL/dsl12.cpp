#include<iostream>
using namespace std;

template<typename T>
class item
{
    public :

    T data;
    int priority;

    item()
    {
        priority=0;
    }

    item(T d,int p)
    {
        data=d;
        priority=p;
    }

    bool operator <=(item<int> i2)
    {
        if(priority<=i2.priority)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class priorityQueue
{
    public:

    int start;
    int end;
    int size=100;
    item<int> arr[100];

    priorityQueue()
    {
        start=-1;
        end=-1;
    }

    void enqueue(item<int> &i)
    {
        if(end==size-1)
        {
            cout<<endl;
            cout<<"Priority Queue Overflow !!"<<endl;
        }
        else if(start==-1)
        {
            start=end=0;
            arr[0]=i;
        }
        else
        {
            int j=end;
            while(arr[j]<=i && j>=start)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=i;
            end++;
        }
    }

    void dequeue()
    {
        if(start==-1 || start==end+1)
        {
            cout<<endl;
            cout<<"Priority Queue Underflow !!"<<endl;
        }
        else
        {
            start++;
        }
    }

    void display()
    {
        if(start<=end)
        {
            cout<<endl;
            cout<<"Priority Queue is as follows :"<<endl;
            for(int i=start;i<=end;i++)
            {
                cout<<"Priority :"<<arr[i].priority<<"\t"<<"Data: "<<arr[i].data<<endl;
            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"Empty Priority Queue!!"<<endl;
        }
    }
};

int main()
{
    int ch=0;

    priorityQueue pq;

    do
    {
        cout<<endl;
        cout<<"* * * * * Priority Queue System * * * * *"<<endl;
        cout<<"1) Add Field"<<endl;
        cout<<"2) Delete Field"<<endl;
        cout<<"3) Display Fields"<<endl;
        cout<<"4) Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                    int d,p;
                    cout<<endl;
                    cout<<"Enter Data :"<<endl;
                    cin>>d;
                    cout<<"Enter Priority :"<<endl;
                    cin>>p;
                    item<int> i1(d,p);
                    pq.enqueue(i1);
                    cout<<endl;
                    cout<<"Field Added in Priority Queue!!"<<endl;
                    break;
            }

            case 2:
            {
                    pq.dequeue();
                    cout<<endl;
                    cout<<"Field Deleted in Priority Queue!!"<<endl;
                    break;
            }

            case 3:
            {
                pq.display();
                break;
            }

            case 4:
            {
                exit(0);
                break;
            }

            default:
            {
                cout<<endl;
                cout<<"Invalid Choice!!"<<endl;
                break;
            }
        }
    } while (ch!=4);

    return 0;

}