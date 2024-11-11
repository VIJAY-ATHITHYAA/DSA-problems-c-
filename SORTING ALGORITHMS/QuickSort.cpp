// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void quicksort(int *,int,int);
int partition(int *,int,int);
void swap(int &,int &);
int main() {
  int *arr;
  int n;
  
  cout<<"Enter the Size :\n";
  cin>>n;
  arr = new int[n];
  cout<<"Enter The elements :\n";
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  quicksort(arr,0,n-1);
  cout<<"After Sorting elements :\n";
      for(int i=0;i<n;i++){
          cout<<arr[i]<<" ";}
return 0;
}

void quicksort(int *arr,int l,int r){
    if(l<r)
    {
        int pos = partition(arr,l,r);
        quicksort(arr,l,pos-1);
        quicksort(arr,pos+1,r);
    }
}

int partition(int *arr,int l,int r){
    int pivot = arr[l];
    int start = l;
    int end = r;
    while(start<end)
    {
        while(arr[start]<=pivot)
          start++;
        while(arr[end]>pivot)
          end--;
        if(start<end)
          swap(arr[start],arr[end]);
    }
    swap(arr[end],arr[l]);
    return end;
}

void swap(int &a,int &b){
    int tem = a;
    a = b;
    b = tem;
}
 