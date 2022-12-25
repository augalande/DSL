#include<iostream>
using namespace std;

class node
{
    public:
    node *prev;
    node *next;
    int seat;
    int status;
    string id;

    node()
    {
        prev=NULL;
        next=NULL;
        seat=0;
        status=0;
        id="";
    }
};

class cinemax
{
    public:
    node *head,*tail,*temp;

    void create_list();
    void avail();
    void book();
    void cancel();
};

void cinemax::create_list()
{
    int i=1;
    temp=new node();
    head=tail=temp;
    temp->seat=1;
    temp->status=0;
    temp->id="null";

    for(int i=2;i<=70;i++)
    {
        node *p=new node();
        p->seat=i;
        p->status=0;
        p->id="null";

        tail->next=p;
        p->prev=tail;
        tail=p;
        tail->next=head;
        head->prev=tail;
    }
}

void cinemax::avail()
{
    cout<<endl;
    int c=1;
    int r=1;
    temp=head;
    while(temp->next!=head)
    {
        if(temp->seat/10==0)
        {
            cout<<"S0"<<temp->seat<<": ";
        }
        else
        {
            cout<<"S"<<temp->seat<<": ";
        }

        if(temp->status==0)
        {
            cout<<"|__|\t";
        }
        else
        {
            cout<<"|_B_|\t";
        }
        
        if(c==7)
        {
            cout<<endl;
            c=1;
            r++;
            temp=temp->next;
            continue;
        }
        c++;
        temp=temp->next;
    }
    cout<<"S"<<temp->seat<<": ";
    if(temp->status==0)
        {
            cout<<"|__|\t";
        }
        else
        {
            cout<<"|_B_|\t";
        }
        cout<<endl;
}

void cinemax::book()
{
    cout<<endl;
    int n;
    string s;
    cout<<"Enter Seat Number to be Booked :"<<endl;
    cin>>n;
    cout<<"Enter your Name(ID) :"<<endl;
    cin>>s;
    temp=head;
    while(temp->seat!=n)
    {
        temp=temp->next;
    }

    if(temp->status==0)
    {
    temp->status=1;
    temp->id=s;
    cout<<endl;
    cout<<"Your Seat Number:"<<temp->seat<<" booked sucessfully!!"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Seat Number:"<<temp->seat<<" is already booked!!"<<endl;
    }
}

void cinemax::cancel()
{
    cout<<endl;
    int n;
    string s;
    cout<<"Enter Seat Number to be Canceled :"<<endl;
    cin>>n;
    cout<<"Enter your Name(ID) :"<<endl;
    cin>>s;
    temp=head;
    while(temp->seat!=n)
    {
        temp=temp->next;
    }
    if(temp->status==1)
    {
        if(temp->id==s)
        {
            cout<<endl;
            cout<<"Seat Number:"<<temp->seat<<" canceled sucessfully!!"<<endl;
            temp->status=0;
        }
        else
        {
            cout<<endl;
            cout<<"Seat Number:"<<temp->seat<<" cannot be canceled!!"<<endl;
            cout<<"Wrong Name(ID) entered!!"<<endl;
        }
    }
    else
    {
        cout<<endl;
        cout<<"Seat Number:"<<temp->seat<<" is not yet booked!!"<<endl;
        cout<<"Seat Cancellation Failed!!"<<endl;
    }
}

int main()
{
    cinemax obj;
    obj.create_list();
    int ch=0;
    do
    {
        cout<<endl;
        cout<<"* * * * * TICKET BOOKING SYSTEM FOR CINEMAX * * * * *"<<endl;
        cout<<"1) Available Seats"<<endl;
        cout<<"2) Book Seat"<<endl;
        cout<<"3) Cancel Seat"<<endl;;
        cout<<"4) Exit"<<endl;
        cout<<"Enter your choice :"<<endl;
        cin>>ch;

        switch(ch)
        {
            case 1: obj.avail();
                    break;

            case 2:obj.book();
            break;

            case 3:obj.cancel();
            break;

            case 4:exit(0);

            default:cout<<endl;
                    cout<<"Invalid Choice!!"<<endl;
            break;
        }
    } while (ch!=4);
    return 0;
}