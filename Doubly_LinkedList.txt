#include <iostream>
using namespace std;
//Doubly linked list
class Node{
    public:
       int data;
       Node *next;
       Node *prev;
       Node(int val){
           data = val;
           next = nullptr;
           prev = nullptr;
       }
};

class DList{
    Node *head = nullptr;
    public:
    int count = 0;
        void insertBegin(int);
        void insertEnd(int);
        void insertPos(int,int);
        int deleteBegin();
        int deleteEnd();
        int deletePos(int);
        int Search(int);
        void display();
};

void DList::insertBegin(int val){
    Node *newnode = new Node(val);
    if(head==nullptr){
        head = newnode;
        count++;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
         count++;
    }
}

void DList::insertEnd(int data){
     Node *newnode = new Node(data);
    if(head==nullptr){
        head = newnode;
        count++;
    }
    else{
        Node *tem = head;
        while(tem->next!=nullptr){
            tem = tem->next;
        }
        tem->next = newnode;
        newnode->prev = tem;
        count++;
    }
}

void DList::insertPos(int data,int pos){
      Node *newnode = new Node(data);
      int i=0;
    if(head==nullptr){
        head = newnode;
        count++;}
    else if(pos==1){
        insertBegin(data);
    }
    else if(pos==count+1){
        insertEnd(data);
    }
    else{
        Node *tem = head;
        while(tem&&i<pos-2){
            tem = tem->next;
            i++;
        }
       newnode->next = tem->next;
       tem->next->prev = newnode;
       tem->next = newnode;
       newnode->prev = tem;
       count++;
   }
}

int DList::deleteBegin(){
    if(head == nullptr)
       return -1;
    else{
        int val = head->data;
        head = head->next;
        count--;
        return val;
    }
}

int DList::deleteEnd(){
     Node *tem1 = head->next;
     Node *tem2 = head;
     if(head == nullptr)
       return -1;
     else{
        while(tem1->next!=nullptr){
            tem1 = tem1->next;
            tem2 = tem2->next;
        }
    }
        int val = tem1->data;
        tem2->next = nullptr;
        count--;
    return val;
}

int DList::deletePos(int pos){
    Node *tem2 = head->next;
    Node *tem1 = head;
    int val=0;
    if(head == nullptr)
       return -1;
    else if(pos == 1){
        val = deleteBegin();
        return val;
    }
    else if(pos == count){
        val = deleteEnd();
        return val;
    }
     else{
         int i=0;
         while(tem1&&tem2&&i<pos-2){
             tem1 = tem1->next;
             tem2 = tem2->next;
             i++;
         }
         val = tem1->next->data;
         tem1->next = tem2->next;
         tem2->next->prev = tem1;
     return val;
     }
}

void DList::display(){
    Node *tem = head;
    if(tem == nullptr)
       cout<<"List Empty!!";
    else{
        while(tem->next!=nullptr){
            cout<<tem->data<<" ";
            tem = tem->next;
        }
        cout<<tem->data;
    }
}

int main() {
    DList l1;
    return 0;
}