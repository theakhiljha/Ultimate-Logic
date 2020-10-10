import java.util.Scanner;
public class Dec_to_oct 
{
  public static void main(String args[]) 
  {
    int n,rem,i=1,j;
    int oct_num[]=new int[50];
    Scanner o=new Scanner(System.in);
    System.out.println("Dec_Number:");
    n=o.nextInt();
    rem=n;
    while(rem!=0)
    {
        oct_num[i++]=rem%8;
	      rem=rem/8;
    }
    System.out.println("Octal Value of " + n + " is:");
    for(j=i-1;j>0;j--)  //it will reverse the rem and give the octal number
    {
        System.out.print(oct_num[j]); //for ease, we took array here for reversing 
    }
  
}
}
