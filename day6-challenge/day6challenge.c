#include<stdio.h>
int main(){
int n;
int arr[12];
int i,j;
printf("PATTERN DETECTIVE\n");
n=0;
while(n<5 || n>12)
{
printf("Enter the number of activity readings(N) (between 5 & 12)");
scanf("%d",&n);
printf("No.of Activity Reading is %d\n",n);
if(n<5 || n>12)
{
printf("Invalid N.Please enter a value between 5 & 12\n");
}
}
printf("Enter %d activity readings (each between 0 and 1000)\n",n);
i=0;
while(i<n)
{
printf("Reading %d ",i+1);
scanf("%d",&arr[i]);
printf("%d\n",arr[i]);
if(arr[i]<0 || arr[i]>1000)
{
printf("Invalid reading.Must be between 0 & 1000.Try again\n");
}
else
{
i++;
}
}
printf("Task-1: Original Readings\n");
i=0;
while(i<n)
{
printf("%d\n",arr[i]);
i++;
}
int sum=0;
int min_value=arr[0];
int max_value=arr[0];
i=0;
while(i<n)
{
sum+=arr[i];
if(arr[i]<min_value)
{
min_value=arr[i];
}
if(arr[i]>max_value)
{
max_value=arr[i];
}
i++;
}
float average=(float)sum/n;
printf("Task-2: Statistics\n");
printf("SUM= %d\n",sum);
printf("AVERAGE=%.2f\n",average);
printf("MINIMUM READING=%d\n",min_value);
printf("MAXIMUM READING=%d\n",max_value);
int second_largest=-1;
int has_second=0;
i=0;
while(i<n)
{
if(arr[i]<max_value)
{
if(!has_second || arr[i]>second_largest)
{
second_largest=arr[i];
has_second=1;
}
}
i++;
}
printf("TASK-3: Second-Largest Distinct Value\n");
if(has_second)
{
printf("Second-Largest Distinct Value is %d\n",second_largest);
}
else
{
printf("No Second-Largest Distinct Value exists(All Values are identical or equal to the maximum)\n");
}
int local_peaks=0;
i=1;
while(i<n-1)
{
if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
{
local_peaks++;
}
i++;
}
printf("TASK-4:Local Peaks\n");
printf("Number of Local peaks=%d\n",local_peaks);
int max_run=1;
int current_run=1;
i=0;
while(i<n-1)
{
if(arr[i+1]>arr[i])
{
current_run++;
}
else
{
if(current_run>max_run)
{
max_run=current_run;
}
current_run=1;
}
i++;
}
if(current_run>max_run)
{
max_run=current_run;
}
printf("TASK-5:Longest Strictly Increasing Run\n");
printf("Length of the longest strictly increasing continuous run=%d\n",max_run);
int k;
printf("TASK-6:Array Rotation\n");
printf("Enter integer K for rotation(positive for right,negative for left)");
scanf("%d",&k);
printf("Rotation is %d\n",k);
int effective_k=k%n;
if(effective_k<0)
{
effective_k+=n;
}
int step=0;
while(step<effective_k)
{
int last_elem=arr[n-1];
j=n-1;
while(j>0)
{
arr[j]=arr[j-1];
j--;
}
arr[0]=last_elem;
step++;
}
printf("Array after rotation\n");
i=0;
while(i<n)
{
printf("%d\n",arr[i]);
i++;
}
int r;
printf("TASK-7: Divisibility Check\n");
printf("Enter the last two digits of your registration number(R)");
scanf("%d",&r);
printf("%d\n",r);
int d=(r%9)+1;
int divisible_count=0;
i=0;
while(i<n)
{
if(arr[i]%d==0)
{
divisible_count++;
}
i++;
}
printf("Calculated Divisor D=(%d %% 9)+1=%d\n",r,d);
printf("Number of values in the rotated array exactly divisible by %d is %d\n",d,divisible_count);
return 0;
}
