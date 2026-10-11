#include<stdio.h>
int main(){
float purchase_amount;
int customer_type;
int delivery_distance;
float discount_percentage;
float discount_amount;
float amount_after_discount;
float delivery_charge;
float final_payable_amount;
printf("Enter Purchase Amount(₹):");
scanf("%f",&purchase_amount);
printf("Purchase Amount(₹): %.2f\n",purchase_amount);
printf("Enter Customer Type:");
scanf("%d",&customer_type);
printf("Customer Type: %d\n",customer_type);
printf("Enter Delivery Distance(Kilometres):");
scanf("%d",&delivery_distance);
printf("Delivery Distance(Kilometres): %d\n",delivery_distance);
if(customer_type==1)
{
printf("Customer is a Student\n");
}
if(customer_type==2)
{
printf("Customer is a Regular Customer\n");
}
if(customer_type==1 && purchase_amount>=2000)
{
discount_percentage=15;
printf("Discount is 15%%\n");
}
else if(customer_type==1 && purchase_amount<2000)
{
discount_percentage=10;
printf("Discount is 10%%\n");
}
if(customer_type==2 && purchase_amount>=3000)
{
discount_percentage=8;
printf("Discount is 8%%\n");
}
else if(customer_type==2 && purchase_amount<3000)
{
discount_percentage=0;
printf("Discount is 0%%\n");
}
if(delivery_distance<=5)
{
delivery_charge=40;
printf("Delivery charge is ₹40\n");
}
else if(delivery_distance>5 && delivery_distance<=15)
{
delivery_charge=70;
printf("Delivery charge is ₹70\n");
}
else
{
delivery_charge=100;
printf("Delivery charge is ₹100\n");
}
discount_amount=(purchase_amount*discount_percentage)/100;
printf("Discount Amount(₹): %.2f\n",discount_amount);
amount_after_discount=purchase_amount-discount_amount;
printf("Amount After Discount(₹): %.2f\n",amount_after_discount);
final_payable_amount=amount_after_discount+delivery_charge;
printf("Final Payable Amount(₹): %.2f\n",final_payable_amount);
return 0;
}


