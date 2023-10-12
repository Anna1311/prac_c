#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	double *elem;
	struct Node *next;
	} Node;
	
 Node* define(double* p) // создать
{
	Node* tmp;
	tmp=(Node*)malloc(sizeof(Node));
	(tmp->elem)=p;
	tmp->next=NULL;
	return tmp;
}

void add_end(Node *head, double* d) //добавить в конец
{
	Node *tmp, *p;
	tmp=(Node*)malloc(sizeof(Node));
	tmp->elem=d;
	tmp->next=NULL;
	p=head;
	while (p->next!=NULL) {p=p->next;}
	p->next=tmp;
}

void print_all(Node *p) //печать
{
	while (p!=NULL) {
		printf("%f  ", *(p->elem));
		p=p->next;
		}
	printf("\n");
	
}

void swap_place(Node *p) // меняем местами первый и последний
{
	double *f, *l, *b; 
	Node* tmp;
	tmp=p;
	if (p==NULL) 
	{
		exit(-1);
	}
	else 
	{
		f=p->elem;
		while (tmp->next != NULL)
		{
			tmp=tmp->next;
		}
		l=tmp->elem;
		b=f;
		tmp->elem=f;
		p->elem=l;
		
		
	}
}
	
Node* delete_one(Node *p, double d) //удалить первый встречный
{
	Node *tmp, *subseq; 
	tmp=p; subseq=p;
	if (p==NULL) return p; // если пустой
	if (*(p->elem)==d) { tmp=tmp->next; printf("YEA\n"); } //если первый
	else 
	{
		tmp=tmp->next;
		while (tmp!=NULL && *(tmp->elem)!=d) 
			{
			//printf("%f\n", *(tmp->elem) );
			tmp=tmp->next;
			subseq=subseq->next;
			}
			if (tmp!=NULL) //нашлось
			{
				subseq->next=tmp->next;
				tmp=subseq; 
			}
			else {tmp=p;} //не нашлось
		
	}
	return p;
}

Node* delete_similar(Node *p, double d) //удалить все такие
{
	Node *tmp, *subseq; 
	tmp=p; subseq=p;
	if (p==NULL) return p; // если пустой
	if (*(p->elem)==d) { tmp=tmp->next;} 
	tmp=tmp->next;
	while (tmp!=NULL)
	{
		if (*(tmp->elem)==d) {
			subseq->next=tmp->next;
			tmp=subseq->next;
			}
		else {
			tmp=tmp->next;
			subseq=subseq->next;
			}
	 }
	return p;
}

Node* insert_similar(Node *p, double d) //дублировать все такие
{
	Node *tmp, *subseq, *dubl;
	tmp=p; subseq=p;
	dubl=(Node*)malloc(sizeof(Node));
	if (p==NULL) return p; // если пустой
	if (*(p->elem)==d) 
	{ 
		dubl->elem=p->elem;
		dubl->next=p->next;
		tmp->next=dubl;
		tmp=tmp->next;
	} 
	tmp=tmp->next;
	while (tmp!=NULL)
	{
		if (*(tmp->elem)==d) {
			dubl=(Node*)malloc(sizeof(Node));
			dubl->elem=tmp->elem;
			dubl->next=tmp->next;
			tmp->next=dubl;
			subseq=tmp->next;
			tmp=tmp->next->next;
			}
		else {
			tmp=tmp->next;
			subseq=subseq->next;
			}
	 }
	return p;
}


int main(int argc, char **argv)
{
	Node* my;
	double *k, *k2, *k3, *k4; *k=1; 
	my = define(k);
	k2=(double*)malloc(sizeof(double));
	k3=(double*)malloc(sizeof(double));
	k4=(double*)malloc(sizeof(double));
	*k2=2; *k3=3; *k4=4;
	add_end(my, k2);
	add_end(my, k3); 
	swap_place(my);
	add_end(my, k);
	add_end(my, k4);
	add_end(my, k);
	add_end(my, k);
	print_all(my);
	printf("%f\n", *(my->elem) );
	my = delete_one(my, 2);
	my = delete_similar(my, 1);
	print_all(my);
	add_end(my, k2);
	add_end(my, k4);
	insert_similar(my, 4);
	print_all(my);
	printf("%f\n", *(my->elem) );
	return 0;
}

