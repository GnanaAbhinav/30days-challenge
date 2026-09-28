#include<stdio.h>
int main(){
int distance;
int mileage;
int fuel_price;
float fuel_required;
float total_fuel_price;
printf("Enter Distance(km)");
scanf("%d",&distance);
printf("%d\n",distance);
printf("Enter Mileage(km/litre)");
scanf("%d",&mileage);
printf("%d\n",mileage);
printf("Enter Fuel Price(₹/litre)");
scanf("%d",&fuel_price);
printf("%d\n",fuel_price);
fuel_required=distance/mileage;
printf("%f\n",fuel_required);
total_fuel_price=fuel_required*fuel_price;
printf("%f\n",total_fuel_price);
return 0;
}


