#include<stdio.h>
#define ROWS 5
#define COLS 8
void initializeSeats(int seats[ROWS][COLS]);
void displaySeats(int seats[ROWS][COLS]);
int bookSeat(int seats[ROWS][COLS],int row,int col);
int cancelSeat(int seats[ROWS][COLS],int row,int col);
int reserveGroup(int seats[ROWS][COLS],int groupSize);
void displayReport(int seats[ROWS][COLS]);
int main(){
int seats[ROWS][COLS];
initializeSeats(seats);
int choice;
do
{
printf("SEAT SMART\n");
printf("1.DISPLAY SEATS\n");
printf("2.BOOK ONE SEAT\n");
printf("3.CANCEL BOOKING\n");
printf("4.GROUP RESERVATION\n");
printf("5.OCCUPANCY REPORT\n");
printf("6.EXIT\n");
printf("Enter your choice(1 to 6):");
scanf("%d",&choice);
printf("Choice is %d\n",choice);
if(choice==1)
{
displaySeats(seats);
}
else if(choice==2)
{
int r,c;
printf("Enter row (1-%d):",ROWS);
scanf("%d",&r);
printf("Enter seat (1-%d):",COLS);
scanf("%d",&c);
if(bookSeat(seats,r,c))
{
printf("Seat Row %d,Seat %d successfully booked.\n",r,c);
displaySeats(seats);
}
else
{
printf("Booking failed.Invalid seat number or seat already booked.\n");
}
}
else if(choice==3)
{
int r,c;
printf("Enter row(1-%d):",ROWS);
scanf("%d",&r);
printf("Enter seat (1-%d):",COLS);
scanf("%d",&c);
if(cancelSeat(seats,r,c))
{
printf("Seat Row %d,Seat %d booking cancelled successfully.\n",r,c);
displaySeats(seats);
}
else
{
printf("Cancellation failed.Invalid seat number or seat is not currently booked.\n");
}
}
else if(choice==4)
{
int groupSize;
printf("Enter group size (2-%d):",COLS);
scanf("%d",&groupSize);
if(groupSize<2 || groupSize>COLS)
{
printf("Invalid group size.Must be between 2 and %d.\n",COLS);
}
else
{
if(reserveGroup(seats,groupSize))
{
displaySeats(seats);
}
else
{
printf("Group reservation failed.No consecutive available seats found for %d people in a single row.\n",groupSize);
}
}
}
else if(choice==5)
{
displayReport(seats);
}
else if(choice==6)
{
printf("Thank you for using SEATSMART.Closing program..\n");
}
}
while(choice!=6);
return 0;
}
void initializeSeats(int seats[ROWS][COLS])
{
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<COLS;j++)
{
seats[i][j]=0;
}
}
}
void displaySeats(int seats[ROWS][COLS])
{
printf("AUDITORIUM SEATING ARRANGEMENT\n");
for(int j=0;j<COLS;j++)
{
printf("S%d ",j+1);
}
for(int i=0;i<ROWS;i++)
{
printf("\nRow %d:\n",i+1);
for(int j=0;j<COLS;j++)
{
printf("%d",seats[i][j]);
}
}
printf("\nLegend:0=Available,1=Booked\n");
}
int bookSeat(int seats[ROWS][COLS],int row,int col)
{
if(row<1 || row>ROWS || col<1 || col>COLS)
{
return 0;
}
int r=row-1;
int c=col-1;
if(seats[r][c]==0)
{
seats[r][c]=1;
return 1;
}
return 0;
}
int cancelSeat(int seats[ROWS][COLS],int row,int col)
{
if(row<1 || row>ROWS || col<1  || col>COLS)
{
return 0;
}
int r=row-1;
int c=col-1;
if(seats[r][c]==1)
{
seats[r][c]=0;
return 1;
}
return 0;
}
int reserveGroup(int seats[ROWS][COLS],int groupSize)
{
if(groupSize<2 || groupSize>COLS)
{
return 0;
}
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<=COLS-groupSize;j++)
{
int available=1;
for(int k=0;k<groupSize;k++)
{
if(seats[i][j+k]==1)
{
available=0;
break;
}
}
if(available)
{
for(int  k=0;k<groupSize;k++)
{
seats[i][j+k]=1;
}
printf("Group reservation successful.Allocated Row %d,Seats %d to %d.\n",i+1,j+1,j+groupSize);
return 1;
}
}
}
return 0;
}
void displayReport(int seats[ROWS][COLS])
{
int bookedCount=0;
int freeCount=0;
int rowBooked[ROWS]={0};
for(int i=0;i<ROWS;i++)
{
for(int j=0;j<COLS;j++)
{
if(seats[i][j]==1)
{
bookedCount++;
rowBooked[i]++;
}
else
{
freeCount++;
}
}
}
float occupancy=((float)bookedCount/(ROWS*COLS))*100.0;
printf("OCCUPANCY REPORT\n");
printf("Total Booked Seats: %d\n",bookedCount);
printf("Total Available Seats: %d\n",freeCount);
printf("Occupancy Percentage: %.2f%%\n",occupancy);
int maxBooked=-1;
for(int i=0;i<ROWS;i++)
{
if(rowBooked[i]>maxBooked)
{
maxBooked=rowBooked[i];
}
}
printf("Busiest Row(s): \n");
if(maxBooked==0 && bookedCount==0)
{
printf("None(No seats booked yet)\n");
}
else
{
int first=-1;
for(int i=0;i<ROWS;i++)
{
if(rowBooked[i]==maxBooked)
{
printf("Row %d(%d seats)\n",i+1,maxBooked);
first=0;
}
}
}
}

