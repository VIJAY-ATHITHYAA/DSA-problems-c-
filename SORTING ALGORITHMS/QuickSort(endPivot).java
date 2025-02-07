import java.util.*;

class Main {
    public static int Partition(int arr[],int p,int r){
        int x = arr[r];
        int i=p-1;
        for(int j=p;j<=r-1;j++){
            if(arr[j]<=x)
             {
                 i=i+1;
                 swap(arr,i,j);
             }
        }
        swap(arr,i+1,r);
        return i+1;
    }
    public static void quicksort(int arr[],int p,int r){
        if(p<r)
         {
             int q = Partition(arr,p,r);
             quicksort(arr,p,q-1);
             quicksort(arr,q+1,r);
         }
    }
    public static void swap(int arr[],int x,int y){
        int tem=arr[x];
        arr[x] = arr[y];
        arr[y] = tem;
    }
     public static void main(String[] args) {
      int arr[] = {1,1,1,1,1,1,1,1};
      quicksort(arr,0,arr.length-1);
      for(int i=0;i<arr.length;i++){
          System.out.print(arr[i]+" ");
      }
    }
}