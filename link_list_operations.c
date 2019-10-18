#include<stdio.h>
#include<malloc.h>
#include<process.h>
struct node{
	int data;
	struct node *link;
};
struct node *root;
void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the node data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
	}
}
int length()
{
	struct node *temp;
	temp=root;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
		
	}
	return count;
}
void add_at_begin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter node data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		temp->link=root;
		root=temp;
	}
}
void addafter()
{
	int loc,len,i=1;
	struct node *temp,*p;
	printf("enter the location : ");
	scanf("%d",&loc);
	len=length();
	if(loc>len)
	{
		printf("\n invalid location ");
		printf("\n currently list having %d nodes",len);
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n enter the number : ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		temp->link=p->link;
		p->link=temp;
	}
}
void display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		printf("no nodes in the list : ");
	}
	while(temp!=NULL)
	{
		printf(" %d",temp->data);
		temp=temp->link;
	}
}
void deletenode()
{
	struct node *temp;
	int loc;
	printf("\n enter the location you want to delete : \n ");
	scanf("%d",&loc);
	if(loc>length())
		printf("\n invalid location");
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		int i=1;
		struct node *p,*q;
		p=root;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
int main()
{
	int x;
	printf("************LINKED LIST********************\n");
	printf("1.append 2.add_at_begin 3.add_after 4.delete 5.length 6.display 7.exit \n");
	while(1)
	{
		printf(" \n enter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				append();
				break;
			case 2:
				add_at_begin();
				break;
			case 3:
				addafter();
				break;
			case 4:
				deletenode();
				break;
			case 5:
				printf("%d",length());
				break;
			case 6:
				display();
				break;
			case 7:
				exit(0);
			default:
				printf("\n invalid choice ");
		}
	}
	return 0;
}
