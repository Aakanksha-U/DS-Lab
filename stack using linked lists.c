#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);
int main()
{
	int val, option;
	do
	{
		printf("\n*********** MAIN MENU*************");
		printf("\n 1.Push");
		printf("\n 2.Pop");
		printf("\n 3.Peek");
		printf("\n 4.Display");
		printf("\n 5.Exit");
		printf("\nchoose an option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				{
					printf("Enter number to push in stack: ");
					scanf("%d", &val);
					top = push(top,val);
					break;
				}
			case 2:
				{
					top = pop(top);
					break;
				}
			case 3:
				{
					val = peek(top);
					if (val != -1)
					{
						printf("top element is %d\n",val);
					}
					break;
				}
			case 4:
				{
					top = display(top);
					break;
				}
			case 5:
				{
					break;
				}
			default:
				{
					printf("Invalid option please try again\n");
				}
		}
	}
	while(option!=5);
		return 0;
}
struct stack *push(struct stack *top, int val)
{
	struct stack *ptr;
	ptr = (struct stack *)malloc(sizeof(struct stack));
	ptr->data = val;
	if(top == NULL)
	{
		ptr -> next = NULL;
		top = ptr;
	}
	else
	{
		ptr -> next = top;
		top = ptr;
	}
	return top;
}

struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top==NULL)
	{
		printf("\n STACK UNDERFLOW");
	}
	else
	{
		top = top -> next;
		printf("\n the value being deleted is: %d",ptr->data);
		free(ptr);
	}
	return top;
}
int peek(struct stack *top)
{
	if(top == NULL)
	{
		return -1;
	}
	else
	{
		return top -> data;
	}
}
struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Stack elements are: \n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr = ptr->next;
		}
	}
	return top;
}






















