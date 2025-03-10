import java.util.*;


public class Main
{
    public static void subse(int i,List<Integer> a,int arr[],int t,int sum){
        if(i==arr.length){
            if(sum==t){
            for(int x:a){
                System.out.print(x+" ");
            }
              System.out.println(" ");
          }
          return;
        }
        a.add(arr[i]);
        sum+=arr[i];
        subse(i+1,a,arr,t,sum);
        sum-=arr[i];
        a.remove(a.size()-1);
        subse(i+1,a,arr,t,sum);
    }

	public static void main(String[] args) {
	    int arr[] = {1,2,1};
	    List<Integer> l = new ArrayList<>();
	    subse(0,l,arr,2,0);
	}
}