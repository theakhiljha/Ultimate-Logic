
import java.util.*;
import java.lang.*;
import java.io.*;

class SOrtingAnArray {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		    int n=Integer.parseInt(br.readLine());
		    String[] s = br.readLine().split(" ");
		    int[] arr = new int[n];
		    for(int i=0;i<n;i++)
		    {
		        arr[i]=Integer.parseInt(s[i]);
		    }
		    int low=0,mid=0,high=n-1,temp;
		    while(mid<=high)
		    {
		        if(arr[mid]==0)
		        {
		            temp=arr[mid];
		            arr[mid]=arr[low];
		            arr[low]=temp;
		            low++;
		            mid++;
		        }
		        else if(arr[mid]==1)
		        {
		           mid++; 
		        }
		        else if(arr[mid]==2)
		        {
		            temp=arr[mid];
		            arr[mid]=arr[high];
		            arr[high]=temp;
		            high--;
		        }
		    }
		    for(int i=0;i<n;i++)
		    {
		        System.out.print(arr[i]+" ");
		    }
		    System.out.println(" ");
		    
		}
	}
}
