
import java.util.*;
import java.lang.*;
import java.io.*;

class next_larger_element {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t =Integer.parseInt(br.readLine().trim());
		for(int i=0;i<t;i++)
		{
		    int n=Integer.parseInt(br.readLine().trim());
		    String s[]=br.readLine().split(" ");
		    long[] arr = new long[n];
		    for(int j=0;j<n;j++)
		    {
		        arr[j]=Long.parseLong(s[j].trim());
		    }
		    Stack<Long> st = new Stack<Long>();
		    ArrayList<Long> al = new ArrayList<Long>();
		    for(int j=n-1;j>=0;j--)
		    {
		       
		        if(st.empty()==true)
		        {
		            al.add((long)-1);
		        }
		        else if(st.peek()>=arr[j])
		        {
		            al.add(st.peek());
		        }
		        else if(st.peek()<arr[j])
		        {
		            while(st.empty()==false && st.peek()<arr[j])
		            {
		                st.pop();
		            }
		            if(st.empty()==false)
		            {
		                al.add(st.peek());
		            }
		            else
		            {
		                al.add((long)-1);
		            }
		        }
		        st.push(arr[j]);
		    }
		    Collections.reverse(al);
		    for(Long it : al)
		    {
		        System.out.print(it+" ");
		    }
		     System.out.println(" ");
		}
	}
}
