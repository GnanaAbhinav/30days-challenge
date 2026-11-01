#include<stdio.h>
int main(){
printf("GRID WATCH\n");
int n=0,T=0,i,j;
int grid[6][6];
while(n<3 || n>6)
{
printf("Enter N (3 to 6)=");
scanf("%d",&n);
printf("%d\n",n);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
do
{
printf("Enter score for (%d,%d) [0-100]=",i+1,j+1);
scanf("%d",&grid[i][j]);
printf("%d\n",grid[i][j]);
}
while(grid[i][j]<0 || grid[i][j]>100);
}
}
do
{
printf("Enter warning threshold T[1-100]=");
scanf("%d",&T);
printf("%d\n",T);
}
while(T<1 || T>100);
int row_sum[6]={0};
int max_row_sum=-1;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
row_sum[i]+=grid[i][j];
}
if(row_sum[i]>max_row_sum)
{
max_row_sum=row_sum[i];
}
}
int col_sum[6]={0};
int max_col_sum=-1;
for(j=0;j<n;j++)
{
for(i=0;i<n;i++)
{
col_sum[j]+=grid[i][j];
}
if(col_sum[j]>max_col_sum)
{
max_col_sum=col_sum[j];
}
}
printf("Row(s) with Highest Total (%d) is ",max_row_sum);
for(i=0;i<n;i++)
{
if(row_sum[i]==max_row_sum)
{
printf("%d\n",i+1);
}
}
printf("Column(s) with Highest Total(%d) is ",max_col_sum);
for(j=0;j<n;j++)
{
if(col_sum[j]==max_col_sum)
{
printf("%d\n",j+1);
}
}
int max_risk=-1;
int count_T=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(grid[i][j]>max_risk)
{
max_risk=grid[i][j];
}
if(grid[i][j]>=T)
{
count_T++;
}
}
}
printf("Highest Risk Score is %d\n",max_risk);
printf("Occurs at Position(s)(1-based) is ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(grid[i][j]==max_risk)
{
printf("(%d,%d)\n",i+1,j+1);
}
}
}
printf("Total Cells>=T is %d\n",count_T);
int d1=0,d2=0;
for(i=0;i<n;i++)
{
d1+=grid[i][i];
d2+=grid[i][n-1-i];
}
printf("Main Diagonal Sum= %d,Secondary Diagonal Sum= %d\n",d1,d2);
if(d1==d2)
{
printf("Diagonal Totals Status is Balanced\n");
}
else
{
printf("Diagonal Totals Status is Not Balanced\n");
}
int boundary_sum=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==0 || i==n-1 || j==0 || j==n-1)
{
boundary_sum+=grid[i][j];
}
}
}
printf("Boundary Total Sum=%d\n",boundary_sum);
int hotspots=0;
printf("Local Hotspot(s): \n");
for(i=1;i<n-1;i++)
{
for(j=1;j<n-1;j++)
{
int val=grid[i][j];
if(val>=T && val>grid[i-1][j] && val>grid[i+1][j] && val>grid[i][j-1] && val>grid[i][j+1])
{
printf("Hotspot at (%d,%d) with score %d\n",i+1,j+1,val);
hotspots++;
}
}
}
if(hotspots==0)
{
printf("No local hotspots found\n");
}
printf("Decision: ");
if(hotspots>0)
{
printf("CRITICAL\n");
}
else if(count_T>=n)
{
printf("WARNING\n");
}
else
{
printf("NORMAL\n");
}
return 0;
}

