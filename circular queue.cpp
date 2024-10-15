// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
//circular queue 
class queue{
    int *arr;
    int size;
    int rear=0,front=0;
    public:
       queue(int s)
       {
           size = s;
           arr = new int[s];
       }
       void insert(int);
       int remov();
       void display();
       int count();
};

void queue::insert(int ele){
    if((rear+1)%size==front)
      cout<<"Queue Full"<<"\n";
    else{
        arr[rear] = ele;
        rear = (rear+1)%size;
    }
}

void queue::display()
{    int i = front;
    if(rear == front)
       cout<<"Queue Empty";
    else{
        cout<<"Elements are:\n";
        while(i!=rear)
        {
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
    }
}

int queue::remov(){
    if(rear==front)
    {
        return -1;
    }
    int val = arr[front];
    front = (front+1)%size;
    return val;
}

int queue::count(){
    int c=0;
    int i=front;
    if(front==rear)
       return -1;
    while(i!=rear)
    {
        c++;
        i = (i+1)%size;
    }
    return c;
}

int main() {
    int size,opt,val;
    
    cout<<"Enter the size: ";
    cin>>size;
    queue q(size+1);
    cout<<"1.Insert\n2.delete\n3.display\n4.Count\n5.exit";
    do{
       cout<<"\nEnter the option: ";
       cin>>opt;
     if(opt<=4)
      {
          cout<<"\n";
          switch(opt){
           case 1:
                cout<<"Enter the element to insert: ";
                cin>>val;
                q.insert(val);
                break;
            case 2:
                val = q.remov();
                if(val!=-1)
                   cout<<"Removed Element :"<<val;
                else
                   cout<<"queue Empty";
                break;
            case 3:
                q.display();
                break;
            case 4:
                val = q.count();
                if(val!=-1)
                   cout<<"Queue Count = "<<val;
                else
                   cout<<"Queue empty";
                break;
                  }
        }
    else
      cout<<"\nEnter the opt 1-4\n";
    }while(opt!=5);
}