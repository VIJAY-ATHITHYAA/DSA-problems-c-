//radix sort
import java.util.*;
class Main {
    public static int[] RadixSort(int arr[],int n){
        int max = Arrays.stream(arr).max().getAsInt();//to find the Max element..
        for(int i=1;max/i>0;i*=10){//this will perform the passes for no.of digits for max number
            countSort(arr,n,i);
        }
        return arr;
    }
    
    public static void countSort(int arr[],int n,int pos){//same as count sort algorithm
        //but it will perform only for the digit from the lsb to msb..
        int count[] = new int[10];
        int res[] = new int[n];
        Arrays.fill(count,0);
        for(int i=0;i<n;i++){
            ++count[(arr[i]/pos)%10];
        }
        for(int i=1;i<10;i++){
            count[i] +=count[i-1];
        }
        for(int i=n-1;i>=0;i--){
            res[--count[(arr[i]/pos)%10]] = arr[i];
        }
        for(int i=0;i<n;i++){
            arr[i] = res[i];
        }
    }
    
    public static void main(String[] args) {
        int arr[]={1,23,4,7,8,9,5,6,9,0};
        RadixSort(arr,arr.length);
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        
    }
}