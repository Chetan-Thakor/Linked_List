#include<stdio.h>
#include<stdlib.h>
struct node {
   int data; 	
   struct node *left;
   struct node *right;
};
struct node *bst(struct node *t1,int key);
struct node *search(struct node *t1, int key);

int main(){

	int a[10]={50,25,75,22,40,60,80,90,15,30};
	struct node *temp = NULL ;
	for(int i=0;i<10;i++){
		temp=bst(temp,a[i]);
	}	
	temp=search(temp,75);
	printf("searched:%d\n",temp->data);
	return 0;
}

struct node *bst(struct node *t1,int key)
{
	struct node *new= (struct node *)malloc(sizeof(struct node));
	if(t1 == NULL){
		new->data=key;
		new->left = new->right = NULL;
		t1=new;
		return t1;
	}
	else if (key < t1->data){
        	t1->left = bst(t1->left, key);
    	}
    	else if (key > t1->data){
        	t1->right = bst(t1->right, key);
	}
	return t1;
}
struct node *search(struct node *t1, int key)
{
    if (t1 == NULL || t1->data == key)
       return t1;
    
    if (t1->data < key)
       return search(t1->right, key);
 
    return search(t1->left, key);
}


