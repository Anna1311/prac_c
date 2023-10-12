#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode { 
	struct data *p;
	struct lnode *next; 
	};
struct data { 
	double f; 
	char *s[2];
	};

struct lnode* create(double f, char *s1[2])
{
	struct data *d;
	struct lnode *nl;
	d=(struct data*)malloc(sizeof(struct data));
	d->f=f;
	d->s=s1;
	strcpy(*(d->ss), *s1);
	nl=(struct lnode*)malloc(sizeof(struct lnode));
	nl->p=d;
	nl->next=NULL;
	return nl;
	
}
	
struct lnode* make_copy(struct lnode* f)
{
	struct lnode *cmp0, *cmp1, *np, *new;
	np=f;
	if (f==NULL) {return f;}
	cmp0=(struct lnode*)malloc(sizeof(struct lnode));
	cmp0->p=np->p;
	cmp0->next=NULL;
	new=cmp0;
	while (np!=NULL)
	{
		cmp1=(struct lnode*)malloc(sizeof(struct lnode));
		cmp0->p=np->p;
		cmp0->next=cmp1;
		cmp1->next=NULL;
		np=np->next;
		
	}
	return new;	
}

void print_lnode(struct *lnode)
{
	for (struct lnode *p=list; p!=NULL; p=p->next)
	{
		printf("%d ", (int)((*(p->data)).f);
		printf("%s ", *(*(p->data)).s);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	char *s1[2];
	double a=3;
	struct lnode* ln;
	(*s1)="ab";
	ln=create(a, s1);
	printf("%s\n", *s1);
	
	
	return 0;
}

