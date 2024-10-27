#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Tree{
    public:
    Node *root = nullptr;
    Node *insert(Node *root,int data)
    {
        Node *newnode = new Node(data);
        if(!root)
         {
             root = newnode;
             return root;
         }
        else{
            if(data<root->data)
              root->left = insert(root->left,data);
            if(data>root->data)
              root->right = insert(root->right,data);
        }
      return root;
    }
void Inorder(Node *root)
       {
           if(!root)
               return;
           Inorder(root->left);
           cout<<root->data<<" ";
           Inorder(root->right);
       }
int Count(Node *root){
       int count =0;
       if(!root)
          return 0;
      else
       return 1+Count(root->right)+Count(root->left);
   }
   void LevelOrder(Node *root)
      {
        if(!root)
            return;
        else
        {
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node *node = q.front();
                cout<<node->data<<" ";
                q.pop();
                if(node->left)
                  q.push(node->left);
                if(node->right)
                  q.push(node->right);
            }	
        }
      } //finds the Minimum of right Subtree
        Node *FindMin(Node *root)
       {
           Node *tem;
           if(!root)
              return nullptr;
           else{
               if(root->right)
               {
                   tem = root->right;
                   while(tem->left!=nullptr){
                       tem = tem->left;
                   }
                   return tem;
               }
               else
                  return nullptr;
           }
       }//Delete a Specific Element...
       Node *Delete(Node *root,int data){
           if(!root)
               return nullptr;
           if(root->data==data){
               if(!root->left)
                   return root->right;
               if(!root->right)
                   return root->left;
               Node *tem = FindMin(root);
               root->data = tem->data;
               root->right = Delete(root->right,tem->data);
               }
           else{
               if(data>root->data)
                  root->right = Delete(root->right,data);
               else
                  root->left = Delete(root->left,data);
           }
           return root;
       }
       int Minimum(Node *root){
           if(!root)
              return -1;
           else{
               if(root->left == nullptr)
                 return root->data; 
               Node *tem = root->left;
               while(tem->left!=nullptr){
                   tem = tem->left;
               }
               return tem->data;
           }
       }
};

int main()
{
    Tree t;
    Node *root = nullptr;
    root = t.insert(root,10);
    root = t.insert(root,20);
    root = t.insert(root,5);
    t.Display(root);
    t.LevelOrder(root);
    return 0;
}