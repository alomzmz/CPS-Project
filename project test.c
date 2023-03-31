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
	int year;
} Average;

int 
main(void)
{
	Row rows [250];
	Average province [4];
	Average year [35];
	Average age [15];
	
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
	
	
	
	
	
	
	
	return 0;
}

