#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100    /*for only input size*/
#define SIZE_ID 10
#define SIZE_NAME 20		/*for name size*/
#define SIZE_SURNAME 20		/*for surname size */
#define SIZE_MAIL 30		/*for mail size */
#define SIZE_RECORDS 200	/*for structure size */

typedef struct     
{
	char id[SIZE_ID];      /*define id*/
	char Name[SIZE_NAME];		/*define name*/
	char Surname[SIZE_SURNAME];		/*define surname*/
	char Mail[SIZE_MAIL];		/*define mail*/
	int count;
}Records; 

typedef struct     
{
	char id[SIZE_ID];      /*define id*/
	char Name[SIZE_NAME];		/*define name*/
	char Surname[SIZE_SURNAME];		/*define surname*/
	char Mail[SIZE_MAIL];		/*define mail*/
}Records_2;

void upload(Records records[SIZE_RECORDS],Records_2 records_2[SIZE_RECORDS],int inp);	  /*this function to sort in records_2*/
void find_space(char arr[] ,int *count);  /*find same strlen*/
void write_space(int space,FILE *file);		/*this function write space in file */
void readDataFromFile(Records records[SIZE_RECORDS],FILE *file);		/*this function read from input file and save in structure*/
void writeDataToFile(Records_2 records_2[SIZE_RECORDS],FILE *file ,char inp , char array[4][8]);		/*this function write output file from structure*/

