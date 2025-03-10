import java.util.*;


public class Main
{
    public static boolean subse(int i,List<Integer> a,int arr[],int t,int sum){
        //this method will avoid the recursion calls when the condition is true....
        if(i==arr.length){
            if(sum==t){
            for(int x:a){
                System.out.print(x+" ");
            }
            System.out.println(" ");
            return true;
            }
            return false;
        }
        a.add(arr[i]);
        sum+=arr[i];
        if(subse(i+1,a,arr,t,sum)==true)
            return true;
        sum-=arr[i];
        a.remove(a.size()-1);
        if(subse(i+1,a,arr,t,sum)==true)
            return true;
        return false;
    }

	public static void main(String[] args) {
	    int arr[] = {1,2,3,4,5,6,7};
	    List<Integer> l = new ArrayList<>();
	    subse(0,l,arr,6,0);
	}
}