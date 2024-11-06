#include <iostream>
using namespace std;

void insertSort(int *,int);

int main() {
    int *arr;
    int size;
    cout<<"Enter the Size :\n";
    cin>>size;
    arr = new int[size];
    cout<<"Enter the Elements: \n";
    for(int i=0;i<size;i++)
      cin>>arr[i];
    insertSort(arr,size);
    cout<<"After Sorting the array :";
    for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
    return 0;
}

void insertSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int tem = arr[i];
        int j = i-1;
        while(j>=0 && tem<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tem;
    }
}

