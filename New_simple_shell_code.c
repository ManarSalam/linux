#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>



int main()
{

    char *argv[10] = { NULL };
    char *argp[] = { NULL };
    char str1[100];
    char newString[10][10];
    int i, j, ctr = 0, flage = 0;
    static char temps[100];
    int index = 0;

    char env_data[100][100];
    char local_var[100][100];

    int ret_pid;
    int status;
    char name[10][10];		//{{name,value}}
    char value[10][10];
    while (1) {
	for (i = 0; i < ctr; i++)
	    argv[i] = NULL;

	printf("Hello I Am Shell:> ");
	fgets(str1, sizeof str1, stdin);
	for (i = 0; i <= (strlen(str1)); i++) {
	    if (str1[i] == '=') {
		flage = 1;
		break;
	    }
	}

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
		ctr++;		//for next word
		j = 0;		//for next word, init index to 0
	    } else {
		newString[ctr][j] = str1[i];
		j++;
	    }

	}

	for (i = 0; i < ctr; i++) {

	    argv[i] = newString[i];
	}
	argv[ctr] = NULL;

	if (flage == 1) {

	    for (i = 0; i < ctr; i++) {

		strcpy(temps, newString[0]);

	    }
	}
	j = 0;
	ret_pid = fork();
	if (ret_pid < 0)
	    printf("fork failed\n");
	else if (ret_pid > 0) {
	    //  printf("i am parent\n");
	    wait(&status);
	} else if (ret_pid == 0) {
	    flage = 0;
	    if (strcmp(newString[0], "set") == 0) {
		strcpy(local_var[index], temps);
		index++;
		for (i = 0; i < index; i++) {
		    printf("local_var[%d]:%s\n", i, local_var[i]);
		}
	    } else if (strcmp(newString[0], "export") == 0) {
		int p = 0;
		int x = 0;
		for (i = 0; i <= index; i++) {
		    for (j = 0; j < strlen(local_var[i]); j++) {
			if (local_var[i][j] != '='&& x==0) {
			    name[i][j] = local_var[i][j];	//name
                          
			}

		//	printf("name[%d]=%s\n", i, name[i]);
			else if(local_var[i][j] == '='&& x==0)
			{
				x++;
				continue;
			}
		        
			else
			{
                         
			 value[i][p] = local_var[i][j];       //value
                            p++;

			}	
			
		    }
		 //   printf("name[%d]=%s\n", i, name[i]);
                 //   printf("value[%d]=%s\n", i, value[i]);
		    p=0;
		    x=0;
                    }
               for(i=0;i<=index;i++)
	       {
		       if(strcmp(newString[1],name[i])==0)
		       {
			       x=1;
		//	       printf("exisssst");
		               setenv(name[i], value[i], 1);

		       }
		       
			       
	       }
	       if(x==0)
		          printf("the variable is not exist\n");

	
		}
	    


	    else
		execvp(newString[0], argv);
//          printf("child\n");

	}
    }
    return 0;
}
