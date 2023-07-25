#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tyme
{
    int hh,mm;
};
 struct bus
{
      char src[20],dst[20],route[30];
      struct tyme t;
      int price;
      int layout[10][5],seats;
};
struct bus s[100];
static int no=0;

void addroute()
{
     int i,n;
     char rt[40],tim[3],tim1[3];
printf("\n welcome to adding new route module\n");
printf("\nHow many new routes you want to add\n");
scanf("%d",&n);
     for(i=no;i<n+no;i++)
{
printf("\n Enter the source and destination city of the bus \n");
scanf("%s%s",s[i].src,s[i].dst);
strcpy(rt,s[i].src);
strcat(rt,s[i].dst);
printf("Enter bus route");
scanf("%s",s[i].route);
printf("\n Enter the time of departure\n");
scanf("%d%d",&s[i].t.hh,&s[i].t.mm);
	
printf("\n Enter the price per seat");
scanf("%d",&s[i].price);
      s[i].seats=50;	
}
 no+=n;
}


void dis_route()
{
  int i;
  for(i=0;i<no;i++)
{
printf("Route       Source       Destination     Hour  Min       Price    Seat Number"); 
printf("\n %s\t    %s\t    %s\t\t  %2d\t  %2d\t   %4d\t %3d\n",s[i].route,s[i].src,s[i].dst,s[i].t.hh,s[i].t.mm,s[i].price,s[i].seats);

}
}
 void book()
{
char route[30],name[20];
int ticket,bill,i;
printf("\n May I know your name please");
scanf("%s",name);
dis_route();
printf("\n Enter route ");
scanf("%s",route);

for(i=0;i<no;i++)
{
	if(strcmp(s[i].route,route)==0)
	{
		printf("\n Enter the number of tickets to be booked");
		scanf("%d",&ticket);
		if(ticket<=s[i].seats)
		{
			bill=ticket*s[i].price;
			printf("\n %s please pay %d rupees",name,bill);
			s[i].seats-=ticket;
			return 0;
		}
		else
		{
			printf("\n Sorry  %s bus is full try another bus",name);
		}

	}
} 	
printf("\n %s you typed wrong route please verify once again");

}

int main()
{
int choice;
	do
	{
		printf("\n Enter 1:display 2:book 3:add route 5: exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: dis_route();
				break;
			case 2: book();
				break;
			case 3:addroute();
			       break;
			default: printf("\n Thank You");
		}
	}while(choice!=5);
}

