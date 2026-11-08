#include<stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS]);
void displayData(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS]);
void calculateAverages(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS],float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES]);
void detectRiskZones(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS],int riskDays[ZONES]);
void computeGreenIndex(float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES],float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES],int riskDays[ZONES]);
int main(){
float temp[ZONES][DAYS];
float humidity[ZONES][DAYS];
int aqi[ZONES][DAYS];
float avgTemp[ZONES];
float avgHumidity[ZONES];
float avgAQI[ZONES];
int riskDays[ZONES];
float greenIndex[ZONES];
int dataReady=0;
int choice;
printf("ECOGUARD\n");
do
{
printf("PROGRAM MENU\n");
printf("1.Input/Update Data\n");
printf("2.Display Data\n");
printf("3.Zone-wise Averages\n");
printf("4.Detect Risk Days\n");
printf("5.Green Index and Ranking\n");
printf("6.Recommendations\n");
printf("7.Exit\n");
printf("Enter your choice (1-7): ");
scanf("%d",&choice);
printf("Choice is %d\n",choice);
if(choice==1)
{
inputData(temp,humidity,aqi);
dataReady=1;
}
else if(choice==2)
{
if(!dataReady)
{
printf("Data has not been entered.Please select Option 1 first.\n");
}
else
{
displayData(temp,humidity,aqi);
}
}
else if(choice==3)
{
if(!dataReady)
{
printf("Data has not been entered.Please select Option 1 first.\n");
}
else
{
calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
printf("Seven-Day Zone-wise Averages\n");
printf("ZONE   | Avg Temp(C)      | Avg Humidity (%%)     | Avg AQI\n");
for(int i=0;i<ZONES;i++)
{
printf("Zone %d |Avg Temp(C):%.2f |Avg Humidity(%%):%.2f | Avg AQI:%.2f\n",i+1,avgTemp[i],avgHumidity[i],avgAQI[i]);
}
}
}
else if(choice==4)
{
if(!dataReady)
{
printf("Data has not been entered.Please select Option 1 first.\n");
}
else
{
detectRiskZones(temp,humidity,aqi,riskDays);
}
}
else if(choice==5)
{
if(!dataReady)
{
printf("Data has not been entered.Please select Option 1 first.\n");
}
else
{
calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
computeGreenIndex(avgTemp,avgHumidity,avgAQI,greenIndex);
displayRanking(greenIndex);
}
}
else if(choice==6)
{
if(!dataReady)
{
printf("Data has not been entered.Please select Option 1 first.\n");
}
else
{
calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAQI);
detectRiskZones(temp,humidity,aqi,riskDays);
displayRecommendations(avgTemp,avgHumidity,avgAQI,riskDays);
}
}
else if(choice==7)
{
printf("Exiting EcoGuard Program.Stay Green!\n");
}
else
{
printf("Invalid choice.Please enter a number between 1 and 7.\n");
}
}
while(choice!=7);
return 0;
}
void inputData(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS]){
printf("Enter Environmental Reading for 5 Zones over 7 Days\n");
printf("Note:Zone 1=Academic Block, 2=Hostel, 3=Library, 4=Cafeteria, 5=Sports Area\n");
for(int i=0;i<ZONES;i++)
{
printf("Zone %d:\n",i+1);
for(int j=0;j<DAYS;j++)
{
do
{
printf("Day %d-Temperature[10-50 C]:",j+1);
scanf("%f",&temp[i][j]);
if(temp[i][j]<10 || temp[i][j]>50)
{
printf("Must be between 10 and 50.Re-enter.\n");
}
}
while(temp[i][j]<10 || temp[i][j]>50);
do
{
printf("Day %d-Humidity[0-100 %%]:",j+1);
scanf("%f",&humidity[i][j]);
if(humidity[i][j]<0 || humidity[i][j]>100)
{
printf("Must be between 0 and 100.Re-enter.\n");
}
}
while(humidity[i][j]<0 || humidity[i][j]>100);
do
{
printf("Day %d-AQI[0-500]: ",j+1);
scanf("%d",&aqi[i][j]);
if(aqi[i][j]<0 || aqi[i][j]>500)
{
printf("Must be between 0 and 500.Re-enter.\n");
}
}
while(aqi[i][j]<0 || aqi[i][j]>500);
}
}
printf("All data successfully entered and validated.\n");
}
void displayData(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS]){
printf("SEVEN-DAY ENVIRONMENTAL MATRICES\n");
for(int i=0;i<ZONES;i++)
{
printf("Zone %d:\n",i+1);
printf("Parameter | Day 1   | Day 2   | Day 3   | Day 4   | Day 5   | Day 6   | Day 7   |\n");
printf("Temp(C)   |");
for(int j=0;j<DAYS;j++)
{
printf("%6.1f   |",temp[i][j]);
}
printf("\nHumidity(%%)|");
for(int j=0;j<DAYS;j++)
{
printf("%6.1f   |",humidity[i][j]);
}
printf("\nAQI       |");
for(int j=0;j<DAYS;j++)
{
printf("%6d   |",aqi[i][j]);
}
printf("\n");
}
}
void calculateAverages(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS],float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES])
{
for(int i=0;i<ZONES;i++)
{
float sumTemp=0,sumHum=0,sumAQI=0;
for(int j=0;j<DAYS;j++)
{
sumTemp+=temp[i][j];
sumHum+=humidity[i][j];
sumAQI+=aqi[i][j];
}
avgTemp[i]=sumTemp/DAYS;
avgHumidity[i]=sumHum/DAYS;
avgAQI[i]=sumAQI/DAYS;
}
}
void detectRiskZones(float temp[ZONES][DAYS],float humidity[ZONES][DAYS],int aqi[ZONES][DAYS],int riskDays[ZONES])
{
printf("Risk Detection Report(AQI>150 OR Temp>35 C OR Humidity>80%%)\n");
for(int i=0;i<ZONES;i++)
{
int count=0;
printf("Zone %d:\n",i+1);
printf("Triggered Days: ");
int hasRisk=0;
for(int j=0;j<DAYS;j++)
{
if(aqi[i][j]>150 || temp[i][j]>35.0 || humidity[i][j]>80.0)
{
count++;
printf("Day %d\n",j+1);
hasRisk=1;
}
}
if(!hasRisk)
{
printf("None\n");
}
printf("Total Risk Days Count: %d\n",count);
riskDays[i]=count;
}
}
void computeGreenIndex(float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES],float greenIndex[ZONES]){
for(int i=0;i<ZONES;i++)
{
float aqiScore=100.0-(avgAQI[i]/5.0);
if(aqiScore<0)
{
aqiScore=0.0;
}
float tempDiff=avgTemp[i]-25.0;
if(tempDiff<0)
{
tempDiff=-tempDiff;
}
float tempScore=100.0-(4.0*tempDiff);
if(tempScore<0)
{
tempScore=0.0;
}
float humDiff=avgHumidity[i]-50.0;
if(humDiff<0)
{
humDiff=-humDiff;
}
float humScore=100.0-(2.0*humDiff);
if(humScore<0)
{
humScore=0.0;
}
greenIndex[i]=(0.4*aqiScore)+(0.3*tempScore)+(0.3*humScore);
}
}
void displayRanking(float greenIndex[ZONES]){
printf("Zone Green Index and Ranking Report\n");
printf("Rank   | Zone  | Green Index       |\n");
for(int i=0;i<ZONES;i++)
{
int rank=1;
for(int j=0;j<ZONES;j++)
{
if(greenIndex[j]>greenIndex[i])
{
rank++;
}
}
printf("Rank:%d |Zone:%d | Green Index:%.2f |\n",rank,i+1,greenIndex[i]);
}
}
void displayRecommendations(float avgTemp[ZONES],float avgHumidity[ZONES],float avgAQI[ZONES],int riskDays[ZONES]){
printf("Practical Recommendations for Each Zone\n");
for(int i=0;i<ZONES;i++)
{
printf("Zone %d:\n",i+1);
printf("Averages:Temp=%.1f C,Humidity=%.1f%%,AQI=%.1f\n",avgTemp[i],avgHumidity[i],avgAQI[i]);
printf("Recommendation(s):\n");
int advised=0;
if(avgAQI[i]>150)
{
printf("Average AQI>150:Suggest reducing vehicle idling or improving ventilation.\n");
advised=1;
}
if(avgTemp[i]>35.0)
{
printf("Average Temperature>35 C:Suggest adding shade or green cover.\n");
advised=1;
}
if(avgHumidity[i]>80.0)
{
printf("Average Humidity>80%%:Suggest checking ventilation or stagnant-water sources.\n");
advised=1;
}
if(!advised)
{
if(riskDays[i]>0)
{
printf("Individual days flagged(%d risk days):Recommend reviewing those specific dates.\n",riskDays[i]);
}
else
{
printf("No significant risk detected:Recommend continuing monitoring.\n");
}
}
}
}

