/***********program to print the alternate nodes in the list*******************/

#include<stdio.h>
#include<stdlib.h>           


typedef struct node
{
	int data;
	struct node *link;
}sll;


void create_list(sll **head,int data);
void display(sll **head);
void print_alternate_nodes(sll **head);

int main()
{
	sll *head=NULL;
	int choice,data,position;

	while(1)
	{
		printf("1.create_list\n2.display\n3.Print_alternate_nodes\n4.exit\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				create_list(&head,data);
				break;
			case 2:
				display(&head);
				break;
			case 3:
				print_alternate_nodes(&head);
				break;
			case 4:
				exit(0);
				break;
		}

	}
	return 0;
}

void create_list(sll **head,int data)
{
	sll *newnode=(sll *)malloc(sizeof(sll));
	if(newnode==NULL)
	{
		printf("Memory not allocated\n");
	}
	else
	{
		newnode->data=data;
		newnode->link=NULL;
		if(*head == NULL)
		{
			*head = newnode;
		}
		else
		{
			sll *temp = *head;
			while(temp->link != NULL)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}
	}
}

void display(sll **head)
{
	sll *temp = *head;
	if(*head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List contains\n");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

void print_alternate_nodes(sll **head)
{
	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		sll *temp = *head;
		printf("The alternate nodes are\n");
		while(temp != NULL)
		{
			printf("%d ",temp->data);
			if(temp->link == NULL)
			{
				temp = temp->link;
			}
			else
			{
				temp = temp->link->link;
			}
		}
		printf("\n");
	}
}
