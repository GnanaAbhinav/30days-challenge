#include<stdio.h>
int main(){
int n;
int i;
int j;
int r;
int ticket[15];
int missing=-1;
int missing_count=0;
int duplicate=-1;
int duplicate_count=0;
int out_of_order=0;
int target;
int target_count=0;
int occurrences;
printf("TICKET TRACE\n");
while(n<5 || n>15)
{
printf("Enter N(5 to 15)");
scanf("%d",&n);
printf("%d\n",n);
if(n<5 || n>15)
{
printf("Invalid N.Please Try Again\n");
}
}
for(i=0;i<n;i++)
{
ticket[i]=0;
while(ticket[i]<1 || ticket[i]>n)
{
printf("Enter ticket %d (1 to %d) ",i+1,n);
scanf("%d",&ticket[i]);
printf("%d\n",ticket[i]);
if(ticket[i]<1 || ticket[i]>n)
{
printf("TICKET ID is out of range.Enter a value between 1 and %d \n",n);
}
}
}
for(int val=1;val<=n;val++)
{
occurrences=0;
for(i=0;i<n;i++)
{
if(ticket[i]==val)
{
occurrences++;
}
}
if(occurrences==0)
{
missing=val;
missing_count++;
}
else if(occurrences==2)
{
duplicate=val;
duplicate_count++;
}
else if(occurrences>2)
{
duplicate_count+=2;
}
}
if(missing_count!=1 || duplicate_count!=1)
{
printf("Invalid log.The scan sequence must contain exactly one missing ID and one duplicate ID\n");
}
else
{
printf("The duplicated ID is %d,and the missing ID is %d \n",duplicate,missing);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(ticket[i]>ticket[j])
{
out_of_order++;
}
}
}
printf("Number of out-of-order pairs: %d\n",out_of_order);
printf("Enter last two digits of registration number(R) ");
scanf("%d",&r);
printf("Last two digits of registration number is %d\n",r);
target=(r%n)+1;
printf("Target ID is %d\n",target);
printf("Positions:\n");
for (i=0;i<n;i++)
{
if(ticket[i]==target)
{
printf("%d\n",i+1);
target_count++;
}
}
printf("Occurrence count is %d\n",target_count);
return 0;
}


