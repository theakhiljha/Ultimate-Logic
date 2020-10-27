
import java.util.*;
import java.lang.*;
import java.io.*;

class knapsack_0_1 {
	public static void main (String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		    int n = Integer.parseInt(br.readLine());
		    int w = Integer.parseInt(br.readLine());
		    String s[] = br.readLine().split(" ");
		    String s1[] = br.readLine().split(" ");
		    int[] wt = new int[n];
		    int[] v  = new int[n];
		    for(int i=0;i<n;i++)
		    {
		        wt[i]=Integer.parseInt(s1[i]);
		        v[i]=Integer.parseInt(s[i]);
		    }
		    int[] dp = new int[w + 1];
                for (int i = 0; i < n; i++) {
                    for (int j = w; j >= wt[i]; j--) {
                        dp[j]=Math.max(dp[j - wt[i]]+v[i],dp[j]);
                    }
                }
                System.out.println(dp[w]);
		    }
	}
}
