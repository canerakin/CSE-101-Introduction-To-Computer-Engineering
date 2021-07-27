#include <stdio.h>
#define MAX 200    /*for only input size*/
#define SIZE_ID 20
#define SIZE_NAME 20		/*for name size*/
#define SIZE_SURNAME 30		/*for surname size */
#define SIZE_MAIL 50		/*for mail size */
#define SIZE_RECORDS 200	/*for structure size */

struct Records    
{
	char id[SIZE_ID];      /*define id*/
	char Name[SIZE_NAME];		/*define name*/
	char Surname[SIZE_SURNAME];		/*define surname*/
	char Mail[SIZE_MAIL];		/*define mail*/
};
struct Records records[SIZE_RECORDS];		/*define all structure size*/

void readDataFromFile(struct Records *records,FILE *file);		/*this function read from input file and save in structure*/
void writeDataToFile(struct Records *records,FILE *file);		/*this function write output file from structure*/

int main()
{
	FILE *file_input;
	FILE *file_output;

	file_input = fopen("hw4_disordered_people.txt","r");	/*open for only read */
	file_output = fopen("orderedFile.txt","w");			/*open for only write */

	readDataFromFile(records,file_input);		/*call function for read from input file and save in structure*/
	writeDataToFile(records,file_output);		/*call function for write output file from structure*/

	fclose(file_input);		/*close file*/
	fclose(file_output);	/*close file*/
	return 0;
}
void readDataFromFile(struct Records *records,FILE *file)		/*this function read from input file and save in structure*/
{
	int i , j, size = 0, count = 1 , flag;
	char array[MAX];

	while(fgets(array,MAX,file) != NULL)	/*there contunie to end of file*/
	{		
		i = 0;
		while(array[i] != '\n')
		{
			flag = 0;
			j = i;
			while(array[j] != ' ' && array[j] != '\n')			/*there conrol for mail*/
			{
				if (array[j] == '.')    	/*if a mail */
				{
					flag = 1;
				}
				j += 1;
			}
			j = 0;
			if (flag == 1)		/*if mail*/
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].Mail[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				records[size].Mail[j] = '\0';
			}
			else if (array[i] >= '0' && array[i] <= '9') 		/* if surname */
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].id[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				records[size].Name[j] = '\0';			
			}
			else if (array[i+1] >= 'a') 		/* if surname */
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].Name[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				records[size].Name[j] = '\0';							
			}
			else
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].Surname[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				if (array[i] == ' ' && array[i+2] >= 'A' && array[i+2] <= 'Z' )
				{
					records[size].Surname[j] = ' ';
					i += 1;
					j += 1; 
					while(array[i] != '\n' && array[i] != ' ')
					{
						records[size].Surname[j] = array[i];		
						j += 1;
						i += 1;
					}
				}
				records[size].Surname[j] = '\0';				
			}
			while(array[i] == ' ')
			{
				i += 1;
			}
		}
		size += 1;
		array[0] = '\0';
	}
	records[size].Name[0] = '\0';
}

void writeDataToFile(struct Records *records,FILE *file)		/*this function write output file from structure*/
{
	int i = 0;

	while(records[i].Name[0] != '\0')		/*contunie up to end of structure*/
	{
		fprintf(file,"%s ",records[i].id);				/* write id in output */
		fprintf(file,"%s ",records[i].Name);			/* write name in output */
		fprintf(file,"%s ",records[i].Surname);			/* write surname in output */
		fprintf(file,"%s%c",records[i].Mail ,'\n');		/* write mail in output */	
		i += 1;
	}
}