int main()
{
	Records records[SIZE_RECORDS];		/*define all structure size*/
	Records_2 records_2[SIZE_RECORDS];		/*define all structure size*/	
	FILE *file_input;
	FILE *file_output;

	file_input = fopen("hw4_disordered_people.txt","r");	/*open for only read */
	file_output = fopen("orderedFile.txt","w");			/*open for only write */
	char array[4][8] , inp;
	strcpy(array[0] , "ID");
	strcpy(array[1] , "NAME");
	strcpy(array[2] , "SIRNAME");
	strcpy(array[3] , "MAIL");	

	printf("enter choise your sort : ");
	scanf("%c",&inp);
	if (inp >= 'a')
	{
		inp = inp - 32;
	}

	readDataFromFile(records,file_input);		/*call function for read from input file and save in structure*/
	upload(records ,records_2,inp);		/*this function to sort in records_2*/
	writeDataToFile(records_2,file_output,inp,array);		/*call function for write output file from structure*/

	fclose(file_input);		/*close file*/
	fclose(file_output);	/*close file*/
	return 0;
}
void find_space(char arr[] ,int *count)  /*find same strlen*/
{
	int i;
	*count = 0;
	for (i = 0; arr[i] != '\0' ; ++i)
	{
		*count += 1;
	}
}
void write_space(int space,FILE *file)		/*this function write space in file */
{
	int i;
	for (i = 0; i < space; ++i)
	{
		fprintf(file,"%c",' ');				/* write space in output */
	}
}
void readDataFromFile(Records records[SIZE_RECORDS],FILE *file)		/*this function read from input file and save in structure*/
{
	int i , j, size = 0 ,flag;
	char array[MAX];

	while(fgets(array,MAX,file) != NULL)	/*there contunie to end of file*/
	{		
		i = 0;
		records[size].count = 0;
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
			else if (array[i] >= '0' && array[i] <= '9') 		/* if id */
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].id[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				records[size].id[j] = '\0';			
			}
			else if (array[i+1] >= 'a') 		/* if name */
			{
				while(array[i] != '\n' && array[i] != ' ')
				{
					records[size].Name[j] = array[i];		/* save in structure */
					j += 1;
					i += 1;
				}
				if (array[i] == ' ' && array[i+2] >= 'a' && array[i+2] <= 'z' && array[i+1] >= 'A' && array[i+1] <= 'Z' )
				{
					records[size].Name[j] = ' ';
					i += 1;
					j += 1; 
					while(array[i] != '\n' && array[i] != ' ')
					{
						records[size].Name[j] = array[i];		
						j += 1;
						i += 1;
					}
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
void upload(Records records[SIZE_RECORDS],Records_2 records_2[SIZE_RECORDS],int inp)	/*this function to sort in records_2*/
{
	int i ,j ,k = 0 , l,number , size = 0, temp = 0, item = 0;
	sscanf(records[0].id,"%d",&l);
	while(records[k+1].Name[0] != '\0')
	{
		sscanf(records[k].id,"%d",&item);
		if (l<=item)
		{
			temp = k;
			l = item;
		}
		k += 1;
	}
	k = temp;
	while(records[size].Name[0] != '\0')
	{
		if (inp == 'I')
		{
			temp = k;
			sscanf(records[temp].id,"%d",&j);		
			for (i = 0;records[i].Name[0] != '\0'; ++i)
			{
				sscanf(records[i].id,"%d",&item);
				if ( (j>item) && (records[i].count == 0))
				{
					temp = i;
					j = item;
				}
			}
			strcpy(records_2[size].id,records[temp].id);
			strcpy(records_2[size].Name,records[temp].Name);
			strcpy(records_2[size].Surname,records[temp].Surname);
			strcpy(records_2[size].Mail,records[temp].Mail);	
			if (temp == 0)
			{
				strcpy(records[temp].id,records[k].id);
			}					
			records[temp].count = 1;
		}
		else if (inp == 'N')
		{
			temp = 0;
			for (i = 0;records[i].Name[0] != '\0'; ++i)
			{
				item = strcmp(records[i].Name,records[temp].Name);
				if ( (item < 0) && (records[i].count == 0))
				{
					temp = i;
				}				
			}
			strcpy(records_2[size].id,records[temp].id);
			strcpy(records_2[size].Name,records[temp].Name);
			strcpy(records_2[size].Surname,records[temp].Surname);
			strcpy(records_2[size].Mail,records[temp].Mail);
			if (temp == 0)
			{
				strcpy(records[temp].Name,"{");
			}			
			records[temp].count = 1;
		}
		else if (inp == 'S')
		{
			temp = 0;
			for (i = 0;records[i].Name[0] != '\0'; ++i)
			{
				item = strcmp(records[i].Surname,records[temp].Surname);
				if ( (item < 0) && (records[i].count == 0))
				{
					temp = i;
				}				
			}
			strcpy(records_2[size].id,records[temp].id);
			strcpy(records_2[size].Name,records[temp].Name);
			strcpy(records_2[size].Surname,records[temp].Surname);
			strcpy(records_2[size].Mail,records[temp].Mail);
			if (temp == 0)
			{
				strcpy(records[temp].Surname,"{");
			}
			records[temp].count = 1;
		}
		else
		{
			temp = 0;
			for (i = 0;records[i].Name[0] != '\0'; ++i)
			{
				item = strcmp(records[i].Mail,records[temp].Mail);
				if ( (item < 0) && (records[i].count == 0))
				{
					temp = i;
				}				
			}			
			strcpy(records_2[size].id,records[temp].id);
			strcpy(records_2[size].Name,records[temp].Name);
			strcpy(records_2[size].Surname,records[temp].Surname);
			strcpy(records_2[size].Mail,records[temp].Mail);
			if (temp == 0)
			{
				strcpy(records[temp].Mail,"{");
			}			
			records[temp].count = 1;
		}
		size += 1;
	}
	records_2[size].Name[0] == '\0';
}
void writeDataToFile(Records_2 records_2[SIZE_RECORDS],FILE *file ,char inp , char array[4][8])		/*this function write output file from structure*/
{
	int i = 0 ,j = 0 ,count;

	if (inp == 'I')
	{
		fprintf(file,"%s",array[0]);				/* write id in output */
		write_space(SIZE_ID - 2 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[1]);			/* write name in output */
		write_space(SIZE_NAME - 4 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[2]);			/* write surname in output */
		write_space(SIZE_SURNAME - 7 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[3]);		/* write mail in output */
		write_space(SIZE_MAIL - 4 ,file);		/*this function write space in file */

	}
	else if (inp == 'N')
	{
		fprintf(file,"%s",array[1]);			/* write name in output */
		write_space(SIZE_NAME - 4 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[0]);				/* write id in output */
		write_space(SIZE_ID - 2 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[2]);			/* write surname in output */
		write_space(SIZE_SURNAME - 7 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[3]);		/* write mail in output */
		write_space(SIZE_MAIL - 4 ,file);		/*this function write space in file */
	}
	else if (inp == 'S')
	{
		fprintf(file,"%s",array[2]);			/* write surname in output */
		write_space(SIZE_SURNAME - 7 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[0]);				/* write id in output */
		write_space(SIZE_ID - 2 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[1]);			/* write name in output */
		write_space(SIZE_NAME - 4 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[3]);		/* write mail in output */
		write_space(SIZE_MAIL - 4 ,file);		/*this function write space in file */
	}
	else
	{
		fprintf(file,"%s",array[3]);		/* write mail in output */
		write_space(SIZE_MAIL - 4 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[0]);				/* write id in output */
		write_space(SIZE_ID - 2 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[1]);			/* write name in output */
		write_space(SIZE_NAME - 4 ,file);		/*this function write space in file */
		fprintf(file,"%s",array[2]);			/* write surname in output */
		write_space(SIZE_SURNAME - 7 ,file);		/*this function write space in file */
	}		

	while(records_2[i].Name[0] != '\0')		/*contunie up to end of structure*/
	{
		fprintf(file,"%c",'\n');
		
		if (inp == 'I')
		{
			fprintf(file,"%s",records_2[i].id);				/* write id in output */
			find_space(records_2[i].id ,&count);
			write_space(SIZE_ID - count ,file);
			fprintf(file,"%s",records_2[i].Name);			/* write name in output */
			find_space(records_2[i].Name ,&count);
			write_space(SIZE_NAME - count ,file);
			fprintf(file,"%s",records_2[i].Surname);			/* write surname in output */
			find_space(records_2[i].Surname ,&count);
			write_space(SIZE_SURNAME - count ,file);
			fprintf(file,"%s",records_2[i].Mail);		/* write mail in output */
			find_space(records_2[i].Mail ,&count);
			write_space(SIZE_MAIL - count ,file);
		}
		else if (inp == 'N')
		{
			fprintf(file,"%s",records_2[i].Name);			/* write name in output */
			find_space(records_2[i].Name ,&count);
			write_space(SIZE_NAME - count ,file);			
			fprintf(file,"%s",records_2[i].id);				/* write id in output */
			find_space(records_2[i].id ,&count);
			write_space(SIZE_ID - count ,file);
			fprintf(file,"%s",records_2[i].Surname);			/* write surname in output */
			find_space(records_2[i].Surname ,&count);
			write_space(SIZE_SURNAME - count ,file);
			fprintf(file,"%s",records_2[i].Mail);		/* write mail in output */
			find_space(records_2[i].Mail ,&count);
			write_space(SIZE_MAIL - count ,file);
		}
		else if (inp == 'S')
		{
			fprintf(file,"%s",records_2[i].Surname);			/* write surname in output */
			find_space(records_2[i].Surname ,&count);
			write_space(SIZE_SURNAME - count ,file);			
			fprintf(file,"%s",records_2[i].id);				/* write id in output */
			find_space(records_2[i].id ,&count);
			write_space(SIZE_ID - count ,file);
			fprintf(file,"%s",records_2[i].Name);			/* write name in output */
			find_space(records_2[i].Name ,&count);
			write_space(SIZE_NAME - count ,file);
			fprintf(file,"%s",records_2[i].Mail);		/* write mail in output */
			find_space(records_2[i].Mail ,&count);
			write_space(SIZE_MAIL - count ,file);
		}
		else
		{
			fprintf(file,"%s",records_2[i].Mail);		/* write mail in output */
			find_space(records_2[i].Mail ,&count);
			write_space(SIZE_MAIL - count ,file);			
			fprintf(file,"%s",records_2[i].id);				/* write id in output */
			find_space(records_2[i].id ,&count);
			write_space(SIZE_ID - count ,file);
			fprintf(file,"%s",records_2[i].Name);			/* write name in output */
			find_space(records_2[i].Name ,&count);
			write_space(SIZE_NAME - count ,file);
			fprintf(file,"%s",records_2[i].Surname);			/* write surname in output */
			find_space(records_2[i].Surname ,&count);
			write_space(SIZE_SURNAME - count ,file);
		}	
		i += 1;
	}
}