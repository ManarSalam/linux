#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

    char *argv[10] = { NULL };
    char *argp[] = { NULL };
    char str1[100];
    char newString[10][10];
    int i, j, ctr = 0, flage = 0;
   static  char *temps[100];
    int index=0;

    char env_data[100][100];
    char *local_var[100];
//printf("Hello I Am Shell:> ");

    while (1) {
	for (i = 0; i < ctr; i++)
	    argv[i] = NULL;

	printf("Hello I Am Shell:> ");
	fgets(str1, sizeof str1, stdin);
	for (i = 0; i <= (strlen(str1)); i++) {
	    if (str1[i] == '=')
	       {flage = 1;break;}
	}
//	printf("flage1=%d",flage);
	    j = 0;
	    ctr = 0;
	    for (i = 0; i <= (strlen(str1)); i++) {
		while (str1[i] == ' ' && str1[i + 1] == ' ')
		    i++;
		if ((str1[i] == '\n')
		    || (str1[i] == ' ' && str1[i + 1] == '\n'))
		    continue;
		if (str1[i] == ' ' || str1[i] == '\0') {
		    newString[ctr][j] = '\0';
		    ctr++;	//for next word
		    j = 0;	//for next word, init index to 0
		} else {
		    newString[ctr][j] = str1[i];
		    j++;
		}

	    }
           // if(flage==0)
	    {
	    for (i = 0; i < ctr; i++) {	// printf(" %s\n",newString[i]);

		argv[i] = newString[i];
	    }
	    argv[ctr] = NULL;

	    }
	    for (i = 0; i < 3; i++) {
		//argv[i]=newString[i];
		// printf("argv[%d]=%s\n",i,argv[i]);
	    }

	
	if(flage == 1 )//&&(strcmp(newString[0],"set")!=0 ))//set buildin command
	{
           for (i = 0; i < ctr; i++) { // printf(" %s\n",newString[i]);
                printf("ggggggggggggggggggg\n");
                temps[i] = newString[i];
		printf("temp[%d]=%s\n",i,temps[i]);
		
            }
	   flage=0;

	}
	flage=0;
	if(strcmp(newString[0],"set")==0)
            {
                 local_var[index]=temps[0];
                 index++;
                 printf("local_var[0]=%s\n",local_var[0]);
                 printf("temp[0]=%s\n",temps[0]);
            }

	int ret_pid = fork();
	int status;
	if (ret_pid < 0)
	    printf("fork failed\n");
	else if (ret_pid > 0) {
	    // printf("i am parent\n");
	    wait(&status);
	} else if (ret_pid == 0) {
            flage=0;
            if(strcmp(newString[0],"set")==0)
	    {
                // local_var[index]=temp[0];
		// index++;	    
	         printf("local_var[0]=%s\n",local_var[0]);
	         printf("temp[0]=%s\n",temps[0]);	 
	    }
	    else
	    execvp(newString[0], argv);
	    // printf("child\n");

	}
    }
    return 0;
}
