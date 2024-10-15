//queue using two stacks
#include <iostream>
using namespace std;

class Stack{
    int size,top1,top2,count = 0;
    int s1[100];
    int s2[100];
    public:
    Stack(int s){
        size = s;
        s1[size];
        s2[size];
        top1=0;
        top2=0;
    }
       void enqueue(int);
       int dequeue();
       void display();
};

void Stack::enqueue(int data){
    if(top1>=size)
      cout<<"Queue full!!";
    else{
        s1[top1++] = data;
        count++;
    }
}

int Stack::dequeue(){
   int val;
   if(top1==0&&top2==0)
      return -1;
   else{
       for(int i=0;i<count;i++){
           s2[top2++] = s1[--top1];
       }
      val = s2[--top2];
      count--;
      for(int i=0;i<count;i++){
          s1[top1++] = s2[--top2]; 
      }
   }
   return val;
}

void Stack::display(){
    if(count==0){
      cout<<"Queue Empty";
      return;}
    for(int i=0;i<top1;i++){
        cout<<s1[i]<<" ";
    }
}
int main(){
    int opt,val,size;
    cout<<"\nEnter the size: ";
    cin>>size;
    Stack s(size);
    cout<<"1.Enqueue\n2.dequeue\n3.display\n4.exit\n";
    do{
          cout<<"\nEnter the Option?";
          cin>>opt;
          switch(opt){
              case 1:
                 cout<<"\nEnter the Element to insert: ";
                 cin>>val;
                 s.enqueue(val);
                 break;
              case 2:
                 val = s.dequeue();
                 if(val!=-1)
                    cout<<"\nDeleted element :"<<val; 
                 else
                    cout<<"Queue empty";
                 break;
              case 3:
                 s.display();
                 break;
          }
    }while(opt!=4);
    return 0;
}`