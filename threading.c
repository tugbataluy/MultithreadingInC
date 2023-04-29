
/* C Program to count the Number of Lines in a Text File  */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#include<math.h>
int c2=0;
 int no_of_works=0;
 sem_t sem;
 double sum=0;
 double *works;
 struct thread_data{
   int  start_index;
   int  end_index;
   int thread_id;
};
 
 
 
 
 void *work(void* args){
  struct thread_data *data_t = (struct thread_data*) args;

  	sem_wait(&sem);
    	// critical section
	for(int i=0;i<data_t->end_index-data_t->start_index;i++)
    	{
    	
    	printf("Thread %d reads %d. line. The value is %.2f \n",data_t->thread_id,data_t->start_index+i+1,works[data_t->start_index+i]);
    	
    	sum+=works[data_t->start_index+i];
    	if(i==data_t->end_index-data_t->start_index-1){
    		printf("Shared Resource: %.2f",sum);
    		printf("\n");
    		}
    		
    	}
    		
    	
    	
    	
    	sem_post(&sem);
    /*for(int i=0;i<thread_data_array[1].end_index-thread_data_array[1].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[1].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[2].end_index-thread_data_array[2].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[2].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[3].end_index-thread_data_array[3].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[3].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[4].end_index-thread_data_array[4].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[4].thread_id,i+1,data);
    }*/
    
    }
 

 
int main()
{
   
   
    // Close the file
    
    //printf("The file %s has %d lines\n ", "input.txt", count);
    
    
   double temp[1000];
	int ck;
	int k=0;
	scanf("%lf",&temp[k]);
	k++;
    while (1) {
        ck = getchar();            // Get one character from the input
        if (ck == EOF) { break; }  // Exit the loop if we receive EOF ("end of file")
        else if(ck=='\n'){c2++;}
        scanf("%lf",&temp[k]);
        k++;
    }
    c2++;
    //printf("%d\n",c2);
    double numbers[c2];
   for(int i=0;i<c2;i++){
   numbers[i]=temp[i];
   
   }
   works=numbers;
    
    /*for(int i=0;i<c2;i++){
    	printf("%lf\n",temp[i]);
    	
    }/*
    printf("\n");
    for(int i=0;i<count;i++){
    	printf("%lf\n",works[i]);
    	
    }*/
 	  
    no_of_works=ceil(c2/5); 
    
    sem_init(&sem,0,1);
    pthread_t threads[5];
    int step=0;
    struct thread_data thread_data_array[5];
    
    thread_data_array[0].start_index=0;
    thread_data_array[0].end_index=no_of_works;
    thread_data_array[0].thread_id=1;
    
    thread_data_array[1].start_index=1*no_of_works;
    thread_data_array[1].end_index=2*no_of_works;
    thread_data_array[1].thread_id=2;
    
    thread_data_array[2].start_index=2*no_of_works;
    thread_data_array[2].end_index=3*no_of_works;
    thread_data_array[2].thread_id=3;
    
    thread_data_array[3].start_index=3*no_of_works;
    thread_data_array[3].end_index=4*no_of_works;
    thread_data_array[3].thread_id=4;
    
    thread_data_array[4].start_index=4*no_of_works;
    thread_data_array[4].end_index=c2;
    thread_data_array[4].thread_id=5;
    
    /*FILE *temp=fopen("input.txt","r");
    fseek(temp,thread_data_array[0].start_index,SEEK_SET);
    for(int i=0;i<thread_data_array[0].end_index-thread_data_array[0].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[0].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[1].end_index-thread_data_array[1].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[1].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[2].end_index-thread_data_array[2].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[2].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[3].end_index-thread_data_array[3].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[3].thread_id,i+1,data);
    }
    for(int i=0;i<thread_data_array[4].end_index-thread_data_array[4].start_index;i++)
    {
    	double data;
    	fscanf(temp,"%lf",&data);
    	printf("Thread %d reads %d. line. The value is %.2lf\n",thread_data_array[4].thread_id,i+1,data);
    }*/
    for(int i=0;i<5;i++){
    	pthread_create(&threads[i],NULL,work,&thread_data_array[i]);
    	pthread_join(threads[i],NULL);
    } 
    
   sem_destroy(&sem);
   
   
    
    
    return 0;
}