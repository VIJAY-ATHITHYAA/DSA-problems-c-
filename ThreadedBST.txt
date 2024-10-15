#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    int lpt,rpt;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
        lpt = rpt = 0;
    }
};

class Tree{
 public:
    Node *root;
    Tree()
    {
        root = nullptr;      
    }
   void insert(int key)
   {
       Node *newnode = new Node(key);
       if(!root)
       {
           root = newnode;
           return;
       }
       else
       {
           Node *curr = root;
           Node *paren = nullptr;
   //find the position to insert;
           while(curr)
           {
               paren = curr;
               if(key<curr->data)
               {
                   if(curr->lpt == 1)
                      curr = curr->left;
                   else
                      break;
               }
               else
               {
                   if(curr->rpt == 1)
                      curr = curr->right;
                   else
                      break;
               }
           }
         if(key<paren->data)
         {
             newnode->left = paren->left;
             newnode->right = paren;
             paren->left = newnode;
             paren->lpt = 1;
         }
         if(key>paren->data)
         {
             newnode->right = paren->right;
             newnode->left = paren;
             paren->right = newnode;
             paren->rpt = 1;
         }
      }
   }
   
   Node *LeftMost(Node *root)
   {
       if(!root)
         return nullptr;
       else{
           while(root->lpt!=0)
           {
               root = root->left;
           }
       }
       return root;
   }
int Count(Node *root){
       int count =0;
       if(!root)
          return 0;
      else
       return 1+Count(root->right)+Count(root->left);
   }
   
   void inorderFor()
   {
       if(!root)
         return;
       else
       {
           Node *curr = LeftMost(root);
           while(curr)
           {
               cout<<curr->data<<" ";
               if(curr->rpt==0)
                 curr = curr->right;
               else
                 curr = LeftMost(curr->right);
           }
       }
   }
};

int main()
{
    Tree t;
    t.insert(70);
    t.insert(65);
    t.insert(75);
    t.insert(60);
    t.insert(68);
    t.insert(73);
    t.insert(90);
    t.inorderFor();
    return 0;
}