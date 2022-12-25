#include<iostream>
#include<iomanip>
using namespace std;

class node
{
    public:
    node* next;
    int start;
    int end;
    int min;
    int max;
    int status;

    node()
    {
        next=NULL;
        start=0;
        end=0;
        min=0;
        max=0;
        status=0;
    }
};

class app_sys
{
    public:
    int size;
    node *head;
    node *tail;
    node *temp;

    void create_appshed();
    void display_appshed();
    void book();
    void cancel();
    void sort();
};

void app_sys::create_appshed()
{
    cout<<endl;
    cout<<"Enter Number of Slots to be created :"<<endl;
    cin>>size;

    cout<<endl;

    temp=new node();
    head=tail=temp;
    cout<<"SLOT NUMBER 1"<<endl;
    cout<<"Enter Start Time :"<<endl;
    cin>>temp->start;
    cout<<"Enter End Time :"<<endl;
    cin>>temp->end;
    cout<<"Enter Maximum Duration :"<<endl;
    cin>>temp->max;
    cout<<"Enter Minimum Duration :"<<endl;
    cin>>temp->min;
    temp->status=0;

    for(int i=2;i<=size;i++)
    {
        cout<<endl;

        node *p=new node();
        cout<<"SLOT NUMBER "<<i<<endl;
        cout<<"Enter Start Time :"<<endl;
        cin>>p->start;
        cout<<"Enter End Time :"<<endl;
        cin>>p->end;
        cout<<"Enter Maximum Duration :"<<endl;
        cin>>p->max;
        cout<<"Enter Minimum Duration :"<<endl;
        cin>>p->min;
        p->status=0;
        p->next=NULL;

        tail->next=p;
        tail=p;
    }
}

void app_sys::display_appshed()
{
    cout<<endl;
    cout<<"Sr.No."<<setw(15)<<"StartTime"<<setw(15)<<"EndTime"<<setw(15)<<"MaxDuration"<<setw(15)<<"MinDuration"<<setw(15)<<"Status"<<endl;
    
    int i=1;
    temp=head;
    while(temp!=NULL)
    {
        cout<<i<<setw(15)<<temp->start<<setw(15)<<temp->end<<setw(15)<<temp->max<<setw(15)<<temp->min<<setw(20);
        if(temp->status==0)
        {
            cout<<"--Free--"<<endl;
        }
        else
        {
            cout<<"--Booked--"<<endl;
        }
        i++;
        temp=temp->next;
    }
}

void app_sys::book()
{
    cout<<endl;
    cout<<"Enter Time to book a slot :"<<endl;
    int time;
    cin>>time;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->status==0)
        {
            if(temp->start==time)
            {
                cout<<endl;
                cout<<"Appointment Slot booked at "<<time<<"!!"<<endl;
                cout<<"Please be on time!!"<<endl; 
                temp->status=1;
                return;
            }
        }
        temp=temp->next;
    }
    cout<<endl;
    cout<<"No Available Slot at Time :"<<time<<endl;
}

void app_sys::cancel()
{
    cout<<endl;
    cout<<"Enter Time to cancel a slot :"<<endl;
    int time;
    cin>>time;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->status==1)
        {
            if(temp->start==time)
            {
                cout<<endl;
                cout<<"Appointment Slot cancelled at "<<time<<"!!"<<endl;
                temp->status=0;
                return;
            }
        }
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Slot Cancellation Failed!!"<<endl;
}

void app_sys::sort()
{
    for(int i=1;i<=size;i++)
    {
        temp=head;
        while(temp->next!=NULL)      // because here the second last node will be compared with the last node hence run while loop till the second last node only
        {
            if(temp->start > temp->next->start)
            {
            int val;

            val=temp->start;
            temp->start = temp->next->start;
            temp->next->start = val;

            val=temp->end;
            temp->end = temp->next->end;
            temp->next->end = val;

            val=temp->max;
            temp->max = temp->next->max;
            temp->next->max = val;

            val=temp->min;
            temp->min = temp->next->min;
            temp->next->min = val;

            val=temp->status;
            temp->status = temp->next->status;
            temp->next->status = val;
            }

            temp=temp->next;
        }
    }
    cout<<endl;
    cout<<"Appointment Slots Sorted sucessfully!!"<<endl;
}

int main()
{
    app_sys a;
    int ch=0;

    do
    {
        cout<<endl;
        cout<<"* * * * * Appointment System * * * * *"<<endl;
        cout<<"1) Create Appointment Schedule"<<endl;
        cout<<"2) Display Appointment Schedule"<<endl;
        cout<<"3) Book Appointment Slot"<<endl;
        cout<<"4) Cancel Appointment Slot"<<endl;
        cout<<"5) Sort Appointment Slots"<<endl;
        cout<<"6) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: a.create_appshed();
                    break;

            case 2: a.display_appshed();
                    break;

            case 3: a.book();
                    break;

            case 4: a.cancel();
                    break;

            case 5: a.sort();
                    break;

            case 6:exit(0);

            default:   cout<<endl;
                    cout<<"Invalid Choice!!"<<endl;
                    break;                                    
        }
    } while (ch!=6);
    return 0;
}