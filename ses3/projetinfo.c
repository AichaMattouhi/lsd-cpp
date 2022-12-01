#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX 500
#define BUFFER_SIZE 1
static char  stc[MAX];


//this function is used to concatenate the two strings s1 and s , it copies s int s1 , it will be used to copy the buffer read into the static varaible stc inside of the function read
void strjoin (char* s1, char* s)
{
	int n= strlen (s);
	int m=strlen (s1);
	for (int i=0;i<n;i++)
		s1[m+i]=s[i];
	return ;
}

// this function checks wether if the string contains a back slash n  , it will hepl us knwo if we read a line in the file

int check_endl(char* s)
{
	int i=0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}


//this function takes in arguments a file descriptor  reads the corresponding file  using the predefined function read in c 
void read_file(int fd )
{
	int k;
	char * buffer= (char*)malloc((BUFFER_SIZE+1) * sizeof(char));
	
	// the function read attempt to read  BUFFER_SIZE bytes from the file associated with the file descriptor fd into the  string buffer 
	while(k=read(fd,buffer,BUFFER_SIZE) != 0)  //as long as we don't get to the end of the file loop ; if read returns 0 int indicates EOF.
	{
		if (k == -1) //on error : read returns -1 we free the buffer and finish the process
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		strjoin(stc,buffer);   //  if read returns a correct index strictly positif we copy the buffer into the static variable
    
   // printf("\n");
		if(check_endl(stc))  // if we arrive to a back slash n , means we have read a line so we stop the function  using break , otherwise the read function will continue until we get a back slash n or get to the end of the file.
			break;
	}
	return ;
}


//this function is used to extract and return a line alreadu stored in the static variable by the function read_file
char* get_line ()
{
	int n=0;
	while (stc[n] != '\n' && stc [n] != '\0')
		n++;
	if (stc[n] == '\n')
		n++;
	char* line =(char*)malloc(sizeof(char) *(n+1));
	for(int i=0;i<n;i++)
	{
		line[i] = stc[i] ;
	}
	line [n]='\0';
	return line;
}


//this function stores what comes after the back slash n since it will be used similarly to get the next line
char* save_extra() 
{
	int n=0, m=1;
	while (stc[n] != '\0' )
		n++;
	//printf("n:%d\n", n);
	while (stc[m] != '\n')
		m++;
	//printf("m:%d\n", m);
	int size= n-m +1 ;
	char* extra = (char*)malloc (sizeof(char) * size );
	for (int i=0; i<size-2 ; i++)
		{
		  extra[i]= stc[i+m+1];
		  
		 
		}
	extra[size-2] = '\0';
	
	return extra;
}


char* get_next_line (int fd)
{
	
	
	read_file (fd);
	if (stc == NULL)
		exit(EXIT_FAILURE);
	char* line = get_line();
	char* extra= save_extra();

	int i=0;
	while ( line[i] !='\0')
	{
		printf("%c", line[i]);
		i++;
	}
    
             memset(stc,0,strlen(stc)); //
	 int j=0;
	while( extra [j]!= '\0')
	{
		stc[j] = extra[j];
                                        j++;
	} 
    
	return line;
	
}




int main()

{ 
  int fd = open("filetxt.txt",O_RDONLY );
  for(int i=0; i<5; i++)
   {
     get_next_line (fd);
    
   }
   return 0;
  
}
   
