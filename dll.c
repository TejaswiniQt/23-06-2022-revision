/*******************Program to create doble linked list and display the elements**********************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}dll;


void create_list(dll **head)
{
	int choice=1;
	while(choice)
	{
		dll *temp;
		dll *newnode=(dll *)malloc(sizeof(dll));
		if(newnode==NULL)
		{
			printf("Memory not allocated\n");
		}
		else
		{
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->prev=NULL;
			newnode->next=NULL;
			if(*head==NULL)
			{
				*head=newnode;
				temp=newnode;
			}
			else
			{
				temp->next=newnode;
				newnode->prev=temp;
				temp=newnode;
			}
		}
		printf("Enter 1 add node 0 to stop adding node:");
		scanf("%d",&choice);
	}
}



void display(dll **head)
{
	dll *temp=*head;
	if(*head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List contains:\n");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}


int main()
{
	int choice;
	dll *head=NULL;

	while(1)
	{
		printf("1.create_list\n2.display\n3.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create_list(&head);
				break;
			case 2:display(&head);
			       break;
			case 3:
			       exit(0);
			       break;
		}
	}
	return 0;
}
