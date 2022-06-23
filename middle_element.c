/******************************program to print middle element in the list****************/

#include<stdio.h>
#include<stdlib.h>           


typedef struct node
{
	int data;
	struct node *link;
}sll;


void create_list(sll **head,int data);
void display(sll **head);
void middle_element(sll **head);

int main()
{
	sll *head=NULL;
	int choice,data,position;

	while(1)
	{
		printf("1.create_list\n2.display\n3.middle_element\n4.exit\n");
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
				middle_element(&head);
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

void middle_element(sll **head)
{
	if(*head == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		sll *fast_ptr = *head, *slow_ptr = *head;
		while(fast_ptr != NULL && fast_ptr->link != NULL)
		{
			fast_ptr = fast_ptr->link->link;
			slow_ptr = slow_ptr->link;
		}
		printf("Middle element is: %d\n",slow_ptr->data);
	}
}
