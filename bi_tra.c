#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};

void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);

struct node* new_node(int data)
{
	struct node *nod;
	nod = (struct node*)malloc(sizeof(struct node));
	nod->data = data;
	nod->left = NULL;
	nod->right = NULL;
	return nod;
}

void preorder(struct node *root)
{
	if(root == NULL)
	return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root)
{
	if(root == NULL)
	return;
	preorder(root->left);
	printf("%d ",root->data);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root == NULL)
	return;
	preorder(root->left);
	preorder(root->right);
	printf("%d ",root->data);
}
int main()
{
	struct node *root;
	root = new_node(10);
	root->left = new_node(40);
	root->right = new_node(20);
	root->left->left = new_node(30);
	root->left->right = new_node(50);
	printf("\nPreorder traversal of binary tree is\n");
	preorder(root);
	printf("\ninorder traversal of binary tree is\n");
	inorder(root);
	printf("\npostorder traversal pf binary tree is\n");
	postorder(root);
	printf("\n");
	return 0;
}
