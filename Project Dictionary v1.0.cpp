#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct dict
{
	char word[10], mean[20];
	struct dict *left, *right;
}*root, *tmp;
void create();
void insert();
void search();
void disp(struct dict *);
int main()
{
	int op;
	create();
	do
	{
		printf("\nMAIN MENU");
		printf("\n1. INSERT");
		printf("\n2. SEARCH");
		printf("\n3. DISPLAY");
		printf("\n4. EXIT");
		printf("\nEnter your Choice: ");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				insert();
				break;
				
			case 2:
				search();
				break;
				
			case 3:
				printf("\nWORD\t\t\tMEANING");
				disp(root);
				break;		
		}
	}while(op!=4);
	getch();
	return 0;
}

void create()
{
	root = NULL;
}

void insert()
{
	int c = 0;
	struct dict *pre, *ptr;
	tmp = (struct dict*)malloc(sizeof(struct dict)); //creating node
	tmp->left = tmp->right = NULL;
	printf("\nEnter the word: ");
	scanf("%s",&tmp->word);
	printf("\nEnter the meaning: ");
	scanf("%s",&tmp->mean);
	ptr = root;
	if(root == NULL) 
	{
		root = tmp;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(strcmp(tmp->word, ptr->word)>0)
			{
				pre = ptr;
				ptr = ptr->right;
			}
			else if(strcmp(tmp->word, ptr->word)<0)
			{
				pre =ptr;
				ptr = ptr->left;
			}
			else if(strcmp(tmp->word, ptr->word)==0)
			{
				c = 1;
				printf("\nWord exists!!");
				break;
			}
		}
		if(c == 0 && ptr == NULL)
		{
			if(strcmp(tmp->word,pre->word)>0)
			{
				pre->right = tmp;
			}
			else
			{
				pre->left = tmp;
			}
		}
	}
}

void search()
{
	int c = 0;
	struct dict *ptr;
	char s[10];
	printf("\nEnter word: ");
	scanf("%s",&s);
	if(root == NULL)
	{
		printf("\nDictionary is Empty!!");
		printf("\nTry Option 1");
	}
	else
	{
		ptr = root;
		while(ptr != NULL && c == 0)
		{
			if(strcmp(s,ptr->word)>0)
			{
				ptr = ptr->right;
			}
			else if(strcmp(s,ptr->word)<0)
			{
				ptr = ptr->left;
			}
			else if(strcmp(s,ptr->word)==0)
			{
				c = 1;
				printf("\nMeaning: %s",ptr->mean);
			}
		}
		if(c == 0)
		{
			printf("\nWord not found!!");
			printf("\nTry Option 1");
		}
	}
}

void disp(struct dict *ptr)
{
	if(root == NULL)
	{
		printf("\nDictionary is Empty!!");
		printf("\nTry Option 1");
	}
	else if(ptr != NULL)
	{
		disp(ptr->left);
		printf("\n%s\t\t\t%s",ptr->word,ptr->mean);
		disp(ptr->right);
	}
}

