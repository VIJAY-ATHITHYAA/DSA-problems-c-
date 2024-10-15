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
         void addition(List,List);
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

void List::addition(List l11,List l22){
    Node *tem1 = l11.head;
    Node *tem2 = l22.head;
    while(tem1&&tem2){
      if(tem1->expo==tem2->expo){
            insert(tem1->coff+tem2->coff,tem1->expo);
            tem1 = tem1->next;
            tem2 = tem2->next;
        }
      else if(tem1->expo>tem2->expo){
            insert(tem1->coff,tem1->expo);
            tem1 = tem1->next;
      }
      else if(tem1->expo<tem2->expo){
            insert(tem2->coff,tem2->expo);
            tem2 = tem2->next;
         }
    }
    while(tem1!=nullptr){
        insert(tem1->coff,tem1->expo);
        tem1 = tem1->next;
    }
    while(tem2!=nullptr){
        insert(tem2->coff,tem2->expo);
        tem2 = tem2->next;
    }
}

int main(void){
    List l1,l2,l3;
    l1.insert(3,2);
    l1.insert(4,1);
    l1.insert(5,0);
    
    l2.insert(4,4);
    l2.insert(6,2);
    l2.insert(4,3);
    l1.display();
    l2.display();
    cout<<"Resultant equation\n";
    l3.addition(l1,l2);
    l3.display();
    return 0;
}