#include<stdio.h>
int main(){
int english;
int telugu;
int maths;
int science;
int social;
int total_marks;
int average_marks;
float percentage;
printf("Enter English Marks");
scanf("%d",&english);
printf("%d\n",english);
printf("Enter Telugu Marks");
scanf("%d",&telugu);
printf("%d\n",telugu);
printf("Enter Maths Marks");
scanf("%d",&maths);
printf("%d\n",maths);
printf("Enter Science Marks");
scanf("%d",&science);
printf("%d\n",science);
printf("Enter Social Marks");
scanf("%d",&social);
printf("%d\n",social);
total_marks=english+telugu+maths+science+social;
printf("%d\n",total_marks);
average_marks=total_marks/5;
printf("%d\n",average_marks);
percentage=(total_marks/500.0)*100;
printf("%f\n",percentage);
return 0;
}

