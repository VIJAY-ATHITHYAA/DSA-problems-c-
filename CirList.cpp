#include <iostream>
using namespace std;
//circular Queue conversion..
class Node{
  public:
    int data;
    Node *next;
    Node(int val){
        data = val;
    }
    Node(){
    }
};
class List{
    private:
      Node *tail = nullptr;
      //insert into begin of node
     public:
      void insertBegin(int val){
          Node *newnode = new Node(val);
          if(tail == nullptr)
          { 
             tail = newnode;
             newnode->next = newnode;
          }
          else{
              newnode->next = tail->next; 
              tail->next = newnode;
          }
      }
      void insertEnd(int val){
          Node *newnode = new Node(val);
          if(tail == nullptr)
          { 
             tail = newnode;
             newnode->next = newnode;
          }
          else{
              newnode->next = tail->next;
              tail->next = newnode;
              tail = newnode;
              }
      }
      void Display(){
          if(tail==nullptr)
            {
                cout<<"List Empty !!";
                return;
            }
        else
         {
             cout<<"\nElements Are!!\n";
             Node *tem = tail->next;
            do
             {
                 cout<<tem->data<<" ";
                 tem = tem->next;
             } while(tem!=tail->next);
         }
     }
};

int main() {
   List l;
   l.insertEnd(10);
    l.Display();
    return 0;
}