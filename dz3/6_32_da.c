#include <stdio.h>
#include <stdlib.h>

struct data;

struct lnode 
{ 
	struct data *p;
	struct lnode *next; 
};

struct data { double f; char *s[2]; };

struct data* init_data( double f, char *ch1,  char *ch2) //создать data
{
	struct data *d;
	char *s[2];
	d=(struct data*)malloc(sizeof(struct data));
	d->f=f;
	(d->s)[0]=ch1;
	(d->s)[1]=ch2;
	return d;
}

struct lnode* init_lnode(struct data *d) //создать lnode
{
	struct lnode *ln;
	ln=(struct lnode*)malloc(sizeof(struct lnode));
	ln->p=d;
	ln->next=NULL;
	return ln;
}

void add_node (struct lnode *ln, struct data *d) //добавить в конец узел lnode
{
	if (ln==NULL) 
	{
		ln=init_lnode(d);
		return;
	}
	else
	{
		struct lnode *np, *tmp;
		tmp=(struct lnode*)malloc(sizeof(struct lnode));
		tmp->p=d;
		tmp->next=NULL;
		np=ln;
		if (np!=NULL) 
		{
			while (np->next!=NULL) { np=np->next; }
			np->next=tmp; 
		}
	}
}

void print_lnode(struct lnode *ln) //печать lnode
{
	if (ln==NULL) { printf("EMPTY\n"); return;}
	for (struct lnode *n=ln; n!=NULL; n=n->next)
	{
		printf("%f ", (*(n->p)).f);
		printf("%c %c \n", *(*(n->p)).s[0], *(*(n->p)).s[1]);
	}
}

 void lnode_copy(struct lnode *ln2, struct lnode *ln1)
{
	struct lnode *m, *tmp, *cur;
	tmp=ln1;
	m = init_lnode(ln1->p);
	*ln2=*m;
	tmp=tmp->next;
	cur=(struct lnode*)malloc(sizeof(struct lnode));
	while (tmp!=NULL)
	{
		cur->p=tmp->p;
		cur->next=NULL;
		add_node(ln2, tmp->p);
		tmp=tmp->next;
	} 
}

int main(int argc, char **argv)
{
	char *ch1, *ch2, *ch3, *ch4;
	char *s[2];
	struct data *data1, *data2, *data0;
	struct lnode *ln1, *ln2, *ln3;
	double f=9;
	
	ch1 =(char *)malloc(sizeof(char));
	ch2 =(char *)malloc(sizeof(char));
	*ch1='a';
	*ch2='b';
	s[0]=ch1; s[1]=ch2;
	data1=init_data(f, ch1, ch2);
	ch3 =(char *)malloc(sizeof(char)); *ch3='x';
	ch4 =(char *)malloc(sizeof(char)); *ch4='y';
	data0=(struct data*)malloc(sizeof(struct data));
	
	data2=init_data(8, ch3, ch4);
	ln1=init_lnode(data1);
	add_node(ln1, data2);
	add_node(ln1, data1);
	print_lnode(ln1);
	ln2= init_lnode( data1);
	//ln3= init_lnode(ln1->p);
	ln3=init_lnode(data0);
	lnode_copy(ln3, ln1);
	//add_node(ln3, data1);
	print_lnode(ln3);
	//print_lnode(ln2);
	printf("%c\n", *(data1->s)[0]);
	return 0;
}

