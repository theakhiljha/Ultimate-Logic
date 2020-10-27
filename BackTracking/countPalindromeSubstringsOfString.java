
import java.util.*;
import java.lang.*;
import java.io.*;

class countPalindromeSubstringsOfString {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		    int n= Integer.parseInt(br.readLine());
		    String s = br.readLine().trim();
		    int count=0;
		  for(int i=0;i<n;i++)
		   {
		     count+=rec(s,i,i+1);
		     count+=rec(s,i-1,i+1);
		   }
		 System.out.println(count);
		}
	}
	public static int rec(String s,int low,int high)
	{
	    int count=0;
	    if(high<s.length() && low>=0)
	    {
	        StringBuilder sb = new StringBuilder(s.substring(low,high+1));
	        sb.reverse();
	        if(s.substring(low,high+1).equals(sb.toString()))
	        {
	          return count+=rec(s,low-1,high+1)+1;
	        }
	        else
	         return  0;
	    }
	    else 
	      return 0;
	}
}















