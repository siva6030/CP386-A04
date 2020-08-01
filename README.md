# CP386-A04

Project title

	CP386: Assignment 4

Motivation

	Write a mutiple threaded program that implements the banker's algorithm. Customers 
	request and release resourses from the bank. The banker will keep track of the resources.
	The banker will grant a request if it satisfies the safety algorithm. If a request
	does not leave the system in a safe state, the banker will deny it.

Installation

	Copy code and put it in a nano file.

	Copy and paste sample4_in.txt into nano file

	Then invoke the code with the number of resourses you want


Individual contribution

	Worked on assignment alone 



Features 

	Considers request from n customers for m resources types.
	Implements a function for requesting resource
	Implements a function for releasing resources

Tests 

	osc@ubuntu:~$ ./a.out 10 7 7 8
	Number of Customes: 5
	Currently Available resources: 10 7 7 8	
	Maximum resources from file: 
	6,4,7,3
	4,2,3,2
	2,5,3,3
	6,3,3,2
	5,6,7,5
	Enter Command (Press 0 to exit): RQ 0 1 1 1 1
	successful 0
	Enter Command (Press 0 to exit): RQ 1 1 1 10 1
	unsuccessful -1
	Enter Command (Press 0 to exit): RQ  1 1 1 1 1
	successful 0
	Enter Command (Press 0 to exit): RL 1 1 1 1 1
	successful 0
	Enter Command (Press 0 to exit): *
	Currently Available resources: 9 6 6 7
	Maximum resources: 
	6 4 7 3 
	4 2 3 2 
	2 5 3 3 
	6 3 3 2 
	5 6 7 5 
	Allocated resources: 
	1 1 1 1 
	0 0 0 0 
	0 0 0 0 
	0 0 0 0 
	0 0 0 0 
	Needed resources: 
	5 3 6 2 
	4 2 3 2 
	2 5 3 3 
	6 3 3 2 
	5 6 7 5 
	Enter Command (Press 0 to exit): Run
	Safe Sequence is: <0 1 2 4 3>


	--> Customer/Thread 0
        Allocated resources:    1 1 1 1
        Needed:    5 3 6 2
        Available:    9 6 6 7
        Thread has started
        Thread has finished
        Thread is releasing resources
        New Available:   10 7 7 8


	--> Customer/Thread 1
        	Allocated resources:    0 0 0 0
        	Needed:    4 2 3 2
        	Available:    10 7 7 8
        	Thread has started
        	Thread has finished
        	Thread is releasing resources
        	New Available:   10 7 7 8


	--> Customer/Thread 2
        	Allocated resources:    0 0 0 0
        	Needed:    2 5 3 3
        	Available:    10 7 7 8
        	Thread has started
        	Thread has finished
        	Thread is releasing resources
        	New Available:   10 7 7 8


	--> Customer/Thread 3
        	Allocated resources:    0 0 0 0
        	Needed:    6 3 3 2
        	Available:    10 7 7 8
        	Thread has started
        	Thread has finished
        	Thread is releasing resources
        	New Available:   10 7 7 8


	--> Customer/Thread 4
        	Allocated resources:    0 0 0 0
       	 	Needed:    5 6 7 5
        	Available:    10 7 7 8
        	Thread has started
        	Thread has finished
        	Thread is releasing resources
        	New Available:   10 7 7 8

Code Example
	
	Example of Asterick function
	
	void Ast(){
        printf("Currently Available resources: %d %d %d %d\n",numOfR[0],numOfR[1],numOfR[2],numOfR[3]);

        printf("Maximum resources: \n");
        for(int i = 0; i<5; i++){
                for(int j = 0;j<4;j++){
                        printf("%d ",r[i][j] );
                }
                printf("\n");
        }

        printf("Allocated resources: \n");
        for(int i = 0; i<5; i++){
                for(int j = 0;j<4;j++){
                        printf("%d ",ar[i][j] );
                }
                printf("\n");
        }

        printf("Needed resources: \n");
        for(int i = 0; i<5; i++){
                for(int j = 0;j<4;j++){
                        printf("%d ",nr[i][j] );
                }
                printf("\n");
        }
	}
Author
	
	Anusaanth Sivakumaran 

Licence
