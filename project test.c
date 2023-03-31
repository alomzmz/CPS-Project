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


int 
main(void)
{
	Row rows [250];
	
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
	
	printf("\n");
	printf("%d %s %s %s %lf\n", rows[20].year, rows[20].geo, rows[i].age, rows[20].sex, rows[20].value);
	printf("%s", rows[20].geo);
	
	
	return 0;
}

