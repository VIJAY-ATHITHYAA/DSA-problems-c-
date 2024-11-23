#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *left,*right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
    Node()
    {
        left = right = nullptr;
    }
};

class BST{
 public:
 //AVL insertion operation
    Node *insertNode(Node *root,int data)
    {
            Node *newnode = new Node(data);
            if(!root)
                root = newnode;
            else if(data>root->data)
            {
                root->right = insertNode(root->right,data);
            }
            else if(data<=root->data)
            {
                root->left = insertNode(root->left,data);
            }
            else
                return root;
        int bf = Balancefun(root);
        if(bf>1 && newnode->data < root->left->data)
          return RR(root);//right - right condition
        if(bf<-1 && newnode->data > root->right->data)
          return LL(root);//Left - Left Condition
        if(bf>1 && newnode->data > root->left->data)
         {
             root->left = LL(root->left);
             return RR(root);
         }
         if(bf<-1 && newnode->data < root->right->data)
         {
             root->right = RR(root->right);
             return LL(root);
         }
         return root;
    }
//to check weather sub trees are balanced
   int Balancefun(Node *root)
     {
         if(!root)
            return -1;
         else 
            return (height(root->left)-height(root->right));
     }
//To Get the height of the Tree..
     int height(Node *root)
     {
         if(!root)
            return -1;
        else
         return max(height(root->left),height(root->right))+1;
     }
//Left Left Condition 
     Node *LL(Node *root)
     {
         Node *y = root->right;
         Node *tem = y->left;
         y->left = root;
         root->right = tem;
         return y;
     }
//Right - Right Condition
     Node *RR(Node *root)
     {
         Node *y = root->left;
         Node *tem = y->right;
         y->right = root;
         root->left = tem;
         return y;
     }
     
     void Inorder(Node *root)
     {
         if(!root)
          return;
         Inorder(root->left);
         cout<<root->data<<" ";
         Inorder(root->right);
     }
};

int main() {
    Node *root = nullptr;
    BST t;
    root = t.insertNode(root,10);
    root = t.insertNode(root,25);
    root = t.insertNode(root,30);
    root = t.insertNode(root,12);
    root = t.insertNode(root,16);
    t.Inorder(root);
    int h = t.height(root);
    int b = t.Balancefun(root);
    cout<<h<<" "<<b;
    return 0;
}