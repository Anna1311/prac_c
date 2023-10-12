#include <stdio.h>
#include <stdlib.h>

typedef struct tnode 
	{
		int elem;
		struct tnode *left;
		struct tnode *right;
	} tnode;
	
tnode* addtree(tnode* p, int a)
{
	tnode *newp;
		if (p==NULL) 
		{
			p=(tnode*)malloc(sizeof(tnode)); 
			p->elem=a;
			p->left=p->right=NULL;
		
		}
		else 
		{ 
			if (a < p->elem)  { p->left=addtree(p->left, a); }
			else 
			{ p->right=addtree(p->right, a); } 
		}
		return p;
}

void treeprint(tnode *p)
	{
		if (p!=NULL) {
			treeprint(p->left);
			printf(" %d ", p->elem);
			printf("\n");
			treeprint(p->right);
		}
		else return;
	}

int count_node(tnode *p, int n)
	{
		int m=0, count=0;
		if (p==NULL && n>=0) { return 0; }
		else if (p!=NULL && n==0)  { return 1; }
			else {
				 m+=count_node(p->left, n-1);
				 m+=count_node(p->right, n-1);
				}
		return m;
	}

int main(int argc, char **argv)
{
	tnode *tree;
	int x;
	tree=NULL;
	tree = addtree(tree, 4);
	treeprint(tree);
	for (int i=0; i<5; i++) 
	{
		scanf("%d", &x);
		tree = addtree(tree, x);
	} 
	treeprint(tree);
	printf(" %d ", count_node(tree, 2));
	return 0;
}

