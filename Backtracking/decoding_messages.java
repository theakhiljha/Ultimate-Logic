import java.lang.*;
import java.io.*;

class decoding_messages {
	public static void main (String[] args) throws Exception {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		    int  n = Integer.parseInt(br.readLine());
		    ArrayList<String> al = new ArrayList<String>();
		    HashMap<Integer,String> hm = new HashMap<Integer,String>();
		    for(int i=1;i<=26;i++)
		    {
		        hm.put(i,String.valueOf((char)(i+96)));
		    }
		    if(n==0)
		    {
		        System.out.println(1);
		    }
		    else
		    {
		      String s = br.readLine();
		      String st = "";
		      rec(s,0,hm,st);
		      System.out.println(count);
		      count=0;
		    }
		}
	}
	static int count=0;
	static void rec(String s , int n,HashMap<Integer,String> hm,String st)
	{
	    if(n==s.length())
	    {
	        count++;
	        //System.out.println(st);
	    }
	    else
	    {
	        if(n<s.length()-1)
	        {
	            int tw  = (int)(s.charAt(n)-'0')*10 + (int)(s.charAt(n+1)-'0');
                if(tw>=10 && tw<=26)
                {
                    String ast = st + hm.get(tw);
                    rec(s,n+2,hm,ast);
                }
	        }
	            int on  = (int)(s.charAt(n)-'0');
                if(on>=1 && on<=9)
                {
                    String ast1 = st + hm.get(on);
                    rec(s,n+1,hm,ast1);
                }
	    }
	}
}
