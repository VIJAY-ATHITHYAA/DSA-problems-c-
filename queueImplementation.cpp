#include <iostream>
using namespace std;

class queue{
    int size;
    int a[100];
    int front=0,rear=0;
    public:
       queue(int x){
           size = x;
       }
       void insert(int);
       void display();
       int remov();
       int peek();
};


void queue::insert(int ele){
    if(rear>=size)
      cout<<"Queue is Full\n";
    else{
         a[rear++] = ele;
    }
}

int queue::remov(){
    int val;
    if(rear<=0)
      cout<<"Queue is empty";
    else{
       val = a[front++];
       }
       return val;
}

void queue::display(){
    if(rear<=0)
      cout<<"Queue is empty";
    else{
        for(int i = front;i < rear;i++)
           cout<<a[i]<<" ";
        cout<<"\n";
    }
}

int queue::peek(){
     int val;
    if(rear<=0)
      cout<<"Queue is empty";
    else
         val = a[front];
    return val;
}


int main()
{
    int val;
    int size;
    cout<<"Enter the size :";
    cin>>size;
    queue q(size);
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.remov();
    q.remov();
    val = q.peek();
    cout<<"Element at Peek "<<val<<"\n";
    q.display();
    return 0;
}