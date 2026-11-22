A university wants to reduce water wastage across its campus. Develop a menu-driven C program that analyses seven days of water-consumption readings from five campus zones, detects unusual usage, identifies zones that exceed their daily targets, and recommends where conservation efforts should begin. Your solution must combine a two-dimensional array, user-defined functions, nested loops, conditional statements, and meaningful pointer operations.
Problem Statement:
The campus is divided into five zones: 1 Academic Block, 2 Hostel, 3 Library, 4 Cafeteria, and 5 Sports Complex. For each zone, the daily water consumption (in litres) is recorded for seven days. A daily usage target is also assigned to each zone. Build WATERWISE to turn these readings into a clear water-audit report and help the campus community identify where water-saving action is needed.
Start.
Read 5 Zones and 7 Days.
Use user-defined functions before starting the main() function.
Use do-while loop to execute and then check the condition is true or not.
Use conditional statements such as IF,ELSE-IF,ELSE to check whether the given condition is true or not.
Read the input data of each zone,target,and days(1-7) readings.
Display the read input data of each zone,target,and days(1-7) readings.
Calculate zonestats by using pointers for zoneUsage,total,average,peakUsage,peakDay.
Compute maxVal=*(zoneUsage+0).
Compute current=*(zoneUsage+day).
Compute sum+=current.
Compute maxDay=day+1.
Compute *total=sum.
Compute *average=(float)sum/DAYS.
Compute *peakUsage=maxVal.
Compute *peakDay=maxDay.
Detect water alerts by using pointers for zoneUsage,total,average,peakUsage,peakDay.
Compute excessSum+=(current-dailyTarget).
Compute prev=*(zoneUsage+(day-1)).
Compute *overLimitDays=overCount.
Compute *totalExcess=excessSum.
Compute *spikeDays=spikeCount.
Compute *alertDays=uniqueAlerts.
Generate the Audit Report for each zone which should contain total(L),avg(L),peak(Day),overDays,excess(L),,spikes,alerts.
Compute excessByZone[i]=totalExcess.
Compute overLimitByZone[i]=overLimitDays.
Compute spikeByZone[i]=spikeDays.
Compute alertByZone[i]=alertDays.
Print zone ranking by total excess.
Print highest total excess(L).
Print the ranking for the zones from highest to lowest along with the total excess(L).
Print the conservation action recommendations for each zone.
Stop.
