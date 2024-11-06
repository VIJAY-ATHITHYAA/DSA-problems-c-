#include <iostream>
using namespace std;
//heap sort algorithm ..
void heapify(int*,int);
void Maxheapify(int *,int,int);
void swap(int &,int &);
int main()
{
   int *arr,size;
   cout<<"Enter the Size :\n";
   cin>>size;
   arr = new int[size];
   cout<<"Enter the Elements :\n";
   for(int i=0;i<size;i++)
     cin>>arr[i];
   heapify(arr,size);
   cout<<"Array After Heap Sort\n";
   for(int i=0;i<size;i++)
     cout<<arr[i]<<" ";
   return 0;
}

void heapify(int *arr,int n){
    for(int i=(n/2)-1;i>=0;i--)
       Maxheapify(arr,n,i);//till this all the elements are maxHeaped..
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        Maxheapify(arr,i,0);
    }
}

void Maxheapify(int *arr,int n,int i){
    int large = i;
    int l = 2*i+1;
    int r = 2*i+2;
    while(l<n && arr[large]<arr[l])
    {
        large = l;
    }
    while(r<n && arr[large]<arr[r])
    {
        large = r;
    }
    if(large!=i){
        swap(arr[large],arr[i]);
        Maxheapify(arr,n,large);
    }
}

void swap(int &a,int &b){
    int tem = a;
    a = b;
    b = tem;
}

