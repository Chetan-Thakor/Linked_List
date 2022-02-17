#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node * create_node();
struct node * insertnode();
void display(struct node *t);
int main()
{
	int n,i = 1;	
	struct node *f1;
	printf("how many node do you want to create?\n");
	scanf("%d",&n);
	printf("\n");
	f1 = (struct node*)malloc(sizeof(struct node));
	f1 = insertnode();
	while(i < n)
	{
		//f1 = insertnode();
		f1->link = insertnode();
		i++;
	}
	void display(f1);
	return 0;
}


struct node * create_node()
{
	struct node *new;	
	new = (struct node*)malloc(sizeof(struct node));
	if(new == NULL)
	{
		printf("space not allow in memory\n");
		return (NULL);
	}
	else	
	{
		return (new);
	}
}

struct node * insertnode()
{
	struct node *temp;
	temp = create_node();
	printf("enter the data of new node\n");
	scanf("%d",&temp->data);
	temp->link = NULL;
	return (temp);
}

void display(struct node *t)
{
	struct node *r;
	r = (struct node*)malloc(sizeof(struct node));
	r = t;
	while(r->link != NULL)
	{
		printf("%d\n",r->data);
		r = r->link;
	}
}




