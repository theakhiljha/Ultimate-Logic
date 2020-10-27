
import java.util.*;
import java.lang.*;
import java.io.*;

class KeyPair {
	public static void main (String[] args) throws Exception {
		BufferedReader br   = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		    String[] s=(br.readLine().split(" "));
		    int n = Integer.parseInt(s[0]);
		    int x =  Integer.parseInt(s[1]);
		    String s1[] =  br.readLine().split(" ");
		    Integer[] ar = new Integer[n];
		    HashMap<Integer,Integer> hm = new HashMap();
		    for(int i=0;i<n;i++)
		    {
		        ar[i] =Integer.parseInt(s1[i]);
		        hm.put(ar[i],i);
		    }
		    int flag=0;
		    for(int i=0;i<n;i++)
		    {
		        int di = x-ar[i];
		        if(hm.containsKey(di) && i!=hm.get(di))
		            {
		                flag=1;
		                break;
		            }
		    }
		    if(flag==0)
		    {
		        System.out.println("No");
		    }
		    else
		    {
		        System.out.println("Yes");
		    }
		}
	}
}
