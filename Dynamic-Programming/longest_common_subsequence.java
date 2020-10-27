
import java.util.*;
import java.lang.*;
import java.io.*;

class longest_common_subsequence {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int j=0;j<t;j++)
		{
		    int n=Integer.parseInt(br.readLine());
		    String s[] = br.readLine().split(" ");
		    int[] arr = new int[n];
		    int[] vis = new int[n];
		    for(int i=0;i<n;i++)
		    {
		        arr[i]=Integer.parseInt(s[i]);
		        vis[i]=1;
		    }
		    
		    int max=-1;
		    for(int k=1;k<n;k++)
		    {
		        for(int l=0;l<k;l++)
		        {
		            if(arr[k]>arr[l])
		            vis[k]=Math.max(vis[l]+1,vis[k]);
		        }
		       if(vis[k]>max)
		        {
		            max=vis[k];
		        }
		    }
		    System.out.println(max);
		    
		    
		}
	}
}
