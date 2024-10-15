#include <iostream>
using namespace std;

class stack{
        
        int size;
        public:
            int top;
            int arr[100];
           stack(int s)
           {
              size = s;
           }
           void insert(int);
           int rem();
           void display();
           int search(int);
           int peek();
};

 void stack::insert(int ele)
{
        if(top>=size)
              cout<<"The stack is full\n\n";
        else{
              arr[top]=ele;
              top++;}
}
 void stack::display(){
    if(top<=0){
      cout<<"Stack is empty";
      return;
    }
    else{
        for(int i=0;i<top;i++)
            cout<<arr[i]<<" ";
    }
}
int stack::rem() {
    if (top <= 0) { 
        cout << "Stack is empty\n";
        return -1;  } 
    else {
        top--;
        return arr[top];
    }
}

int stack::search(int ele){
    if (top <= 0) { 
        cout << "Stack is empty\n";
        return -1;
    }  
    else{
        for(int i=0;i<top;i++){
            if(arr[i]==ele)
                  return i+1;
        }
        return -1;
    }
    
}

int stack::peek(){
    if (top <= 0) 
         return -1;
     return arr[top-1]; 
}

int main(void)
{
    int size;
    int opt,mem,ele;
    cout<<"Enter the size: ";
    cin>>size;
    stack s(size);
    
    do{
        cout<<"\n1.inserting element\n"<<"2.traversal\n"<<"3.remove a element\n"<<"4.searching\n"<<"5.peek\n"<<"6.Exit\n";
        cout<<"\vEnter the option: \n";
        cin>>opt;
        switch(opt)
        {
            case 1:
                cout<<"Enter the element to insert: ";
                cin>>mem;
                s.insert(mem);
                break;
            case 2:
                cout<<"Here is the list of stack element:\n";
                s.display();
                break;
            case 3:
                cout<<"Removed element:";
                cout<<s.rem();
                break;
            case 4:
                cout<<"Enter the element to search: ";
                cin>>ele;
                mem = s.search(ele);
                if(mem==-1)
                  cout<<"Element not found";
                else
                  cout<<"Element found at "<<mem<<endl;
                break;
            case 5:
                ele = s.peek();
                if(ele!=-1)
                   cout<<"Element at Top: "<<ele;
                else
                  cout << "Stack is empty\n";
                break;
        }
     }while(opt!=6); 
     return 0;
}
