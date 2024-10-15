#include <iostream>
using namespace std;
//min heap...
class Heap{
    public:
      int heap[100];
      int size=0;
      void insert(int val)
      {
          int i=size;
          heap[i] = val;
          size++;
          while(i>0)
          {
             int parent=(i-1)/2;
              if(heap[i]<=heap[parent])
              {
                  swap(heap[i],heap[parent]);
                  i = parent;
              }
              else
               break;
          }
      }
      
      void Delete()
      {
         int i= 0;
         heap[i] = heap[size-1];
         size--;
        
         while(i<size)
         {
             int left = (2*i)+1;
             int right = (2*i)+2;
             int small = i;
             if(left<size&&heap[left]<heap[small])
             {
                 small = left;
             }
             
             if(right<size&&heap[right]<heap[small])
              {
                  small = right;
              }
            if(small!=i)
            {  
               swap(heap[i],heap[small]);
               i = small;
            }
            else
             {
                 break;
             }
             
         }
      }
      void swap(int &i,int &j)
      {
          int tem = i;
          i = j;
          j=tem;
      }
      void display()
      {
          for(int i=0;i<size;i++)
          {
              cout<<heap[i]<<" ";
          }
      }
};
int main() {
    Heap h;
    h.insert(10);
    h.insert(20); 
     h.insert(30);
     h.insert(40);
      h.insert(50);
    h.display();
    cout<<"After Deletion Operation..\n";
    h.Delete();
    h.display();
    cout<<h.size;
    return 0;
}