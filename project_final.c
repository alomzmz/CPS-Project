#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int year;
	char geo[50];
	char age[50];
	char sex[20];
	double value;
} Row;

typedef struct
{
	double avg;
	char province[50];
	char age[50];
} Average;

typedef struct
{
	double avg[7];
	char name[50];
	
} yearlyAvg;

int 
main(void)
{
	Row rows [250];
	Average province [4];
	yearlyAvg yAvg [5];
	yearlyAvg ageavg [5];
	
	FILE *in = fopen("statscan_diabetes.csv", "r");
	
	if(in == NULL){
		perror("Unable to load file");
		exit(1);
	}

	
	char line[200];
	char *sp;
	int i = 0;
		
	while(fgets(line, sizeof(line) , in) != NULL) {
		
		i++;
		if (i == 1)
		continue;
		
		sp = strtok(line, "\",");
		rows[i].year = atoi(sp);
		
		
		sp = strtok(NULL, "\",");
		strcpy(rows[i].geo, sp);
		
		strtok(NULL, ",");
		sp = strtok(NULL, "\",");
		strcpy(rows[i].age, sp);
		
		sp = strtok(NULL, "\",");
		strcpy(rows[i].sex, sp);
		
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		strtok(NULL, "\",");
		sp = strtok(NULL, "\",");
		rows[i].value = atof(sp);
		
	}
	fclose(in);

	
	char* ontario = "Ontario";
	double sum=0;
	double count=0;
	
	for(i = 1; i<= 211; i++){
		
		if (strcmp(ontario, rows[i].geo) == 0){
			
			if(rows[i].value != 0.00){
				
				sum = sum + rows[i].value;
				count++;
			}
		}
	}
	province[0].avg = sum/count;
	strcpy(province[0].province,ontario);
	
	
	printf("\nThe average rate of diabetes in %s is %.2lf%% \n", province[0].province, province[0].avg);
	
	char* quebec = "Quebec";
	sum = 0;
	count = 0;
	
	for(i = 1; i<= 211; i++){
		
		if (strcmp(quebec, rows[i].geo) == 0){
			
			if(rows[i].value != 0.00){
				
				sum = sum + rows[i].value;
				count++;
			}
		}
	}
	province[1].avg = sum/count;
	strcpy(province[1].province,quebec);
	
	
	printf("The average rate of diabetes in %s is %.2lf%% \n", province[1].province, province[1].avg);
	
	char* bc = "British Columbia";
	sum = 0;
	count = 0;
	
	for(i = 1; i<= 211; i++){
		
		if (strcmp(bc, rows[i].geo) == 0){
			
			if(rows[i].value != 0.00){
				
				sum = sum + rows[i].value;
				count++;
			}
		}
	}
	province[2].avg = sum/count;
	strcpy(province[2].province,bc);
	
	
	printf("The average rate of diabetes in %s is %.2lf%% \n", province[2].province, province[2].avg);
	
	char* alberta = "Alberta";
	sum = 0;
	count = 0;
	
	for(i = 1; i<= 211; i++){
		
		if (strcmp(alberta, rows[i].geo) == 0){
			
			if(rows[i].value != 0.00){
				
				sum = sum + rows[i].value;
				count++;
			}
		}
	}
	province[3].avg = sum/count;
	strcpy(province[3].province,alberta);
	
	
	printf("The average rate of diabetes in %s is %.2lf%% \n", province[3].province, province[3].avg);
	
	char* national = "Canada (excluding territories)";
	sum = 0;
	count = 0;
	double natavg;
	
	for(i = 1; i<= 211; i++){
		
		if (strcmp(national, rows[i].geo) == 0){
			
			if(rows[i].value != 0.00){
				
				sum = sum + rows[i].value;
				count++;
			}
		}
	}
	natavg = sum/count;
	
	printf("The average national rate of diabetes is %.2lf%% \n", natavg);
	
	printf("\n");
	
	for (int m=0;m<5;m++){
		for (int l=0;l<7;l++){
			yAvg[m].avg[l]=0;
		}
	}
		
	double c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,q1=0,q2=0,q3=0,q4=0,q5=0,q6=0,q7=0,o1=0,o2=0,o3=0,o4=0,o5=0,o6=0,o7=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0;
	for (int j=1;j<212;j++){
		
		if (strcmp(rows[j].geo,"Canada (excluding territories)")==0){
			if (rows[j].year == 2015){
				yAvg[0].avg[0] += rows[j].value;
				if (rows[j].value !=0){
					c1++;
				}
			}
			else if (rows[j].year == 2016){
				yAvg[0].avg[1] += rows[j].value;
				if (rows[j].value !=0){
					c2++;
				}
			}
			else if (rows[j].year == 2017){
				yAvg[0].avg[2] += rows[j].value;
				if (rows[j].value !=0){
					c3++;
				}
			}
			else if (rows[j].year == 2018){
				yAvg[0].avg[3] += rows[j].value;
				if (rows[j].value !=0){
					c4++;
				}
			}
			else if (rows[j].year == 2019){
				yAvg[0].avg[4] += rows[j].value;
				if (rows[j].value !=0){
					c5++;
				}
			}
			else if (rows[j].year == 2020){
				yAvg[0].avg[5] += rows[j].value;
				if (rows[j].value !=0){
					c6++;
				}
			}
			else if (rows[j].year == 2021){
				yAvg[0].avg[6] += rows[j].value;
				if (rows[j].value !=0){
					c7++;
				}
			}
		}
		else if (strcmp(rows[j].geo,"Quebec")==0){
			if (rows[j].year == 2015){
				yAvg[1].avg[0] += rows[j].value;
				if (rows[j].value !=0){
					q1++;
				}
			}
			else if (rows[j].year == 2016){
				yAvg[1].avg[1] += rows[j].value;
				if (rows[j].value !=0){
					q2++;
				}
			}
			else if (rows[j].year == 2017){
				yAvg[1].avg[2] += rows[j].value;
				if (rows[j].value !=0){
					q3++;
				}
			}
			else if (rows[j].year == 2018){
				yAvg[1].avg[3] += rows[j].value;
				if (rows[j].value !=0){
					q4++;
				}
			}
			else if (rows[j].year == 2019){
				yAvg[1].avg[4] += rows[j].value;
				if (rows[j].value !=0){
					q5++;
				}
			}
			else if (rows[j].year == 2020){
				yAvg[1].avg[5] += rows[j].value;
				if (rows[j].value !=0){
					q6++;
				}
			}
			else if (rows[j].year == 2021){
				yAvg[1].avg[6] += rows[j].value;
				if (rows[j].value !=0){
					q7++;
				}
			}
		}
		else if (strcmp(rows[j].geo,"Ontario")==0){
			if (rows[j].year == 2015){
				yAvg[2].avg[0] += rows[j].value;
				if (rows[j].value !=0){
					o1++;
				}
			}
			else if (rows[j].year == 2016){
				yAvg[2].avg[1] += rows[j].value;
				if (rows[j].value !=0){
					o2++;
				}
			}
			else if (rows[j].year == 2017){
				yAvg[2].avg[2] += rows[j].value;
				if (rows[j].value !=0){
					o3++;
				}
			}
			else if (rows[j].year == 2018){
				yAvg[2].avg[3] += rows[j].value;
				if (rows[j].value !=0){
					o4++;
				}
			}
			else if (rows[j].year == 2019){
				yAvg[2].avg[4] += rows[j].value;
				if (rows[j].value !=0){
					o5++;
				}
			}
			else if (rows[j].year == 2020){
				yAvg[2].avg[5] += rows[j].value;
				if (rows[j].value !=0){
					o6++;
				}
			}
			else if (rows[j].year == 2021){
				yAvg[2].avg[6] += rows[j].value;
				if (rows[j].value !=0){
					o7++;
				}
			}
		}
		else if (strcmp(rows[j].geo,"Alberta")==0){
			if (rows[j].year == 2015){
				yAvg[3].avg[0] += rows[j].value;
				if (rows[j].value !=0){
					a1++;
				}
			}
			else if (rows[j].year == 2016){
				yAvg[3].avg[1] += rows[j].value;
				if (rows[j].value !=0){
					a2++;
				}
			}
			else if (rows[j].year == 2017){
				yAvg[3].avg[2] += rows[j].value;
				if (rows[j].value !=0){
					a3++;
				}
			}
			else if (rows[j].year == 2018){
				yAvg[3].avg[3] += rows[j].value;
				if (rows[j].value !=0){
					a4++;
				}
			}
			else if (rows[j].year == 2019){
				yAvg[3].avg[4] += rows[j].value;
				if (rows[j].value !=0){
					a5++;
				}
			}
			else if (rows[j].year == 2020){
				yAvg[3].avg[5] += rows[j].value;
				if (rows[j].value !=0){
					a6++;
				}
			}
			else if (rows[j].year == 2021){
				yAvg[3].avg[6] += rows[j].value;
				if (rows[j].value !=0){
					a7++;
				}
			}
		}
		else if (strcmp(rows[j].geo,"British Columbia")==0){
			if (rows[j].year == 2015){
				yAvg[4].avg[0] += rows[j].value;
				if (rows[j].value !=0){
					b1++;
				}
			}
			else if (rows[j].year == 2016){
				yAvg[4].avg[1] += rows[j].value;
				if (rows[j].value !=0){
					b2++;
				}
			}
			else if (rows[j].year == 2017){
				yAvg[4].avg[2] += rows[j].value;
				if (rows[j].value !=0){
					b3++;
				}
			}
			else if (rows[j].year == 2018){
				yAvg[4].avg[3] += rows[j].value;
				if (rows[j].value !=0){
					b4++;
				}
			}
			else if (rows[j].year == 2019){
				yAvg[4].avg[4] += rows[j].value;
				if (rows[j].value !=0){
					b5++;
				}
			}
			else if (rows[j].year == 2020){
				yAvg[4].avg[5] += rows[j].value;
				if (rows[j].value !=0){
					b6++;
				}
			}
			else if (rows[j].year == 2021){
				yAvg[4].avg[6] += rows[j].value;
				if (rows[j].value !=0){
					b7++;
				}
			}
		}
	}
	yAvg[0].avg[0]=yAvg[0].avg[0]/c1;
	yAvg[0].avg[1]=yAvg[0].avg[1]/c2;
	yAvg[0].avg[2]=yAvg[0].avg[2]/c3;
	yAvg[0].avg[3]=yAvg[0].avg[3]/c4;
	yAvg[0].avg[4]=yAvg[0].avg[4]/c5;
	yAvg[0].avg[5]=yAvg[0].avg[5]/c6;
	yAvg[0].avg[6]=yAvg[0].avg[6]/c7;
	
	yAvg[1].avg[0]=yAvg[1].avg[0]/q1;
	yAvg[1].avg[1]=yAvg[1].avg[1]/q2;
	yAvg[1].avg[2]=yAvg[1].avg[2]/q3;
	yAvg[1].avg[3]=yAvg[1].avg[3]/q4;
	yAvg[1].avg[4]=yAvg[1].avg[4]/q5;
	yAvg[1].avg[5]=yAvg[1].avg[5]/q6;
	yAvg[1].avg[6]=yAvg[1].avg[6]/q7;
	
	yAvg[2].avg[0]=yAvg[2].avg[0]/o1;
	yAvg[2].avg[1]=yAvg[2].avg[1]/o2;
	yAvg[2].avg[2]=yAvg[2].avg[2]/o3;
	yAvg[2].avg[3]=yAvg[2].avg[3]/o4;
	yAvg[2].avg[4]=yAvg[2].avg[4]/o5;
	yAvg[2].avg[5]=yAvg[2].avg[5]/o6;
	yAvg[2].avg[6]=yAvg[2].avg[6]/o7;
	
	yAvg[3].avg[0]=yAvg[3].avg[0]/a1;
	yAvg[3].avg[1]=yAvg[3].avg[1]/a1;
	yAvg[3].avg[2]=yAvg[3].avg[2]/a1;
	yAvg[3].avg[3]=yAvg[3].avg[3]/a1;
	yAvg[3].avg[4]=yAvg[3].avg[4]/a1;
	yAvg[3].avg[5]=yAvg[3].avg[5]/a1;
	yAvg[3].avg[6]=yAvg[3].avg[6]/a1;
	
	yAvg[4].avg[0]=yAvg[4].avg[0]/b1;
	yAvg[4].avg[1]=yAvg[4].avg[1]/b1;
	yAvg[4].avg[2]=yAvg[4].avg[2]/b1;
	yAvg[4].avg[3]=yAvg[4].avg[3]/b1;
	yAvg[4].avg[4]=yAvg[4].avg[4]/b1;
	yAvg[4].avg[5]=yAvg[4].avg[5]/b1;
	yAvg[4].avg[6]=yAvg[4].avg[6]/b1;
	
	
	
	printf("Yearly Averages of Canada (excluding territories): \n");
	printf("2015: %0.2lf %%\n" ,((yAvg[0].avg[0])));
	printf("2016: %0.2lf %%\n" ,((yAvg[0].avg[1])));
	printf("2017: %0.2lf %%\n" ,((yAvg[0].avg[2])));
	printf("2018: %0.2lf %%\n" ,((yAvg[0].avg[3])));
	printf("2019: %0.2lf %%\n" ,((yAvg[0].avg[4])));
	printf("2020: %0.2lf %%\n" ,((yAvg[0].avg[5])));
	printf("2021: %0.2lf %%\n\n" ,((yAvg[0].avg[6])));
	
	printf("Yearly Averages of Quebec: \n");
	printf("2015: %0.2lf %%\n" ,((yAvg[1].avg[0])));
	printf("2016: %0.2lf %%\n" ,((yAvg[1].avg[1])));
	printf("2017: %0.2lf %%\n" ,((yAvg[1].avg[2])));
	printf("2018: %0.2lf %%\n" ,((yAvg[1].avg[3])));
	printf("2019: %0.2lf %%\n" ,((yAvg[1].avg[4])));
	printf("2020: %0.2lf %%\n" ,((yAvg[1].avg[5])));
	printf("2021: %0.2lf %%\n\n" ,((yAvg[1].avg[6])));
	
	printf("Yearly Averages of Ontario: \n");
	printf("2015: %0.2lf %%\n" ,((yAvg[2].avg[0])));
	printf("2016: %0.2lf %%\n" ,((yAvg[2].avg[1])));
	printf("2017: %0.2lf %%\n" ,((yAvg[2].avg[2])));
	printf("2018: %0.2lf %%\n" ,((yAvg[2].avg[3])));
	printf("2019: %0.2lf %%\n" ,((yAvg[2].avg[4])));
	printf("2020: %0.2lf %%\n" ,((yAvg[2].avg[5])));
	printf("2021: %0.2lf %%\n\n" ,((yAvg[2].avg[6])));
	
	printf("Yearly Averages of Alberta: \n");
	printf("2015: %0.2lf %%\n" ,((yAvg[3].avg[0])));
	printf("2016: %0.2lf %%\n" ,((yAvg[3].avg[1])));
	printf("2017: %0.2lf %%\n" ,((yAvg[3].avg[2])));
	printf("2018: %0.2lf %%\n" ,((yAvg[3].avg[3])));
	printf("2019: %0.2lf %%\n" ,((yAvg[3].avg[4])));
	printf("2020: %0.2lf %%\n" ,((yAvg[3].avg[5])));
	printf("2021: %0.2lf %%\n\n" ,((yAvg[3].avg[6])));
	
	printf("Yearly Averages of British Columbia: \n");
	printf("2015: %0.2lf %%\n" ,((yAvg[4].avg[0])));
	printf("2016: %0.2lf %%\n" ,((yAvg[4].avg[1])));
	printf("2017: %0.2lf %%\n" ,((yAvg[4].avg[2])));
	printf("2018: %0.2lf %%\n" ,((yAvg[4].avg[3])));
	printf("2019: %0.2lf %%\n" ,((yAvg[4].avg[4])));
	printf("2020: %0.2lf %%\n" ,((yAvg[4].avg[5])));
	printf("2021: %0.2lf %%\n\n" ,((yAvg[4].avg[6])));
	
	for (int m=0;m<5;m++){
		for (int l=0;l<7;l++){
			ageavg[m].avg[l]=0;
		}
	}
	
	c1 = c2 = c3 = q1 = q2 = q3 = o1 = o2 = o3 = a1 = a2 = a3 = b1 = b2 = b3 = 0;
	
	
	for (int j=1;j<212;j++){
		
		if (strcmp(rows[j].geo,"Canada (excluding territories)")==0){
			if (strcmp(rows[j].age,"35 to 49 years") ==0){
				ageavg[0].avg[0] += rows[j].value;
				if(rows[j].value !=0){
					c1++;
				}
			}
			else if (strcmp(rows[j].age,"50 to 64 years")){
				ageavg[0].avg[1] += rows[j].value;
				if(rows[j].value !=0){
					c2++;
				}
			}
			else if (strcmp(rows[j].age,"65 years and over")){
				ageavg[0].avg[2] += rows[j].value;
				if(rows[j].value !=0){
					c3++;
				}
			}
		}
		
		if (strcmp(rows[j].geo,"Quebec")==0){
			if (strcmp(rows[j].age,"35 to 49 years") ==0){
				ageavg[1].avg[0] += rows[j].value;
				if(rows[j].value !=0){
					q1++;
				}
			}
			else if (strcmp(rows[j].age,"50 to 64 years")){
				ageavg[1].avg[1] += rows[j].value;
				if(rows[j].value !=0){
					q2++;
				}
			}
			else if (strcmp(rows[j].age,"65 years and over")){
				ageavg[1].avg[2] += rows[j].value;
				if(rows[j].value !=0){
					q3++;
				}
			}
		}
		
		if (strcmp(rows[j].geo,"Ontario")==0){
			if (strcmp(rows[j].age,"35 to 49 years") ==0){
				ageavg[2].avg[0] += rows[j].value;
				if(rows[j].value !=0){
					o1++;
				}
			}
			else if (strcmp(rows[j].age,"50 to 64 years")){
				ageavg[2].avg[1] += rows[j].value;
				if(rows[j].value !=0){
					o2++;
				}
			}
			else if (strcmp(rows[j].age,"65 years and over")){
				ageavg[2].avg[2] += rows[j].value;
				if(rows[j].value !=0){
					o3++;
				}
			}
		}
		
		if (strcmp(rows[j].geo,"Alberta")==0){
			if (strcmp(rows[j].age,"35 to 49 years") ==0){
				ageavg[3].avg[0] += rows[j].value;
				if(rows[j].value !=0){
					a1++;
				}
			}
			else if (strcmp(rows[j].age,"50 to 64 years")){
				ageavg[3].avg[1] += rows[j].value;
				if(rows[j].value !=0){
					a2++;
				}
			}
			else if (strcmp(rows[j].age,"65 years and over")){
				ageavg[3].avg[2] += rows[j].value;
				if(rows[j].value !=0){
					a3++;
				}
			}
		}
		
		if (strcmp(rows[j].geo,"British Columbia")==0){
			if (strcmp(rows[j].age,"35 to 49 years") ==0){
				ageavg[4].avg[0] += rows[j].value;
				if(rows[j].value !=0){
					b1++;
				}
			}
			else if (strcmp(rows[j].age,"50 to 64 years")){
				ageavg[4].avg[1] += rows[j].value;
				if(rows[j].value !=0){
					o2++;
				}
			}
			else if (strcmp(rows[j].age,"65 years and over")){
				ageavg[4].avg[2] += rows[j].value;
				if(rows[j].value !=0){
					o3++;
				}
			}
		}
	}
	
	ageavg[0].avg[0]=ageavg[0].avg[0]/c1;
	ageavg[0].avg[1]=ageavg[0].avg[1]/c2;
	ageavg[0].avg[2]=ageavg[0].avg[2]/c3;
	
	ageavg[1].avg[0]=ageavg[1].avg[0]/q1;
	ageavg[1].avg[1]=ageavg[1].avg[1]/q2;
	ageavg[1].avg[2]=ageavg[1].avg[2]/q3;
	
	ageavg[2].avg[0]=ageavg[2].avg[0]/o1;
	ageavg[2].avg[1]=ageavg[2].avg[1]/o2;
	ageavg[2].avg[2]=ageavg[2].avg[2]/o3;
	
	ageavg[3].avg[0]=ageavg[3].avg[0]/a1;
	ageavg[3].avg[1]=ageavg[3].avg[1]/a1;
	ageavg[3].avg[2]=ageavg[3].avg[2]/a1;
	
	ageavg[4].avg[0]=ageavg[4].avg[0]/b1;
	ageavg[4].avg[1]=ageavg[4].avg[1]/b1;
	ageavg[4].avg[2]=ageavg[4].avg[2]/b1;
	
	printf("National age group averages:\n");
	printf("35 to 49 years: %0.2lf %%\n" ,((ageavg[0].avg[0])));
	printf("50 to 64 years: %0.2lf %%\n" ,((ageavg[0].avg[1])));
	printf("65 years and over: %0.2lf %%\n\n" ,((ageavg[0].avg[2])));
	
	printf("Age group averages in Quebec:\n");
	printf("35 to 49 years: %0.2lf %%\n" ,((ageavg[1].avg[0])));
	printf("50 to 64 years: %0.2lf %%\n" ,((ageavg[1].avg[1])));
	printf("65 years and over: %0.2lf %%\n\n" ,((ageavg[1].avg[2])));
	
	printf("Age group averages in Ontario:\n");
	printf("35 to 49 years: %0.2lf %%\n" ,((ageavg[2].avg[0])));
	printf("50 to 64 years: %0.2lf %%\n" ,((ageavg[2].avg[1])));
	printf("65 years and over: %0.2lf %%\n\n" ,((ageavg[2].avg[2])));
	
	printf("Age group averages in Alberta:\n");
	printf("35 to 49 years: %0.2lf %%\n" ,((ageavg[3].avg[0])));
	printf("50 to 64 years: %0.2lf %%\n" ,((ageavg[3].avg[1])));
	printf("65 years and over: %0.2lf %%\n\n" ,((ageavg[3].avg[2])));
	
	printf("Age group averages in British Columbia:\n");
	printf("35 to 49 years: %0.2lf %%\n" ,((ageavg[4].avg[0])));
	printf("50 to 64 years: %0.2lf %%\n" ,((ageavg[4].avg[1])));
	printf("65 years and over: %0.2lf %%\n\n" ,((ageavg[4].avg[2])));
	
	// question 2
	
	double rmax, rmin;
	int maxpoint, minpoint;
	
	rmin = province[0].avg;
	minpoint = 0;
	
	for(i=0; i<4; i++)
	{
		if (rmin>province[i].avg){
			rmin = province[i].avg;
			minpoint = i;
		}
	}
	
	rmax = province[0].avg;
	maxpoint = 0;
	
	for(i=0; i<4; i++)
	{
		if (province[i].avg>rmax){
			rmax = province[i].avg;
			maxpoint = i;
		}
	}
	
	printf("The province with the highest average is %s\n", province[maxpoint].province);
	printf("The province with the lowest average is %s\n\n", province[minpoint].province);
	
	
	// question 3
	
	for(i=0;i<4;i++){
		if(province[i].avg > natavg){
			printf("%s has a higher average than the national average\n", province[i].province);
		}
		else {
			printf("%s has a lower average than the national average\n", province[i].province);
		}
	}
	
	printf("\n");
	
	// question 4
	
	
	double quebecMax=yAvg[1].avg[0];
	int arrCQ=0;
	for (int k=1;k<7;k++){
		if (quebecMax==yAvg[1].avg[k]){
			arrCQ++;
		}
		if (quebecMax<yAvg[1].avg[k]){
			quebecMax=yAvg[1].avg[k];
		}
	}
	int quebecMaxtie[arrCQ];
	int w=arrCQ;
	for (int u=0;u<7;u++){
		if (quebecMax==yAvg[1].avg[u]){
			 quebecMaxtie[w]=u;
			 w=w-1;
		}
	}
	int largestQ=quebecMaxtie[0];
	printf("\nThe largest Yearly Averages in Quebec are: \n");
	for (int q=0;q<=arrCQ;q++){
		if (quebecMaxtie[q]==0){
			printf("2015: ");
		}
		else if (quebecMaxtie[q]==1){
			printf("2016: ");
		}
		else if (quebecMaxtie[q]==2){
			printf("2017: ");
		}
		else if (quebecMaxtie[q]==3){
			printf("2018: ");
		}
		else if (quebecMaxtie[q]==4){
			printf("2019: ");
		}
		else if (quebecMaxtie[q]==5){
			printf("2020: ");
		}
		else if (quebecMaxtie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n",(yAvg[1].avg[quebecMaxtie[q]]));
	}
	
	
	
	
	double quebecMin=yAvg[1].avg[0];
	arrCQ=0;
	for (int k=1;k<7;k++){
		if (quebecMin==yAvg[1].avg[k]){
			arrCQ++;
		}
		if (quebecMin>yAvg[1].avg[k]){
			quebecMin=yAvg[1].avg[k];
		}
	}
	int quebecMintie[arrCQ];
	int o=arrCQ;
	for (int u=0;u<7;u++){
		if (quebecMin==yAvg[1].avg[u]){
			 quebecMintie[o]=u;
			 o=o-1;
		}
	}
	int lowestQ=quebecMintie[0];
	printf("\nThe lowest Yearly Averages in Quebec are: \n");
	for (int q=0;q<=arrCQ;q++){
		if (quebecMintie[q]==0){
			printf("2015: ");
		}
		else if (quebecMintie[q]==1){
			printf("2016: ");
		}
		else if (quebecMintie[q]==2){
			printf("2017: ");
		}
		else if (quebecMintie[q]==3){
			printf("2018: ");
		}
		else if (quebecMintie[q]==4){
			printf("2019: ");
		}
		else if (quebecMintie[q]==5){
			printf("2020: ");
		}
		else if (quebecMintie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n\n",(yAvg[1].avg[quebecMintie[q]]));
	}
	
	
	
	
	double ontarioMax=yAvg[2].avg[0];
	int arrCO=0;
	for (int k=1;k<7;k++){
		if (ontarioMax==yAvg[2].avg[k]){
			arrCO++;
		}
		if (ontarioMax<yAvg[2].avg[k]){
			ontarioMax=yAvg[2].avg[k];
		}
	}
	int ontarioMaxtie[arrCO];
	int r=arrCO;
	for (int u=0;u<7;u++){
		if (ontarioMax==yAvg[2].avg[u]){
			 ontarioMaxtie[r]=u;
			 r=r-1;
		}
	}
	int largestO=ontarioMaxtie[0];
	printf("\nThe largest Yearly Averages in Ontario are: \n");
	for (int q=0;q<=arrCO;q++){
		if (ontarioMaxtie[q]==0){
			printf("2015: ");
		}
		else if (ontarioMaxtie[q]==1){
			printf("2016: ");
		}
		else if (ontarioMaxtie[q]==2){
			printf("2017: ");
		}
		else if (ontarioMaxtie[q]==3){
			printf("2018: ");
		}
		else if (ontarioMaxtie[q]==4){
			printf("2019: ");
		}
		else if (ontarioMaxtie[q]==5){
			printf("2020: ");
		}
		else if (ontarioMaxtie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n",(yAvg[2].avg[ontarioMaxtie[q]]));
	}
	
	
	
	double ontarioMin=yAvg[2].avg[0];
	arrCO=0;
	for (int k=1;k<7;k++){
		if (ontarioMin==yAvg[2].avg[k]){
			arrCO++;
		}
		if (ontarioMin>yAvg[2].avg[k]){
			ontarioMin=yAvg[2].avg[k];
		}
	}
	int ontarioMintie[arrCO];
	int s=arrCO;
	for (int u=0;u<7;u++){
		if (ontarioMin==yAvg[2].avg[u]){
			 ontarioMintie[s]=u;
			 s=s-1;
		}
	}
	int lowestO=ontarioMintie[0];
	printf("\nThe lowest Yearly Averages in Ontario are: \n");
	for (int q=0;q<=arrCO;q++){
		if (ontarioMintie[q]==0){
			printf("2015: ");
		}
		else if (ontarioMintie[q]==1){
			printf("2016: ");
		}
		else if (ontarioMintie[q]==2){
			printf("2017: ");
		}
		else if (ontarioMintie[q]==3){
			printf("2018: ");
		}
		else if (ontarioMintie[q]==4){
			printf("2019: ");
		}
		else if (ontarioMintie[q]==5){
			printf("2020: ");
		}
		else if (ontarioMintie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n\n",(yAvg[2].avg[ontarioMintie[q]]));
	}
	
	
	
	double albertaMax=yAvg[3].avg[0];
	int arrCA=0;
	for (int k=1;k<7;k++){
		if (albertaMax==yAvg[3].avg[k]){
			arrCA++;
		}
		if (albertaMax<yAvg[3].avg[k]){
			albertaMax=yAvg[3].avg[k];
		}
	}
	int albertaMaxtie[arrCA];
	int a=arrCA;
	for (int u=0;u<7;u++){
		if (albertaMax==yAvg[3].avg[u]){
			 albertaMaxtie[a]=u;
			 a=a-1;
		}
	}
	
	printf("\nThe largest Yearly Averages in Alberta are: \n");
	for (int q=0;q<=arrCA;q++){
		if (albertaMaxtie[q]==0){
			printf("2015: ");
		}
		else if (albertaMaxtie[q]==1){
			printf("2016: ");
		}
		else if (albertaMaxtie[q]==2){
			printf("2017: ");
		}
		else if (albertaMaxtie[q]==3){
			printf("2018: ");
		}
		else if (albertaMaxtie[q]==4){
			printf("2019: ");
		}
		else if (albertaMaxtie[q]==5){
			printf("2020: ");
		}
		else if (albertaMaxtie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n",(yAvg[3].avg[albertaMaxtie[q]]));
	}
	
	int largestA=albertaMaxtie[0];
	
	double albertaMin=yAvg[3].avg[0];
	arrCA=0;
	for (int k=1;k<7;k++){
		if (albertaMin==yAvg[3].avg[k]){
			arrCA++;
		}
		if (albertaMin>yAvg[3].avg[k]){
			albertaMin=yAvg[3].avg[k];
		}
	}
	int albertaMintie[arrCA];
	int q=arrCA;
	for (int u=0;u<7;u++){
		if (albertaMin==yAvg[3].avg[u]){
			 albertaMintie[q]=u;
			 q=q-1;
		}
	}
	
	printf("\nThe lowest Yearly Averages in Alberta are: \n");
	for (int q=0;q<=arrCA;q++){
		if (albertaMintie[q]==0){
			printf("2015: ");
		}
		else if (albertaMintie[q]==1){
			printf("2016: ");
		}
		else if (albertaMintie[q]==2){
			printf("2017: ");
		}
		else if (albertaMintie[q]==3){
			printf("2018: ");
		}
		else if (albertaMintie[q]==4){
			printf("2019: ");
		}
		else if (albertaMintie[q]==5){
			printf("2020: ");
		}
		else if (albertaMintie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n\n",(yAvg[3].avg[albertaMintie[q]]));
	}
	
	int lowestA=albertaMintie[0];
	
	
	double bcMax=yAvg[4].avg[0];
	int arrCB=0;
	for (int k=1;k<7;k++){
		if (bcMax==yAvg[4].avg[k]){
			arrCB++;
		}
		if (bcMax<yAvg[4].avg[k]){
			bcMax=yAvg[4].avg[k];
		}
	}
	
	int bcMaxtie[arrCB];
	int t=arrCB;
	for (int u=0;u<7;u++){
		if (bcMax==yAvg[4].avg[u]){
			 bcMaxtie[t]=u;
			 t=t-1;
		}
	}
	int largestB=bcMaxtie[0];
	
	printf("\nThe largest Yearly Averages in British Columbia are:\n");
	for (int q=0;q<=arrCB;q++){
		if (bcMaxtie[q]==0){
			printf("2015: ");
		}
		else if (bcMaxtie[q]==1){
			printf("2016: ");
		}
		else if (bcMaxtie[q]==2){
			printf("2017: ");
		}
		else if (bcMaxtie[q]==3){
			printf("2018: ");
		}
		else if (bcMaxtie[q]==4){
			printf("2019: ");
		}
		else if (bcMaxtie[q]==5){
			printf("2020: ");
		}
		else if (bcMaxtie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n",(yAvg[4].avg[bcMaxtie[q]]));
	}
	
	
	double bcMin=yAvg[4].avg[0];
	arrCB=0;
	for (int k=1;k<7;k++){
		if (bcMin==yAvg[4].avg[k]){
			arrCB++;
		}
		if (bcMin>yAvg[4].avg[k]){
			bcMin=yAvg[4].avg[k];
		}
	}
	
	int bcMintie[arrCB];
	int p=arrCB;
	for (int u=0;u<7;u++){
		if (bcMin==yAvg[4].avg[u]){
			 bcMintie[p]=u;
			 p=p-1;
		}
	}
	int lowestB=bcMintie[0];
	
	printf("\nThe lowest Yearly Averages in British Columbia are:\n");
	for (int q=0;q<=arrCB;q++){
		if (bcMintie[q]==0){
			printf("2015: ");
		}
		else if (bcMintie[q]==1){
			printf("2016: ");
		}
		else if (bcMintie[q]==2){
			printf("2017: ");
		}
		else if (bcMintie[q]==3){
			printf("2018: ");
		}
		else if (bcMintie[q]==4){
			printf("2019: ");
		}
		else if (bcMintie[q]==5){
			printf("2020: ");
		}
		else if (bcMintie[q]==6){
			printf("2021: ");
		}
		printf("%.2lf %%\n\n",(yAvg[4].avg[bcMintie[q]]));
	}
	
	double maxProvince[4];
	maxProvince[0]=yAvg[1].avg[largestQ];
	maxProvince[1]=yAvg[2].avg[largestO];
	maxProvince[2]=yAvg[3].avg[largestA];
	maxProvince[3]=yAvg[4].avg[largestB];
	
	double provMax=maxProvince[0];
	int maxprovID=0;
	for (int k=1;k<4;k++){
		if (provMax<maxProvince[k]){
			provMax=maxProvince[k];
			maxprovID=k;
		}
	}

	printf("\nThe Province with the largest yearly average is:\n");
	if (maxprovID==0){
		printf("Quebec: %.2lf %%\n",maxProvince[0]);
	}
	else if (maxprovID==1){
		printf("Ontario: %.2lf %%\n",maxProvince[1]);
	}
	else if (maxprovID==2){
		printf("Alberta: %.2lf %%\n",maxProvince[2]);
	}
	else if (maxprovID==3){
		printf("British Columbia: %.2lf %%\n",maxProvince[3]);
	}
	
	
	
	double minProvince[4];
	minProvince[0]=yAvg[1].avg[lowestQ];
	minProvince[1]=yAvg[2].avg[lowestO];
	minProvince[2]=yAvg[3].avg[lowestA];
	minProvince[3]=yAvg[4].avg[lowestB];
	
	double provMin=minProvince[0];
	int minprovID=0;
	for (int k=1;k<4;k++){
		if (provMin>minProvince[k]){
			provMin=minProvince[k];
			minprovID=k;
		}
	}

	printf("\nThe Province with the lowest yearly average is:\n");
	if (minprovID==0){
		printf("Quebec: %.2lf %%\n",minProvince[0]);
	}
	else if (minprovID==1){
		printf("Ontario: %.2lf %%\n",minProvince[1]);
	}
	else if (minprovID==2){
		printf("Alberta: %.2lf %%\n",minProvince[2]);
	}
	else if (minprovID==3){
		printf("British Columbia: %.2lf %%\n\n\n",minProvince[3]);
	}
	
	
	
	
	double overallYearAverage[7];
	double overallProvinceAverage[5];
	for (int i=0;i<7;i++){
		overallYearAverage[i]=0;
	}
	for (int i=0;i<5;i++){
		overallProvinceAverage[i]=0;
	}
	
	double qC=0,oC=0,aC=0,bC=0;
	for (int i=0;i<7;i++){
		overallProvinceAverage[0]+=yAvg[1].avg[i];
		overallProvinceAverage[1]+=yAvg[2].avg[i];
		overallProvinceAverage[2]+=yAvg[3].avg[i];
		overallProvinceAverage[3]+=yAvg[4].avg[i];
		if (yAvg[1].avg[i]!=0){
			qC++;
		}
		if (yAvg[2].avg[i]!=0){
			oC++;
		}
		if (yAvg[3].avg[i]!=0){
			aC++;
		}
		if (yAvg[4].avg[i]!=0){
			bC++;
		}
	}
	
	overallProvinceAverage[0]=overallProvinceAverage[0]/qC;
	overallProvinceAverage[1]=overallProvinceAverage[1]/oC;
	overallProvinceAverage[2]=overallProvinceAverage[2]/aC;
	overallProvinceAverage[3]=overallProvinceAverage[3]/bC;
	
	
	
	
	
	
	double overallprovinceMax=overallProvinceAverage[0];
	int arrCOP=0;
	for (int k=1;k<4;k++){
		if (overallprovinceMax==overallProvinceAverage[k]){
			arrCOP++;
		}
		if (overallprovinceMax<overallProvinceAverage[k]){
			overallprovinceMax=overallProvinceAverage[k];
		}
	}
	
	int OPMaxtie[arrCOP];
	int f=arrCOP;
	for (int u=0;u<4;u++){
		if (overallprovinceMax==overallProvinceAverage[u]){
			 OPMaxtie[f]=u;
			 f=f-1;
		}
	}
	
	printf("\nThe Provinces with the largest overall average are:\n");
	for (int q=0;q<=arrCOP;q++){
		if (OPMaxtie[q]==0){
			printf ("Quebec: %.2lf %%\n",overallProvinceAverage[0]);
		}
		else if (OPMaxtie[q]==1){
			printf ("Ontario: %.2lf %%\n",overallProvinceAverage[1]);
		}
		else if (OPMaxtie[q]==2){
			printf ("Alberta: %.2lf %%\n",overallProvinceAverage[2]);
		}
		else if (OPMaxtie[q]==3){
			printf ("British Columbia: %.2lf %%\n",overallProvinceAverage[3]);
		}
	}
	
	
	
	
	double overallprovinceMin=overallProvinceAverage[0];
	arrCOP=0;
	for (int k=1;k<4;k++){
		if (overallprovinceMin==overallProvinceAverage[k]){
			arrCOP++;
		}
		if (overallprovinceMin>overallProvinceAverage[k]){
			overallprovinceMin=overallProvinceAverage[k];
		}
	}
	
	int OPMintie[arrCOP];
	int x=arrCOP;
	for (int u=0;u<4;u++){
		if (overallprovinceMin==overallProvinceAverage[u]){
			 OPMintie[x]=u;
			 x=x-1;
		}
	}
	
	printf("\nThe Provinces with the lowest overall average are:\n");
	for (int q=0;q<=arrCOP;q++){
		if (OPMintie[q]==0){
			printf ("Quebec: %.2lf %%\n",overallProvinceAverage[0]);
		}
		else if (OPMintie[q]==1){
			printf ("Ontario: %.2lf %%\n",overallProvinceAverage[1]);
		}
		else if (OPMintie[q]==2){
			printf ("Alberta: %.2lf %%\n",overallProvinceAverage[2]);
		}
		else if (OPMintie[q]==3){
			printf ("British Columbia: %.2lf %%\n\n",overallProvinceAverage[3]);
		}
	}
	
	
	
	
	double c15=0,c16=0,c17=0,c18=0,c19=0,c20=0,c21=0;
	for (int i=1;i<4;i++){
		overallYearAverage[0]+=yAvg[i].avg[0];
		overallYearAverage[1]+=yAvg[i].avg[1];
		overallYearAverage[2]+=yAvg[i].avg[2];
		overallYearAverage[3]+=yAvg[i].avg[3];
		overallYearAverage[4]+=yAvg[i].avg[4];
		overallYearAverage[5]+=yAvg[i].avg[5];
		overallYearAverage[6]+=yAvg[i].avg[6];
		if (yAvg[i].avg[0]!=0){
			c15++;
		}
		if (yAvg[i].avg[1]!=0){
			c16++;
		}
		if (yAvg[i].avg[2]!=0){
			c17++;
		}
		if (yAvg[i].avg[3]!=0){
			c18++;
		}
		if (yAvg[i].avg[4]!=0){
			c19++;
		}
		if (yAvg[i].avg[5]!=0){
			c20++;
		}
		if (yAvg[i].avg[6]!=0){
			c21++;
		}
		
	}
	overallYearAverage[0]=overallYearAverage[0]/c15;
	overallYearAverage[1]=overallYearAverage[1]/c16;
	overallYearAverage[2]=overallYearAverage[2]/c17;
	overallYearAverage[3]=overallYearAverage[3]/c18;
	overallYearAverage[4]=overallYearAverage[4]/c19;
	overallYearAverage[5]=overallYearAverage[5]/c20;
	overallYearAverage[6]=overallYearAverage[6]/c21;
	
	double overallyearMax=overallYearAverage[0];
	int arrCYP=0;
	for (int k=1;k<7;k++){
		if (overallyearMax==overallYearAverage[k]){
			arrCYP++;
		}
		if (overallyearMax<overallYearAverage[k]){
			overallyearMax=overallYearAverage[k];
		}
	}
	
	int OYMaxtie[arrCYP];
	int z=arrCYP;
	for (int u=0;u<4;u++){
		if (overallyearMax==overallYearAverage[u]){
			 OYMaxtie[z]=u;
			 z=z-1;
		}
	}
	
	
	
	printf("\nThe years with the largest overall average are:\n");
	for (int q=0;q<=arrCYP;q++){
		if (OYMaxtie[q]==0){
			printf ("2015: %.2lf %%\n",overallYearAverage[0]);
		}
		else if (OYMaxtie[q]==1){
			printf ("2016: %.2lf %%\n",overallYearAverage[1]);
		}
		else if (OYMaxtie[q]==2){
			printf ("2017: %.2lf %%\n",overallYearAverage[2]);
		}
		else if (OYMaxtie[q]==3){
			printf ("2018: %.2lf %%\n",overallYearAverage[3]);
		}
		else if (OYMaxtie[q]==4){
			printf ("2019: %.2lf %%\n",overallYearAverage[4]);
		}
		else if (OYMaxtie[q]==5){
			printf ("2020: %.2lf %%\n",overallYearAverage[5]);
		}
		else if (OYMaxtie[q]==6){
			printf ("2021: %.2lf %%\n",overallYearAverage[6]);
		}
		
	}
	
	double overallyearMin=overallYearAverage[0];
	arrCYP=0;
	for (int k=1;k<7;k++){
		if (overallyearMin==overallYearAverage[k]){
			arrCYP++;
		}
		if (overallyearMin>overallYearAverage[k]){
			overallyearMin=overallYearAverage[k];
		}
	}
	
	int OYMintie[arrCYP];
	int d=arrCYP;
	for (int u=0;u<4;u++){
		if (overallyearMin==overallYearAverage[u]){
			 OYMintie[d]=u;
			 d=d-1;
		}
	}
	
	printf("\nThe years with the lowest overall average are:\n");
	for (int q=0;q<=arrCYP;q++){
		if (OYMintie[q]==0){
			printf ("2015: %.2lf %%\n",overallYearAverage[0]);
		}
		else if (OYMintie[q]==1){
			printf ("2016: %.2lf %%\n",overallYearAverage[1]);
		}
		else if (OYMintie[q]==2){
			printf ("2017: %.2lf %%\n",overallYearAverage[2]);
		}
		else if (OYMintie[q]==3){
			printf ("2018: %.2lf %%\n",overallYearAverage[3]);
		}
		else if (OYMintie[q]==4){
			printf ("2019: %.2lf %%\n",overallYearAverage[4]);
		}
		else if (OYMintie[q]==5){
			printf ("2020: %.2lf %%\n",overallYearAverage[5]);
		}
		else if (OYMintie[q]==6){
			printf ("2021: %.2lf %%\n",overallYearAverage[6]);
		}
	}
	
	return 0;
}

