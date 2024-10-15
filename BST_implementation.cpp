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
  void Display(Node *root)
  {
      if(!root)
         {
             return;
         }
      Display(root->left);
      cout<<root->data<<" ";
      Display(root->right);
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