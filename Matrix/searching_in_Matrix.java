
import java.util.*;
import java.lang.*;
import java.io.*;

class searching_in_Matrix {
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for(int l=0;l<t;l++)
		{
		String rcs[] = br.readLine().split(" ");
		int r = Integer.parseInt(rcs[0]);
		int c = Integer.parseInt(rcs[1]);
		String mats[] = br.readLine().split(" ");
		int[][] mat = new int[r][c];
		int n=0;
		for(int i=0;i<r;i++)
		{
		    for(int j=0;j<c;j++)
		    {
		        mat[i][j]=Integer.parseInt(mats[n++]);
		    }
		}
		int x = Integer.parseInt(br.readLine());
		int i=0,j=c-1,flag=0;
		while(i<r)
		{
		    if(x==mat[i][0]) 
		    {
		        System.out.println(1);
		        flag=1;
		        break;
		    }
		    else if(x==mat[i][j])
		    {
		        System.out.println(1);
		        flag=1;
		        break;
		    }
		    else if(x>mat[i][0] && x<mat[i][j])
		    {
		        int k=1; 
		        while(k<j)
		        {
		            if(mat[i][k]==x)
		            {
		                System.out.println(1);
		                flag=1;
		                break;
		            }
		            k++;
		        }
		        if(flag==1) break;
		    }
		    i++;
		}
		if(flag==0) 
		{
		   System.out.println(0); 
		}
		}
	}
}
