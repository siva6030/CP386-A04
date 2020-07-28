#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>

time_t programClock;//the global timer/clock for the program

typedef struct thread //represents a single thread, you can add more members if required
{
        char tid[4];//id of the thread as read from file
        unsigned int startTime;
        int state;
        pthread_t handle;
        int retVal;
} Thread;

//you can add more functions here if required

void* Run(void* t);//the thread function, the code executed by each thread
int readFile(char* fileName);//function to read the file content and build array of threads
char rff[5][8];

int main(int argc, char *argv[])
{
        if(argc<2)
        {
                printf("Input file name missing...exiting with error code -1\n");
                return -1;
        }

    //you can add some suitable code anywhere in main() if required

        Thread* threads = NULL;
        int threadCount = readFile(argv[1]);
        int numCus;
        printf("Number of Customes: ");
        scanf(" %d", &numCus);
//      printf("\n");
        printf("Currently Available resources: \n");
        printf("Maximum resources from file: \n");
        int x = 0;
        while(x<5){
                printf("%s\n", rff[x]);
                x++;
        }
//      startClock();

        return 0;
}

int readFile(char* fileName)//do not modify this method
{
        FILE *in = fopen(fileName, "r");
        if(!in)
        {
                printf("Child A: Error in opening input file...exiting with error code -1\n");
                return -1;
        }

        struct stat st;
        fstat(fileno(in), &st);
        char* fileContent = (char*)malloc(((int)st.st_size+1)* sizeof(char));
        fileContent[0]='\0';    
        while(!feof(in))
        {
                char line[100];
                if(fgets(line,100,in)!=NULL)
                {
                        strncat(fileContent,line,strlen(line));
                }
        }
        fclose(in);

        char* command = NULL;
        int threadCount = 0;
        char* fileCopy = (char*)malloc((strlen(fileContent)+1)*sizeof(char));
        strcpy(fileCopy,fileContent);
        command = strtok(fileCopy,"\r\n");
        while(command!=NULL)
        {
                threadCount++;
                command = strtok(NULL,"\r\n");
        }
//      *threads = (Thread*) malloc(sizeof(Thread)*threadCount);
char* lines[threadCount];
        command = NULL;
        int i=0;
        command = strtok(fileContent,"\r\n");
        while(command!=NULL)
        {
                lines[i] = malloc(sizeof(command)*sizeof(char));
                strcpy(lines[i],command);
                i++;
                command = strtok(NULL,"\r\n");
        }

        for(int k=0; k<threadCount; k++)
        {
                char* token = NULL;
                int j = 0;
                token =  strtok(lines[k],";");
                while(token!=NULL)
                {
//if you have extended the Thread struct then here
//you can do initialization of those additional members
//or any other action on the Thread members
//                      printf("%s\n",token);
                        strcpy(rff[k], token);
/*
                        (*threads)[k].state=0;
                        if(j==0)
                                strcpy((*threads)[k].tid,token);
                        if(j==1)
                                (*threads)[k].startTime=atoi(token);
                        j++;
*/
                        token = strtok(NULL," ");

                }
        }


        return threadCount;
}


void* Run(void* t)//implement this function in a suitable way
{

}

