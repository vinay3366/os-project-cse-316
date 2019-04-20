-*/There are 3 student processes and 1 teacher process. Students are supposed to do their assignments and they need 3 things for that-pen
, paper and question paper. The teacher has an infinite supply of all the three things. One students has pen, another has paper and 
another has question paper. The teacher places two things on a shared table and the student having the third complementary thing makes 
the assignment and tells the teacher on completion. The teacher then places another two things out of the three and again the student
having the third thing makes the assignment and tells the teacher on completion. This cycle continues. WAP to synchronise the teacher and
the students/*

#include <stdio.h>
#include <string.h>
int student1=0,student2=0,student3=0 ;
	void student(int a)
    {
    	if(a==1)
    		{student1=1;
    		printf("Student 1 completed\n");
    		}
    	if(a==2)
    		{student2=1;
    	    printf("Student 2 completed\n");}
    	if(a==3)
    		{student3=1;
    		printf("Student 3 completed\n");
    		}
    }
int main()
{   printf("\t\tWhat do you want to keep in share table\n");
    printf("\tYou can keep pen, paper, question_paper\n\tYou should keep 2 items\n");
	char s1[50];
	char s2[50];
	q:
	printf("Enter first item\n");
	s1x:
	scanf("%s",s1);
	if((!(strcmp(s1,"pen")))||(!(strcmp(s1,"paper")))||(!(strcmp(s1,"question_paper"))));
	else
	{
		printf("Item must be only pen, paper, question_paper\n");
		goto s1x;
	}
	printf("Enter second item\n");
	s2x:
	scanf("%s",s2);
		if(((!(strcmp(s1,"pen")))||(!(strcmp(s1,"paper")))||(!(strcmp(s1,"question_paper"))))&&(strcmp(s1,s2)));
	else
	{   printf("Item must be only pen, paper, question_paper and not equal to first item\n");
		goto s2x;
	}
	if((!(strcmp(s1,"pen"))&&(!strcmp(s2,"paper")))||((!strcmp(s1,"paper"))&&(!strcmp(s2,"pen"))))
	{   if(student1==1)
	{
		printf("Student 1 is already completed please give different intems\n");
	}
	else{
	
		student(1);}
    }
    	if((!(strcmp(s1,"question_paper"))&&(!strcmp(s2,"paper")))||((!strcmp(s1,"paper"))&&(!strcmp(s2,"question_paper"))))
	{  if(student2==1)
	{
		printf("Student 2 is already completed please give different intems\n");
	}
	else
		{
		student(2);}
    }
    	if((!(strcmp(s1,"pen"))&&(!strcmp(s2,"question_paper")))||((!strcmp(s1,"question_paper"))&&(!strcmp(s2,"pen"))))
	{
		if(student3==1)
	{
		printf("Student 3 is already completed please give different intems\n");
	}
	else
		{
		student(3);}
    }
    //printf("%d\n",student1);
    //printf("%d\n",student2);
    //printf("%d\n",student3);
    if((student1==1)&&(student2==1)&&(student3==1))
    {
    	printf("done");
	}
	else
	{
		goto q;
	}
}

*/Two types of people can enter into a library- students and teachers. After entering the library, the visitor searches for the required
books and gets them. In order to get them issued, he goes to the single CPU which is there to process the issuing of books. Two types of
queues are there at the counter-one for students and one for teachers. A student goes and stands at the tail of the queue for students 
and similarly the teacher goes and stands at the tail of the queue for teachers (FIFO). If a student is being serviced and a teacher 
arrives at the counter, he would be the next person to get service (PRIORITY-non preemptive). If two teachers arrive at the same time, 
they will stand in their queue to get service (FIFO). WAP to ensure that the system works in a non-chaotic manner./*

#include<stdio.h>
int no_studen=0;
int no_teach=0;
main()
{
	printf("Enter no of students : ");
    scanf("%d",&no_studen);
    printf("Enter no of faculty : ");
    scanf("%d",&no_teach);
    int at_s[no_studen];
    int s[no_studen];
    int at_t[no_teach];
    int t[no_teach];
    int i;
    for(i=0;i<no_studen;i++)
    {
    	printf("at of %d student :  ",i);
    	s[i]=i;
    	scanf("%d",&at_s[i]);
	}
	    for(i=0;i<no_teach;i++)
    {
    	printf("at of %d faculty :  ",i);
    	t[i]=i;
    	scanf("%d",&at_t[i]);
	}
	int max;
	int c;
	int checks[no_studen];
		  for(c=0;c<no_studen;c++)
	  {
	  	checks[c]=0;
	  	if(max<at_s[c])
	  	{
	  		max=at_s[c];
		  }
	  }
	int checkt[no_teach];
		  for(c=0;c<no_teach;c++)
	  {
	  	checkt[c]=0;
	  	if(max<at_t[c])
	  	{
	  		max=at_t[c];
		  }
	  }
	for(i=1;i<=max;i++)
	{ int fs[no_studen];
	  int fsp=0;
	  int j;
	  for(j=0;j<no_studen;j++)
	  {
	  	fs[j]=0;
	  }
		for(j=0;j<no_studen;j++)
		{
			if((at_s[j]<=i)&&(checks[j]==0))
			{
			fs[fsp]=j;
			fsp++;
		}
		}
	int ft[no_teach];
	  int ftp=0;
	for(j=0;j<no_teach;j++)
	  {
	  	ft[j]=0;
	  }
		for(j=0;j<no_teach;j++)
		{
			if((at_t[j]<=i)&&(checkt[j]==0))
			{
			ft[ftp]=j;
			ftp++;
		}
		}
		for(j=0;j<ftp;j++)
		{
			printf("faculty %d has completed\n",ft[j]);
			checkt[(ft[j])]=1;
		}
				for(j=0;j<fsp;j++)
		{
			printf("sudent %d has completed\n",fs[j]);
			checks[(fs[j])]=1;
		}
	}
	
}
*/ If a teacher is being served and during the period when he is being served, another teacher comes, then that teacher would get the 
service next. This process might continue leading to increase in waiting time of students. Ensure in your program that the waiting time 
of students is minimized. /*

#include<stdio.h>
int no_studen=0;
int no_teach=0;
main()
{
	printf("Enter no of students : ");
    scanf("%d",&no_studen);
    printf("Enter no of faculty : ");
    scanf("%d",&no_teach);
    int at_s[no_studen];
    int s[no_studen];
    int at_t[no_teach];
    int t[no_teach];
    int i;
    for(i=0;i<no_studen;i++)
    {
    	printf("at of %d student :  ",i);
    	s[i]=i;
    	scanf("%d",&at_s[i]);
	}
	    for(i=0;i<no_teach;i++)
    {
    	printf("at of %d faculty :  ",i);
    	t[i]=i;
    	scanf("%d",&at_t[i]);
	}
	int max;
	int c;
	int checks[no_studen];
		  for(c=0;c<no_studen;c++)
	  {
	  	checks[c]=0;
	  	if(max<at_s[c])
	  	{
	  		max=at_s[c];
		  }
	  }
	int checkt[no_teach];
		  for(c=0;c<no_teach;c++)
	  {
	  	checkt[c]=0;
	  	if(max<at_t[c])
	  	{
	  		max=at_t[c];
		  }
	  }
	for(i=1;i<=max;i++)
	{ int fs[no_studen];
	  int fsp=0;
	  int j;
	  for(j=0;j<no_studen;j++)
	  {
	  	fs[j]=0;
	  }
		for(j=0;j<no_studen;j++)
		{
			if((at_s[j]<=i)&&(checks[j]==0))
			{
			fs[fsp]=j;
			fsp++;
		}
		}
	int ft[no_teach];
	  int ftp=0;
	for(j=0;j<no_teach;j++)
	  {
	  	ft[j]=0;
	  }
		for(j=0;j<no_teach;j++)
		{
			if((at_t[j]<=i)&&(checkt[j]==0))
			{
			ft[ftp]=j;
			ftp++;
		}
		}
		int d=0;
		   if(ftp<3)
			{
			for(j=0;j<ftp;j++)
			{
			printf("faculty %d has completed\n",ft[j]);
			checkt[(ft[j])]=1;
			}
			}
		   else
		   { int z=0;
		   	while(1)
		   	{
			printf("faculty %d has completed\n",ft[z]);
			checkt[(ft[z])]=1;
			z++;
			ftp--;
			if(ftp==0)
			break;
			printf("faculty %d has completed\n",ft[z]);
			checkt[(ft[z])]=1;
			z++;
			ftp--;
			printf("sudent %d has completed\n",fs[d]);
			checks[(fs[d])]=1;
			d++;
			if(ftp==0)
			break;	
			   }
		   }
		for(j=d;j<fsp;j++)
		{
			printf("sudent %d has completed\n",fs[j]);
			checks[(fs[j])]=1;
		}
	}
	
}
