#include<stdio.h>
#define ZONES 5
#define DAYS 7
void inputWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]);
void displayWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]);
void calculateZoneStats(int *zoneUsage,int *total,float *average,int *peakUsage,int *peakDay);
void detectWaterAlerts(int *zoneUsage,int dailyTarget,int *overLimitDays,int *totalExcess,int *spikeDays,int *alertDays);
void generateAuditReport(int usage[ZONES][DAYS],int dailyTarget[ZONES],int excessByZone[ZONES],int overLimitByZone[ZONES],int spikeByZone[ZONES],int alertByZone[ZONES]);
void rankZones(int excessByZone[ZONES]);
void displayConservationActions(int overLimitByZone[ZONES],int spikeByZone[ZONES],int excessByZone[ZONES]);
void printZoneName(int zoneIndex);
void printZoneName(int zoneIndex){
if(zoneIndex==0)
{
printf("Academic Block\n");
}
else if(zoneIndex==1)
{
printf("Hostel\n");
}
else if(zoneIndex==2)
{
printf("Library\n");
}
else if(zoneIndex==3)
{
printf("Cafeteria\n");
}
else if(zoneIndex==4)
{
printf("Sports Complex\n");
}
else
{
printf("Unknown Zone\n");
}
}
int main(){
int usage[ZONES][DAYS];
int dailyTarget[ZONES];
int excessByZone[ZONES]={0};
int overLimitByZone[ZONES]={0};
int spikeByZone[ZONES]={0};
int alertByZone[ZONES]={0};
int reportGenerated=0;
int choice;
printf("WATERWISE CAMPUS WATER AUDIT SYSTEM\n");
inputWaterData(usage,dailyTarget);
do
{
printf("PROGRAM MENU\n");
printf("1.Display Water Data\n");
printf("2.Generate Audit Report\n");
printf("3.Rank Zones by Excess\n");
printf("4.Conservation Actions\n");
printf("5.Exit\n");
printf("Enter your choice(1-5):");
scanf("%d",&choice);
printf("\nChoice is %d\n\n",choice);
if(choice==1)
{
displayWaterData(usage,dailyTarget);
}
else if(choice==2)
{
generateAuditReport(usage,dailyTarget,excessByZone,overLimitByZone,spikeByZone,alertByZone);
reportGenerated=1;
}
else if(choice==3)
{
if(!reportGenerated)
{
printf("Please select Option 2 first to generate the audit report.\n");
}
else
{
rankZones(excessByZone);
}
}
else if(choice==4)
{
if(!reportGenerated)
{
printf("Please select Option 2 first to generate the audit report.\n");
}
else
{
displayConservationActions(overLimitByZone,spikeByZone,excessByZone);
}
}
else if(choice==5)
{
printf("\nExiting WATERWISE.Conserve water!\n\n");
}
else
{
printf("Invalid choice.Please enter a number between 1 and 5.\n");
}
}
while(choice!=5);
return 0;
}
void inputWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]){
for(int i=0;i<ZONES;i++)
{
printf("Entering data for Zone %d\n",i+1);
printZoneName(i);
do
{
printf("Enter daily target(100-50000 litres):");
scanf("%d",&dailyTarget[i]);
if(dailyTarget[i]<100 || dailyTarget[i]>50000)
{
printf("Invalid target.Must be between 100 and 50000.\n");
}
}
while(dailyTarget[i]<100 || dailyTarget[i]>50000);
for(int j=0;j<DAYS;j++)
{
do
{
printf("Day %d reading(0-50000 litres):",j+1);
scanf("%d",&usage[i][j]);
if(usage[i][j]<0 || usage[i][j]>50000)
{
printf("Invalid reading.Must be between 0 and 50000.\n");
}
}
while(usage[i][j]<0 || usage[i][j]>50000);
}
}
}
void displayWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES]){
printf("%-16s | %-7s| %-7s| %-7s| %-7s| %-7s| %-7s| %-7s| %-8s\n",
       "ZONE", "Day 1", "Day 2", "Day 3", "Day 4", "Day 5", "Day 6", "Day 7", "Target");
for(int i=0;i<ZONES;i++)
{
if(i==0)
{
printf("%-16s |","Academic Block");
}
else if(i==1)
{
printf("%-16s |","Hostel");
}
else if(i==2)
{
printf("%-16s |","Library");
}
else if(i==3)
{
printf("%-16s |","Cafeteria");
}
else if(i==4)
{
printf("%-16s |","Sports Complex");
}
for(int j=0;j<DAYS;j++)
{
printf("%-7d |",usage[i][j]);
}
printf("%-8d\n",dailyTarget[i]);
}
printf("\n");
}
void calculateZoneStats(int *zoneUsage,int *total,float *average,int *peakUsage,int *peakDay)
{
int sum=0;
int maxVal=*(zoneUsage+0);
int maxDay=1;
for(int day=0;day<DAYS;day++)
{
int current=*(zoneUsage+day);
sum+=current;
if(current>maxVal)
{
maxVal=current;
maxDay=day+1;
}
}
*total=sum;
*average=(float)sum/DAYS;
*peakUsage=maxVal;
*peakDay=maxDay;
}
void detectWaterAlerts(int *zoneUsage,int dailyTarget,int *overLimitDays,int *totalExcess,int *spikeDays,int *alertDays)
{
int overCount=0;
int excessSum=0;
int spikeCount=0;
int uniqueAlerts=0;
for(int day=0;day<DAYS;day++)
{
int current=*(zoneUsage+day);
int isOver=0;
int isSpike=0;
if(current>dailyTarget)
{
isOver=1;
overCount++;
excessSum+=(current-dailyTarget);
}
if(day>0)
{
int prev=*(zoneUsage+(day-1));
if(current*5>prev*7)
{
isSpike=1;
spikeCount++;
}
}
if(isOver || isSpike)
{
uniqueAlerts++;
}
}
*overLimitDays=overCount;
*totalExcess=excessSum;
*spikeDays=spikeCount;
*alertDays=uniqueAlerts;
}
void generateAuditReport(int usage[ZONES][DAYS],int dailyTarget[ZONES],int excessByZone[ZONES],int overLimitByZone[ZONES],int spikeByZone[ZONES],int alertByZone[ZONES]){
printf("WATERWISE CAMPUS AUDIT REPORT\n");
printf("%-15s | %-8s | %-8s | %-11s| %-9s | %-12s | %-6s | %-6s\n",
       "Zone","Total(L)","Avg(L)","Peak(Day)","OverDays","Excess(L)","Spikes","Alerts");
for(int i=0;i<ZONES;i++)
{
int total,peakUsage,peakDay;
float average;
int overLimitDays,totalExcess,spikeDays,alertDays;
calculateZoneStats(&usage[i][0],&total,&average,&peakUsage,&peakDay);
detectWaterAlerts(&usage[i][0],dailyTarget[i],&overLimitDays,&totalExcess,&spikeDays,&alertDays);
excessByZone[i]=totalExcess;
overLimitByZone[i]=overLimitDays;
spikeByZone[i]=spikeDays;
alertByZone[i]=alertDays;
if(i==0)
{
printf("%-15s |","Academic Block");
}
else if(i==1)
{
printf("%-15s |","Hostel");
}
else if(i==2)
{
printf("%-15s |","Library");
}
else if(i==3)
{
printf("%-15s |","Cafeteria");
}
else if(i==4)
{
printf("%-15s |","Sports Complex");
}
printf(" %-8d | %-8.2f | %6d(D%d) | %-9d | %-12d | %-6d | %-6d\n",
       total,average,peakUsage,peakDay,overLimitDays,totalExcess,spikeDays,alertDays);
}
printf("\n");
}
void rankZones(int excessByZone[ZONES]){
int indices[ZONES]={0,1,2,3,4};
for(int i=0;i<ZONES-1;i++)
{
for(int j=0;j<ZONES-i-1;j++)
{
if(excessByZone[indices[j]]<excessByZone[indices[j+1]])
{
int temp=indices[j];
indices[j]=indices[j+1];
indices[j+1]=temp;
}
}
}
int maxExcess=excessByZone[indices[0]];
printf("Zone Ranking By Total Excess\n");
printf("Highest Total Excess(%d L):",maxExcess);
int first=1;
for(int i=0;i<ZONES;i++)
{
if(excessByZone[i]==maxExcess)
{
printf("\n");
printZoneName(i);
first=0;
}
}
printf("Rank | Zone            | Total Excess(L)\n");
int currentRank=1;
for(int i=0;i<ZONES;i++)
{
if(i>0 && excessByZone[indices[i]]<excessByZone[indices[i-1]])
{
currentRank++;
}
printf("%-4d |",currentRank);
if(indices[i]==0)
{
printf("%-16s |","Academic Block");
}
else if(indices[i]==1)
{
printf("%-16s |","Hostel");
}
else if(indices[i]==2)
{
printf("%-16s |","Library");
}
else if(indices[i]==3)
{
printf("%-16s |","Cafeteria");
}
else if(indices[i]==4)
{
printf("%-16s |","Sports Complex");
}
printf("%d\n",excessByZone[indices[i]]);
}
printf("\n");
}
void displayConservationActions(int overLimitByZone[ZONES],int spikeByZone[ZONES],int excessByZone[ZONES])
{
printf("CONSERVATION ACTION RECOMMENDATIONS\n");
for(int i=0;i<ZONES;i++)
{
printf("Zone %d ",i+1);
printZoneName(i);
printf("Total Excess: %d L:\n",excessByZone[i]);
int alertDaysCheck=overLimitByZone[i]+spikeByZone[i];
if(spikeByZone[i]>0)
{
printf("Recommend checking for a leak or unexpected use around the flagged spike days.\n");
}
if(overLimitByZone[i]>=3)
{
printf("Prioritise a water audit and reduction plan.\n");
}
else if(overLimitByZone[i]==1 || overLimitByZone[i]==2)
{
printf("Monitor those over-limit days and inspect taps or valves.\n");
}
if(alertDaysCheck==0)
{
printf("Recommend maintaining current good practices.\n");
}
}
printf("\n");
}




