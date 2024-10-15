#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node *left;
    Node *right;
};

class Tree{
    public:
    
        Node *create(){
             int x;
        Node *newnode = new Node();
        cout<<"\nEnter the Data:(-1 for No Node:): ";
        cin>>x;
        if(x==-1) {
            return nullptr;
        }
        newnode->data = x;
        cout<<"\nEnter the Left Node of "<<x<<" :";
        newnode->left=create();
        cout<<"\nEnter the right Node of "<<x<<" :";
        newnode->right=create();
        return newnode;
        }
    
      void display(Node *root){
          if(root==nullptr)
          {
              return;
          }	
          display(root->left);
          cout<<root->data<<" ";
          display(root->right);
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
      } 
      Node * copy(Node *root)
      {
          if(!root)
          {
              return nullptr;
          }
         Node *node = new Node();
         node->data = root->data;
         node->left = copy(root->left);
         node->right = copy(root->right);
         return node;
      }
      bool Check(Node *root1,Node *root2)
      {
          bool res=true;
          if(!root1&&!root2)
            return true;
          if(!root1||!root2)
            return false;
          else{
              if(root1->data == root2->data)
              {
                  res = Check(root1->left,root2->left);
                  res = Check(root1->right,root2->right);
              }
          }
          return res;
      }
     Node *Mirror(Node *root)
     {
         if(!root)
           return nullptr;
         if(root->left&&root->right)
         {
             Node *tem = root->left;
             root->left = root->right;
             root->right = tem;
         }
         Mirror(root->left);
         Mirror(root->right);
        return root;
     }
};

int main() {
    Tree t;
    Node *root = t.create();
    cout<<"Tree Datas are:\n";
    t.LevelOrder(root);
    // cout<<"Copy of the Tree:\n";
    // Node *root = t.copy(root1);
    // t.LevelOrder(root);
    // Node *root1 = t.create();
    // t.LevelOrder(root1);
    // bool val = t.Check(root,root1);
    // if(val)
    //   cout<<"Matches";
    //  else
    //   cout<<"Not Matches";
    Node *root2 = t.Mirror(root);
    t.LevelOrder(root2);
    return 0;
}