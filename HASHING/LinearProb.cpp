#include <iostream>
using namespace std;
int hashfn(int);

void insertNode(int *,int);

int visited[7] = {0};

int main() {
    
    int arr[7] = {0};
    insertNode(arr,45);
    insertNode(arr,34);
    insertNode(arr,23);
    insertNode(arr,16);
    
    for(int i=0;i<7;i++){
      cout<<i<<" : "<<arr[i]<<"\n";
    }
    return 0;
}
//inserting into hash table
void insertNode(int *arr,int k){
    int index = hashfn(k);
    if(visited[index]!=1)
    {
        arr[index] = k;
        visited[index] = 1;
    }
    else
    {
        int i=index;
       while(i<7)
       {
          i = (i+1)%7;
          if(visited[i] != 1)
          {
              arr[i] = k;
              visited[i] = 1;
              return;
          }
       }
    }
}

//return hash value..
int hashfn(int key){
    return key%7;
}
