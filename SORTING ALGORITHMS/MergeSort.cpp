#include <iostream>
using namespace std;
void mergesort(int *,int,int);
void merge(int *,int,int,int);
int main() {
    int *arr;
    int n;
    cout<<"Enter the Size:";
    cin>>n;
    arr = new int[n];
    cout<<"\nEnter the Array :";
    for(int i =0;i<n;i++)
      cin>>arr[i];
    mergesort(arr,0,n-1);
    cout<<"\nArray after Merge sort:";
    for(int i =0;i<n;i++)
      cout<<arr[i]<<" ";
    return 0;
}

void mergesort(int *arr,int l,int h){
    int mid = (l+h)/2;
    if(l<h)
    {
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
    return;
}

void merge(int *arr,int l,int mid,int h){
    int n1 = mid-l+1;
    int n2 = h-mid;
    int *left = new int[n1];
    int *right = new int[n2];
    for(int i=0;i<n1;i++)
      left[i] = arr[l+i];
    for(int j=0;j<n2;j++)
      right[j] = arr[mid+1+j];
   int i=0,j=0;
   int k=l;
    while(i<n1 && j<n2)
    {
            if(left[i]<=right[j])
              { arr[k] = left[i];
               i++;}
            else
             {
                 arr[k] = right[j];
                 j++;
             }
             k++;
    }
    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}
