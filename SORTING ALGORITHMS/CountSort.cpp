#include <iostream>
using namespace std;
void CountSort(int *,int);
int FindMax(int *,int);
int main() {
    int *arr;
    int n;
    cout<<"Enter the Size: ";
    cin>>n;
    cout<<"\nEnter The Elements: ";
    arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    CountSort(arr,n);  
    cout<<"After Sorting the array:\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
void CountSort(int *arr,int n){
    int max = FindMax(arr,n);
    int count[max+1] = {0};
    int res[n] = {0};
    //count the Occurrance of element...
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    //cumulative sum..
    for(int i=1;i<max+1;i++){
       count[i] = count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        res[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    //transferring to the arr..
    for(int i=0;i<n;i++){
        arr[i] = res[i];
    }
}

int FindMax(int *arr,int n){
   int max = arr[0];
   for(int i=1;i<n;i++){
       if(arr[i]>max)
         max = arr[i];
   } 
   return max;
}