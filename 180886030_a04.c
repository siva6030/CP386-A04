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

void Run();//the thread function, the code executed by each thread
int readFile(char* fileName);//function to read the file content and build array of threads
void rq(char* c);
void rl(char* c);
void Ast();
int safety();

char rff[5][8];//resources from file
int r[5][4];//max resources
int ar[5][4];// allocated
int nr[5][4];//needed
int numOfR[4];

int main(int argc, char *argv[])
{
        if(argc<2)
        {
                printf("Input file name missing...exiting with error code -1\n");
                return -1;
        }

    //you can add some suitable code anywhere in main() if required

        Thread* threads = NULL;
        //argv[1]
        int threadCount = readFile("sample4_in.txt");
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
        char cmd[12];
        char zero[2] = "0";
        char c[3];

        printf("Enter Command (Press 0 to exit): ");
        scanf(" %s", cmd);

        while(strcmp(cmd,zero) != 0){
                strncpy(c,cmd,3);
                if(strcmp(c,"RQ") == 0){
                        rq(cmd);
                }
                else if(strcmp(c,"RL") == 0){
                        rl(cmd);
                }
                else if(strcmp(c,"*") == 0){
                        Ast();
                }
                else if(strcmp(c,"Run") == 0){
                        Run();
                }
                else{
                        printf("Invalid entry\n");
                }


                printf("Enter Command (Press 0 to exit): ");
                scanf(" %s", cmd);
        }

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
                        r[k][j] = atoi(token);
                        nr[k][j] = atoi(token);
                        ar[k][j] =  0;
                        j++;
                        token = strtok(NULL," ");

                }
        }


        return threadCount;
}


void run()//implement this function in a suitable way
{

}

void rq(char* c){

}

void rl(char* c){

}

void Ast(){

}

int safety(){

}

