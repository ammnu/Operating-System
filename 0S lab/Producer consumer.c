#include<stdio.h>
#include<stdlib.h>
 int m=1; //mutex
 int e=5; //empty
 int f=0; //full
 int items=0;
 int main()
{ 
  int c; //choice
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  
  printf("\nOPERATIONS:\n 1.PRODUCE ITEM \n 2.CONSUME ITEM \n 3.EXIT\n");
  while(1)
 {
  printf("\nEnter choice: ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
            if ((m==1) && (e!=0))
              producer();
            else
              printf("\nProducer is waiting...");
	    break;
    case 2:
            if((m==1) && (f!=0))
               consumer();
	    else
               printf("\nConsumer is waiting...");
	    break;
    case 3:
            printf("Exiting the program");
            return 0;
  }
 }
 return 0;
}

  int wait(int s)
  {
    while(s<=0);
    s--;
    return s;
  }
 
  
  int signal(int s)
  {
    s++;
    return s;
  }
   

  void producer()
 {
    m= wait(m);
    e= wait(e);
    f=signal(f);
    items++;
    printf("\nItem %d is produced.",items);
    m= signal(m);
 }
  

  void consumer()
 {
    m=wait(m);
    f= wait(f);
    e= signal(e);
    printf("\nItem %d is consumed.",items);
    items--;
    m= signal(m);
 }

    

    

  
  
  



