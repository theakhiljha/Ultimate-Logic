
import java.util.*;
import java.lang.*;
import java.io.*;

class MaximumOfAllSubarrays {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcases = Integer.parseInt(br.readLine());
		for(int z=0;z<testcases;z++)
		{
		    String s[] = br.readLine().split(" ");
		    int n = Integer.parseInt(s[0]);
		    int k = Integer.parseInt(s[1]);
		    String s1[] = br.readLine().split(" ");
		    int[] arr = new int[n];
		    for(int i=0;i<n;i++)
		    {
		        arr[i]=Integer.parseInt(s1[i]);
		    }
		    Deque<Integer> d = new LinkedList<Integer>();
		    StringBuffer sb = new StringBuffer();
		    for(int i=0;i<k;i++)
		    {
		        while(!d.isEmpty() && arr[i]>arr[d.peekLast()])
		           d.removeLast();
		        d.addLast(i);     
		    }
		    sb.append(arr[d.peek()]+" ");
		    for(int i = k;i<n;i++)
		    {
		        while(!d.isEmpty() && d.peek()<=i-k)
		           d.removeFirst();
		        while(!d.isEmpty() && arr[i]>arr[d.peekLast()])
		           d.removeLast();
		        d.addLast(i);
		        sb.append(arr[d.peek()]+" ");
		             
		    }
		    System.out.println(sb);
		    
		}
	}
}
