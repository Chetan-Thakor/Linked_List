#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
void display(struct node *f1);
struct node* insert(int x, struct node *f1);
struct node* insertend(int x, struct node *f1);
struct node* inserord(int x, struct node *f1);
struct node* delete(struct node *y, struct node *f1);
struct node* copy(struct node *f1);
void count_node(struct node *f1,int count);

int main()
{
	struct node *f1, *f2, *f3;
	struct node *a1, *a2, *a3;
	int x,count = 0;
	f1 = (struct node *)malloc(sizeof(struct node));
	f2 = (struct node *)malloc(sizeof(struct node));
	f3 = (struct node *)malloc(sizeof(struct node)); 
	a1 = (struct node *)malloc(sizeof(struct node));
	a2 = (struct node *)malloc(sizeof(struct node));
	a3 = (struct node *)malloc(sizeof(struct node)); 
	f1->info = 1;
	f1->link = f2;
	f2->info = 2;
	f2->link = f3;
	f3->info = 3;
	f3->link = NULL;
	printf("%d %p %p\n",f1->info,f1->link,f2);
	printf("%d %p %p\n",f2->info,f2->link,f3);
	printf("%d %p %p\n",f3->info,f3->link,f3);
		
	display(f1);
	f1 = insertend(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	f1 = insertend(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	f1 = insertend(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	printf("\ninsert value for order\n");
	f1 = inserord(x,f1);
	display(f1);
	printf("\nAfter deletion the node\n");
	f1 = delete(f3->link,f1);
	display(f1);
	printf("\n");
	a1 = copy(f1);
	printf("After copy one linked list to other linked list\n");
	display(f1);
	printf("\n");
	count_node(f1,count);
	return 0;
}

//display linked_list

void display(struct node *f1)
{
	struct node *save;
	save = f1;
	do
	{
		printf("%d ",save->info);
		save = save->link;
	}while(save != NULL);
}


//insert at beginning of linked list 
struct node* insert(int x, struct node *f1)
{
	struct node *new;
	new =  (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return 0;		
	}
	
	else
	{	
		printf("the value of x\n");
		scanf("%d",&x);
		new->info = x;
		new->link = f1;
		return new;
	}
}


//insert end of linked list
struct node* insertend(int x, struct node *f1)
{
	struct node *save;
	save = f1;
	struct node *new;
	new =  (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return new;		
	}
	
	else
	{
		while(save->link != NULL)
		{
			save = save->link;
			if(save->link == NULL)
			{	
				printf("the value of x\n");
				scanf("%d",&x);
				new->info = x;
				new->link = NULL;
				save->link = new;
				return f1;
			}
		}
	}
}

//insert in between linked list


struct node* inserord(int x, struct node *f1)
{
	struct node *save;
	save = f1;
	struct node *new;
	new =  (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return new;		
	}
	
	else
	{
		printf("the value of x\n");
		scanf("%d",&x);
		new->info = x;
		new->link = NULL;
		if(new->info <= f1->info)
		{
			new->link = f1;
			return new;
		}
		while(((save->link)->info) <= new->info)
		{
			save = save->link;	
		}
		new->link = save->link;
		save->link = new;
		return f1;
	}
}

//delete the node

struct node* delete(struct node *y, struct node *f1)
{
	struct node *pred, *save;
	save = f1;
	while(save != y && save->link != NULL)
	{	
		pred = save;
		save = save->link;
	}
	pred->link = save->link;
	free(y);
	return f1;
}

//copy linked list to other linked list

struct node* copy(struct node *f1)
{
	struct node *save, *a1, *new;
	save = f1;
	do
	{
		new = (struct node*)malloc(sizeof(struct node));
		if(new == NULL)
		{
			printf("not spaced\n");
		}
		else if(new != NULL)
		{
			new->info = save->info;
			new->link = NULL;		
		}
		save = save->link;
	}while(save->link != NULL);
	return new;
}

//count the number of node

void count_node(struct node *f1,int count)
{
	struct node *save;
	save = f1;
	if(save == NULL)
	{
		printf("%d\n",count);
	}
	
	else
	{
		if(save->link == NULL)
		{
			printf("%d\n",++count);	
		}		
		else
		{	
			while(save->link != NULL)
			{
				count = count + 1;
				save = save->link;
			}
			printf("%d\n",++count);
		}
	}
	//printf("%d\n",count);
}




