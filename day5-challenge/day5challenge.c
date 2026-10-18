#include<stdio.h>
#include<math.h>
int main(){
int choice=0;
while(choice!=4)
{
printf("\nMENU OPTIONS FOR THE USER TO CHOOSE A MATHEMATICAL OPERATION\n");
printf("1.Solve a Linear Equation (ax+b=0)\n");
printf("2.Calculate factorial (n!)\n");
printf("3.Solve a quadratic equation(ax^2+bx+c=0)\n");
printf("4.Exit\n");
printf("Enter your Choice ranging from (1 to 4)\n");
printf("\nEnter Your Choice ");
scanf("%d",&choice);
printf("Your selected choice is %d\n",choice);
if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
{
printf("Please Enter a Valid Input from the above mentioned MENU OPTIONS \n");
continue;
}
if(choice==1)
{
printf("Solve a Linear Equation(ax+b=0)\n");
float a;
float b;
printf("Enter the coefficient value of a");
scanf("%f",&a);
printf("Enter the coefficient value of b");
scanf("%f",&b);
printf("Value of a is %.2f\n",a);
printf("Value of b is %.2f\n",b);
if(a!=0)
{
float x;
x=-b/a;
printf("Solution is %.2f\n",x);
}
else if(a==0 && b==0)
{
printf("The equation has Infinitely-many solutions\n");
}
else if(a==0 && b!=0)
{
printf("The equation has no solution\n");
}
}
else if(choice==2)
{
int n;
printf("Calculate Factorial(n!)\n");
printf("Enter an integer value from (0 to 12)");
scanf("%d",&n);
printf("Integer Value is %d\n",n);
if(n<0 || n>12)
{
printf("Rejected Values outside 0-12.Remember that 0!=1\n");
}
else
{
int factorial=1;
for(int i=0;i<=n;i++)
{
if(i>0)
{
factorial*=i;
}
}
printf("Factorial of (%d!)=%d\n",n,factorial);
}
}
else if(choice==3)
{
printf("Solve a Quadratic Equation(ax^2+bx+c=0)\n");
float a;
float b;
float c;
printf("Enter the coefficient value of a");
scanf("%f",&a);
printf("Enter the coefficient value of b");
scanf("%f",&b);
printf("Enter the coefficient value of c");
scanf("%f",&c);
printf("Value of a is %.2f\n",a);
printf("Value of b is %.2f\n",b);
printf("Value of c is %.2f\n",c);
if(a==0)
{
printf("It is not a Quadratic Equation\n");
}
else
{
float D=(b*b)-(4*a*c);
printf("Discriminant (D)=%.2f\n",D);
if(D>0)
{
float root1=(-b+sqrt(D))/(2*a);
float root2=(-b-sqrt(D))/(2*a);
printf("Two Distinct Real Roots exists\n");
printf("Root 1 is %.2f\n",root1);
printf("Root 2 is %.2f\n",root2);
}
else if(D==0)
{
float root=-b/(2*a);
printf("One repeated Real Root is Calculated\n");
printf("Root is %.2f\n",root);
}
else
{
printf("No Real Roots exits as Discriminant is negative \n");
}
}
}
else if(choice==4)
{
printf("Exiting from the Menu of the Program\n");
break;
}
}
return 0;
}



