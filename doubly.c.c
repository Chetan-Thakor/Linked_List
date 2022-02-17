#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int info;
	struct node *right;
};
void display(struct node *f1);
struct node* insert(int x, struct node *f1);
struct node* insertend(int x, struct node *f1);
//struct node* insertend(int x, struct node *f1);
//struct node* inserord(int x, struct node *f1);
//struct node* delete(struct node *y, struct node *f1);

int main()
{
	struct node *f1, *f2, *f3;
	int x;
	f1 = (struct node *)malloc(sizeof(struct node));
	f2 = (struct node *)malloc(sizeof(struct node));
	f3 = (struct node *)malloc(sizeof(struct node));  
	f1->left = NULL;
	f1->info = 10;
	f1->right = f2;
	f2->left = f1;
	f2->info = 20;
	f2->right = f3;
	f3->left = f2;
	f3->info = 30;
	f3->right = NULL;
	
	printf("%d %p %p\n",f1->info,f1->left,f1->right);
	printf("%d %p %p\n",f2->info,f2->left,f2->right);
	printf("%d %p %p\n",f3->info,f3->left,f3->right);
		
	f1 = insert(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	f1 = insertend(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	/*f1 = inserord(x,f1);
	printf("after the new insertion node\n");
	display(f1);
	printf("\n");
	f1 = delete(f1->link,f1);
	display(f1);
	printf("\n");
	return 0;*/
	return 0;
}

//display linked_list

void display(struct node *f1)
{
	struct node *save;
	save = f1;
	while(save != NULL)
	{
		printf("%d ",save->info);
		save = save->right;
	}//while(save->right != NULL);
}


//insert at beginning of linked list 
struct node* insert(int x, struct node *f1)
{
	struct node *new, *ptr, *save;
	save = f1;
	//ptr = f1;
	new =  (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return 0;		
	}	
	printf("the value of x\n");
	scanf("%d",&x);
	new->info = x;
	new->left = NULL;
	new->right = save;
	save->left = new;
	return new;
}

//insert end of linked list
struct node* insertend(int x, struct node *f1)
{
	struct node *save, *new, *ptr;
	save = f1;
	ptr = f1;
	new = (struct node *)malloc(sizeof(struct node)); 
	if(new == NULL)
	{
		printf("not space in memory\n");
		return new;		
	}
	
	else
	{
		while(save->right != NULL)
		{
			save = save->right;
		}	
		while(ptr->right != NULL)
		{
			ptr = ptr->right;
		}
		printf("the value of x\n");
		scanf("%d",&x);
		new->info = x;
		new->right = NULL;
		new->left = save;
		ptr->right = new;
		return f1;	
	}
}

/*insert in between linked list

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
*/





