The university wants to understand environmental conditions across its campus and identify areas that may need attention. Develop a menu-driven C program that analyses seven days of temperature, humidity, and Air Quality Index (AQI) readings from five campus zones. Your program must turn the readings into a clear risk report, a Green Index ranking, and practical recommendations.
Problem Statement:The campus is divided into five zones: 1 Academic Block, 2 Hostel, 3 Library, 4 Cafeteria, and 5 Sports Area. For each zone, record three environmental parameters for seven days. Store the readings in three separate two-dimensional arrays. The system must analyse the data through user-defined functions and help you to identify where an environmental improvement could make the greatest difference.
Start.
Read 5 Zones and 7 Days.
Use do-while loop to execute and then check the condition is true or not.
Use Conditional statements such as IF,ELSE-IF,and ELSE to check whether the given condition is true or not.
Read input/update data of temperature,humidity,and AQI for all 5 zones and 7 days.
Display the input/update data for all 5 zones and 7 days.
Compute sumTemp+=temp[i][j].
Compute sumHum+=humidity[i][j].
Compute sumAQI+=aqi[i][j].
Compute avgTemp[i]=sumTempDAYS.
Compute avgHumidity[i]=sumHum/DAYS.
Compute avgAQI[i]=sumAQI/DAYS.
Print zone-wise averages of avg temperature,avg humidity,avg AQI.
Print risk detection report(AQI>150 OR Temp>35 C OR Humidity>80%)along with triggered days and total risk days count for each zone.
Print green index and ranking for each zone.
Print practical recommendations for each zone.
Stop.
