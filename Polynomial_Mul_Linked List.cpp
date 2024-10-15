#include <iostream>
using namespace std;

class Node{
      public:
          int coff;
          int expo;
          Node *next;
          Node(int cof,int exp1){
             coff = cof;
             expo = exp1;
             next = nullptr;
          }
};

class List{
    Node *head = nullptr;
    public:
         void insert(int,int);
         void multiplication(List,List);
         void Add()
         void display();
};

void List::insert(int coff,int expo){
    Node *newnode = new Node(coff,expo);
    if(head==nullptr)
        head = newnode;
    else{
        Node *tem = head;
        while(tem->next!=nullptr){
            tem = tem->next;
        }
        tem->next = newnode;
    }
}

void List::display(){
    if(head==nullptr)
        cout<<"List Empty\n";
    else{
        Node *tem = head;
        while(tem->next!=nullptr){
            cout<<tem->coff<<"X^"<<tem->expo<<"+";
            tem = tem->next;
        }
        cout<<tem->coff<<"X^"<<tem->expo;
        cout<<"\n";
    }
}

void List::multiplication(List l1,List l2){
    Node *tem1 = l1.head;
    Node *tem2 = l2.head;
    while(tem1){
        Node *tem = tem2;
        while(tem){
            insert(tem1->coff*tem->coff,tem1->expo+tem->expo);
            tem = tem->next;
        }
        tem1 = tem1->next;
    }
}

int main(void){
    List l1,l2,l3;
    l1.insert(3,1);
    l1.insert(4,0);
    l2.insert(4,1);
    l2.insert(2,0);
    l3.multiplication(l1,l2);
    l3.display();
    return 0;
}

//Pending Addition work to be completed..