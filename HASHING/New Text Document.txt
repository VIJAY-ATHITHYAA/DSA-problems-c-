#include <iostream>
using namespace std;
//Double Hashing..
int hash1(int);
int hash2(int);

void insertNode(int *,int);

int visited[7] = {0};
int Size = 7;
int main() {
    
    int arr[Size] = {0};
    insertNode(arr,45);
    insertNode(arr,34);
    insertNode(arr,23);
    insertNode(arr,43);
    
    for(int i=0;i<Size;i++){
      cout<<i<<" : "<<arr[i]<<"\n";
    }
    return 0;
}
//inserting into hash table
void insertNode(int *arr,int k){
    int index = hash1(k);
    if(visited[index]!=1)
    {
        arr[index] = k;
        visited[index] = 1;
    }
    else
    {
        for(int i=0;i<Size;i++){
            int ind = (hash1(k)+hash2(k)*i)%Size;
            if(visited[ind]!=1)
             { arr[ind] = k;
              visited[ind] = 1;
              return;}
        }
    }
}

//return hash value..
int hash1(int key){
    return key%7;
}
int hash2(int key){
    
    return 5-(key%5);
}
