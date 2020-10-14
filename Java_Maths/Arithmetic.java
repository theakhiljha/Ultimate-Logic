import java.util.Scanner;
class Arithmetic
{
double number1;
double number2;
char operator;
double result;
void getInput()
{
Scanner sc = new Scanner(System.in);
System.out.println("Enter two numbers: ");
number1 = sc.nextDouble();
number2 = sc.nextDouble();
System.out.print("Enter an operator [+, -, *, /]:  ");
operator = sc.next().charAt(0);
}
void ComputeResult()
{
result=0;
switch(operator)
{
case '+':
result = number1 + number2;
break;
case '-':
result = number1 - number2;
break;
case '*':
result = number1* number2;
break;
case '/':
result = number1/ number2;
break;
default:
System.out.println("Error!");
}
}
void ShowResult()
{
System.out.println("Result is "+result);
}
public static void main(String[] args)
{
Arithmetic ob = new Arithmetic();
ob.getInput();
ob.ComputeResult();
ob.ShowResult();
}
}
