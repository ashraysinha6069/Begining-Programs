#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct bst{

	int data;
	struct bst* left;
	struct bst* right;
};

typedef struct bst node;

struct linked_list{
	struct bst* addr;
	struct linked_list* next;
};

typedef struct linked_list node1; 

void insert(node** root_ref,int x)
{

	if(*root_ref==NULL){
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		*root_ref=temp;
		 return;
		}
	

	else if(x<(*root_ref)->data)
		insert(&((*root_ref)->left),x);

	else
		insert(&((*root_ref)->right),x);

}

void Push(node1** head,node* x)
{
	node1* temp=(node1*)malloc(sizeof(node1));	
	temp->addr=x;
	temp->next=NULL;
	

	if(*head==NULL)
	{
		*head=temp;
		return ;
	}
	

	node1* temp1=*head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
		
	temp1->next=temp;
		
}

void Pop(node1** head)
{ 
	node1* temp=*head;
	*head=temp->next;
	free(temp);
}

bool isEmpty(node1* head)
{
	return head==NULL?true:false;
}


void levelOrderTraversal(node1* head,node* root)
{
	if(root==NULL)
		return;

	Push(&head,root);

	while(!isEmpty(head))
	{
		node* current=head->addr;
		printf("%d ",current->data);
		
		if(current->left!=NULL)
			Push(&head,current->left);
		if(current->right!=NULL)
			Push(&head,current->right);

		Pop(&head);
		
	}
}

int main()
{	
	int n,num,i;
	scanf("%d",&n);
	node* root=NULL;
	node1* head=NULL;


	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	levelOrderTraversal(head,root);


}	