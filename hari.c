/*
	Developed By : Hari Pad Bharti
	Date : 8th October 2015
	
	This C program is a command line interface which is capable of executing most of the shell commands.
	Commands from DOS and UNIX can be used at the same time.	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define EOL       1
#define ARG       2
#define AMPERSAND 3
#define SEMICOLON 4
#define MAXARG  512
#define MAXBUF  512
#define FOREGROUND  0
#define BACKGROUND  1

static char inpbuf[MAXBUF], tokbuf[2*MAXBUF], *ptr = inpbuf, *tok = tokbuf;
char path[MAXBUF];

char *prompt = "command>";

int main()
{
	system("clear");
	
	printf("\nProgram Started\n\n");

	
	while (userin(prompt) != EOF)
	{
		procline();
	}
	
	return 0;
}


int userin(char *p)
{
		int c,i, count;
		
		ptr = inpbuf;
		tok = tokbuf;
				
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			fprintf(stdout, "Shree-%s$:", cwd);
		else
			printf("<Error getting present working directory>");

		count = 0;
				
		while(1)
		{
			if((c = getchar()) == EOF)
			{
			   return(EOF);
			}
			
			if(count < MAXBUF)
				inpbuf[count++] = c;

			if(c == '\n' && count < MAXBUF)
			{
				inpbuf[count] = '\0';
				return count;
			}
		
			if(c == '\n')
			{
				printf("smallsh: input line too long\n");
				count = 0;
			
			
				if (getcwd(cwd, sizeof(cwd)) != NULL)
					fprintf(stdout, "Shree-%s$:", cwd);
				else
					printf("<Error getting present working directory>");
			}
		}
	
}

static char special [] = {' ','\t','&',';','\n','\0'};

int inarg(char c)
{
	char *wrk;

	for(wrk=special; *wrk; wrk++)
	{
		if(c == *wrk)
			return (0);
	}
	return (1);
}

int gettok (char **outptr)
{ 

	int type;
	*outptr = tok;
	while (*ptr == ' ' || *ptr == '\t')
	{	ptr++;    }
	*tok++ = *ptr;
	
	switch (*ptr++)
	{
		case '\n': 
			type = EOL;
			break;
		case '&':
			type = AMPERSAND;
			break;
		case ';':
			type = SEMICOLON;
			break;
		default: 
			type = ARG;
			while(inarg (*ptr))
			{	
				*tok++ = *ptr++;
			}
	}
	*tok++ = '\0';
	return type;
}

int  procline(void)
{
	char *arg[MAXARG +1];
	int toktype;
	int narg;
	int type;
	narg=0;
	for(;;)
	{
		switch(toktype=gettok(&arg[narg]))
		{
			case ARG:
				if(narg < MAXARG)
				{narg++;}
				break;
			case EOL:
			case SEMICOLON:
			case AMPERSAND:
				if(toktype == AMPERSAND)
					type = BACKGROUND;
				else
					type = FOREGROUND;
				if(narg != 0)
				{
					arg[narg] = NULL;
					runcommand(arg,type);
				}
				if(toktype==EOL)
					return (1);
				narg=0;
				break;
			
		}
	}

	
}


int runcommand(char **cline, int where)
{
	const char *ptr = strchr(inpbuf, '|');

	if(strcmp(cline[0],"cd")==0) 
	{
		
		path[0]='\0';
		strncat(path, &inpbuf[3], strlen(inpbuf) - 4);
		
		if (chdir(path) == -1)
			printf("%s : No such file or directiry\n",path);		
	}
	
	else
	{				
		pid_t pid;
		int status;
		switch(pid = fork())
		{

			case -1:
			perror("smallsh");
			return (-1);
			case 0:


	

			if(strcmp(cline[0],"del")==0)
				cline[0]="rm";		
			if(strcmp(cline[0],"copy")==0)
				cline[0]="cp";
			if(strcmp(cline[0],"move")==0)
				cline[0]="mv";
			if(strcmp(cline[0],"rename")==0)
				cline[0]="mv";
			if(strcmp(cline[0],"type")==0)
				cline[0]="cat";
			if(strcmp(cline[0],"md")==0)
				cline[0]="mkdir";
			if(strcmp(cline[0],"rd")==0)
				cline[0]="rmdir";
			if(strcmp(cline[0],"cls")==0)			
				cline[0]="clear";
			if(strcmp(cline[0],"dir")==0)			
				cline[0]="ls";
			if(strcmp(cline[0],"cls")==0)			
				cline[0]="clear";		
			
			if((strcmp(cline[0],"exit")==0)	|| (strcmp(cline[0],"close")==0) || (strcmp(cline[0],"quit")==0) || (strcmp(cline[0],"terminate")==0))	
			{	
				
				exit(1);
			}



			if (ptr)
			{
				int i, pipeIndex = ptr - inpbuf;
		
				for (i=0;cline[i];i++)
				{
					if(strcmp(cline[i],"|")==0)
					{
						cline[i]=NULL;
					
						break;		
					}
				}
		
		
		
				pid_t child_pid;
			    int fd[2];
			    int pfd[2];
			    pipe(pfd);
			    child_pid = fork ();
		
			    if (child_pid != 0) 
			    {
					wait(child_pid);
					close(pfd[1]);
					dup2(pfd[0],0);
					close(pfd[0]);
					execlp("cut","cut","-c","1-512",NULL);
					perror(*cline);
					exit(1);
			    }
			    else
			    {
					pipe(fd);
					pid_t pfils = fork();
				       
			
					if(pfils == 0)
					{
					    close(fd[0]);
					    dup2(fd[1],1);
					    close(fd[1]);
						execvp(*cline,cline);
					    perror(*cline);
						exit(1);
					}
					else
					{
					    wait(pfils);
					    close(fd[1]);
					    dup2(fd[0],0);
					    close(fd[0]);
					    close(pfd[0]);
					    dup2(pfd[1],1);
					    close(pfd[1]);
					    execlp(cline[i+1],cline[i+1],cline[i+2],NULL);
					    perror(*cline);
						exit(1);
					}
					return (0);
			    }
		
			}

			
			execvp(*cline,cline);
			perror(*cline);
			exit(1);

		}
	
		if((strcmp(cline[0],"exit")==0)	|| (strcmp(cline[0],"close")==0) || (strcmp(cline[0],"quit")==0) || (strcmp(cline[0],"terminate")==0))
		{
			printf("Program terminated\n");
			exit(1);
		}
		if(where== BACKGROUND)
		{
			return (0);
		}
		if (waitpid(pid, &status, 0) == -1)
		{
			return (-1);
		}
		else
		{
			return (status);
		}

	}
}
