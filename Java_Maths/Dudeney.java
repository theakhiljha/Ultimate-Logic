import java.util.Scanner;
class Dudeney
{
public static void main(String args[])
{
int n,sum=0;
Scanner sc = new Scanner(System.in);
int N=n=sc.nextInt();
while(N>0)
{
sum=sum+N%10;
N/=10;
}
if(sum==Math.cbrt(n))
System.out.println("Yes,it is a dudeney number");
else
System.out.println("It is not a dudeney number");
}
}
