import java.util.*;


public class Main
{
    public static int subse(int i,int arr[],int t,int sum){
        //this method will avoid the recursion calls when the condition is true....
        if(i==arr.length){
            if(sum==t){
            return 1;
            }
            return 0;
        }
        sum+=arr[i];
        int l=subse(i+1,arr,t,sum);
        sum-=arr[i];
        int r=subse(i+1,arr,t,sum);
        return l+r;
    }

	public static void main(String[] args) {
	    int arr[] = {1,2,1};
	    System.out.println(subse(0,arr,2,0));
	}
}