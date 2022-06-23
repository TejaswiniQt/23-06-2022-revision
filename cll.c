/*****************Program to create circular linked list and display the elements********************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}cll;

void create_list(cll **head,int data);
void display(cll **head);


int main()
{
	cll *head=NULL;
	int data,choice;

	while(1)
	{
		printf("1.create_list\n2.display\n3.exit\n");
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
				exit(0);
				break;
		}
	}
	return 0;
}

void create_list(cll **head,int data)
{
	cll *newnode=(cll *)malloc(sizeof(cll)), *temp;
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
			(*head)->link = *head;
		}
		else
		{
			temp = *head;
			while(temp->link != *head)
			{
				temp=temp->link;
			}
			temp->link = newnode;
			newnode->link = *head;

		}
	}
}

void display(cll **head)
{
	cll *temp = *head;
	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("List contains:\n");
		while(temp->link != *head)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("%d\n",temp->data);
	}
}


