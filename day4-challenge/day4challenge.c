#include<stdio.h>
int main(){
int expense;
int valid_expenses=0;
int total_valid_expenses=0;
int small_count=0;
int small_total=0;
int medium_count=0;
int medium_total=0;
int large_count=0;
int large_total=0;
printf("LOOP LAB\n");
for(int i=1;i<=10;i++)
{
printf("Enter Expense Amount");
scanf("%d",&expense);
printf("%d\n",expense);
if(expense==0)
{
break;
}
else if(expense<0)
{
printf("Invalid Expense\n");
}
else if(expense<100)
{
printf("small\n");
valid_expenses++;
total_valid_expenses+=expense;
small_count++;
small_total+=expense;
}
else if(expense<500)
{
printf("medium\n");
valid_expenses++;
total_valid_expenses+=expense;
medium_count++;
medium_total+=expense;
}
else if(expense>=500)
{
printf("large\n");
valid_expenses++;
total_valid_expenses+=expense;
large_count++;
large_total+=expense;
}
}
printf("No.of valid expenses %d\n",valid_expenses);
printf("Total no.of valid expenses %d\n",total_valid_expenses);
printf("Small count %d\n",small_count);
printf("Small total %d\n",small_total);
printf("Medium count %d\n",medium_count);
printf("Medium total %d\n",medium_total);
printf("Large count %d\n",large_count);
printf("Large total %d\n",large_total);
if(valid_expenses>0)
{
float average_valid_expenses=total_valid_expenses/valid_expenses;
printf("Average valid expenses %.2f\n",average_valid_expenses);
}
else
{
printf("No valid average expenses\n");
}
return 0;
}

