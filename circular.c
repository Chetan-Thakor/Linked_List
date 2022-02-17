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

int main()
{
	struct node *f1, *f2, *f3;
	int x;
	f1 = (struct node *)malloc(sizeof(struct node));
	f2 = (struct node *)malloc(sizeof(struct node));
	f3 = (struct node *)malloc(sizeof(struct node));  
	f1->info = 10;
	f1->link = f2;
	f2->info = 20;
	f2->link = f3;
	f3->info = 30;
	f3->link = f1;
	printf("%d %p %p\n",f1->info,f1->link,f2);
	printf("%d %p %p\n",f2->info,f2->link,f3);
	printf("%d %p %p\n",f3->info,f3->link,f3);
		
	//f1 = insert(x,f1);
	//printf("after the new insertion node\n");
	//display(f1);
	f1 = insertend(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	f1 = inserord(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	printf("\n");
	f1 = delete(f1->link,f1);
	display(f1);
	printf("\n");
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
	}while(save != f1);
}


//insert at beginning of linked list 
struct node* insert(int x, struct node *f1)
{
	struct node *new, *ptr, *save;
	save = f1;
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
		while(save->link != NULL)
		{
			save = save->link;
		}
		save->link = new;
		return new;
	}
}

//insert end of linked list
struct node* insertend(int x, struct node *f1)
{
	struct node *save, *new;
	save = f1;
	new = (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return new;		
	}
	
	else
	{
		while(save->link != f1)
		{
			save = save->link;
		}	
		printf("the value of x\n");
		scanf("%d",&x);
		new->info = x;
		new->link = f1;
		save->link = new;
		return f1;	
	}
}

//insert in between linked list

struct node* inserord(int x, struct node *f1)
{
	struct node *save, *ptr;  //ptr for last node point
	save = f1;
	ptr = f1;
	struct node *new;
	new =  (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return new;		
	}
	
	else
	{
		printf("\nthe value of x\n");
		scanf("%d",&x);
		new->info = x;
		new->link = NULL;
		while(ptr->link != f1)
		{
			ptr = ptr->link;		
		}
		if(new->info <= f1->info)
		{
			new->link = f1;
			ptr->link = new;
			return new;
		}
		while(((save->link)->info) <= new->info)
		{
			save = save->link;	
		}
		new->link = save->link;
		save->link = new;
		ptr->link = f1;
		return f1;
	}
}

//delete the node

struct node* delete(struct node *y, struct node *f1)
{
	struct node *pred, *save, *ptr;
	save = f1;
	ptr = f1;
	while(ptr->link != f1)
	{
		ptr = ptr->link;		
	}
	while(save != y && save->link != NULL)
	{	
		pred = save;
		save = save->link;
	}
	pred->link = save->link;
	free(y);
	ptr->link = f1;
	return f1;
}






