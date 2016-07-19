#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

char* MenuStruct = "menu_t menu[] = \n{";
char* MenuEnd = "\n}";
using namespace std;

void parser(char *fname)
{
	char line[500], oline[500];
	fstream  infile,outfile;
	char *token,*cmd,*func,args[100];
	int first = 1;
	
	memset(line,'\0',500);
	memset(args,'\0',100);
	
	infile.open(fname, std::fstream::out | std::fstream::in );
	if (!infile.is_open())
	{
		printf("Error opening Infile");
		return;
	}
	outfile.open("auto.h", std::fstream::in | std::fstream::out);
	if (!outfile.is_open())
	{
		printf("Error opening Outfile");
		return;
	}
	
	outfile << MenuStruct;
	while(infile.getline(line,500,';'))
	{
		printf( "line:%s\n", line );
		token = strtok(line, ",: \r\n");
		printf( "string:%s\n", token );
		if (token && !strcmp(token,"Cmd"))
		{
			cmd = strtok(NULL, ",: ");
			printf("\nCMD :%s\n",cmd);
			token = strtok(NULL, ",: ");	

			if (token && !strcmp(token,"Func"))
			{
				func = strtok(NULL, ",: ");
				printf("\nFUNC :%s\n",func);
				token = strtok(NULL, ",: ");	
				
				if (token && !strcmp(token,"ArgType"))
				{
					token = strtok(NULL, ",: ");
					printf("\nARG :%s\n",token);
					/* walk through other tokens */

					while( token != NULL ) 
					{
						sprintf(args,"%s %s",args,token);
						printf( "string:%s\n", token );
						token = strtok(NULL, ",: ");		
					}
				}
				else
					printf("Args Failed");
			}
			else
				printf("Func Failed");
		}
		else
			printf("Cmd Failed");
		
		if(first)
		{
			first=!first;
			sprintf(oline, 	"\n\t{ \"%s\",&%s,{ \"%s\" } }",cmd,func,args);
		}
		else
			sprintf(oline, 	",\n\t{ \"%s\",&%s,{ \"%s\" } }",cmd,func,args);
		
		outfile << oline;
		memset(line,'\0',500);
		memset(args,'\0',100);
		
	}
	outfile << MenuEnd;
	infile.close();
	outfile.close();
	
}
int main()
{
	parser("file.txt");
	return 0;
}