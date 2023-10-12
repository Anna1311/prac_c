#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	char *(elem);
	struct Node *next;
	} Node;
	
Node* define(char* p) // создать
{
	Node* tmp;
	tmp=(Node*)malloc(sizeof(Node));
	(tmp->elem)=(char*)malloc(sizeof(char));
	(tmp->elem)=p;
	tmp->next=NULL;
	return tmp;
}

void add_end(Node *head, char* d) //добавить в конец
{
	Node *tmp, *p;
	tmp=(Node*)malloc(sizeof(Node));
	tmp->elem=d;
	tmp->next=NULL;
	p=head;
	while (p->next!=NULL) {p=p->next;}
	p->next=tmp;
}

void add_end_ch(Node *head, char d) //добавить в конец char
{
	Node *tmp, *p;
	char *ch;
	ch=(char*)malloc(sizeof(char));
	*ch=d;
	tmp=(Node*)malloc(sizeof(Node));
	tmp->elem=ch;
	tmp->next=NULL;
	p=head;
	while (p->next!=NULL) {p=p->next;}
	p->next=tmp;
}


void print_all(Node *p) //печать
{
	while (p!=NULL) {
		printf("%c ", *(p->elem));
		p=p->next;
		}
	printf("\n");
	
}

int is_in(Node *p, char q) //1-естьб 0-нет
{
	int find=0;
	while (p!=NULL) {
		if (*(p->elem)==q) {find=1;}
		p=p->next;
		}
	return find;
}

Node* cr_copy(Node *l1, Node *l2) //добавляет в l1 копию одного элемента l2
{
	Node *dop, *k;
	char *ch;
	k=l1;
	dop=(Node*)malloc(sizeof(Node));
	ch=(char*)malloc(sizeof(char));
	*ch=*(l2->elem);
	dop->elem=ch;
	dop->next=NULL;
	if (l1==NULL) 
	{
		l1=dop;
		return l1;
	}
	else {
		while (k->next!=NULL) {k=k->next;} 
		k->next=dop;
		}
	return l1;
	
}

Node* exclusive(Node *l1, Node *l2) //объединение - пересечение
{
	Node *ll3, *cl1, *cl2, *cl3;
	char *cur_elem;
	ll3=(Node*)malloc(sizeof(Node));
	ll3=NULL;
	cl1=l1;
	cl2=l2;
	cl3=ll3;
	 while (cl1!=NULL)  
	{
		cur_elem=cl1->elem;
		if (is_in(l2, *(cur_elem))== 0) {ll3= cr_copy(ll3, cl1);  }
		cl1=cl1->next; 
		
	} 
	 while (cl2!=NULL) 
	{
		cur_elem=cl2->elem;
		if (is_in(l1, *(cur_elem))== 0) { ll3=cr_copy(ll3, cl2); }
		cl2=cl2->next;
	} 
	return ll3;
	
}


int main(int argc, char **argv)
{
	Node* chain;
	Node *l1, *l2, *l3, *l4;
	char *s1, *s2, *s3;
	l4=NULL;
	s1=(char*)malloc(sizeof(char));
	s2=(char*)malloc(sizeof(char));
	s3=(char*)malloc(sizeof(char));
	(*s1)='a'; (*s2)='b'; (*s3)='c'; 
	chain = define(s1);
	l1 = define(s1); l2 = define(s2); l3 = define(s3);
	add_end_ch(chain, 'k');
	add_end_ch(l1, 'f'); add_end_ch(l1, 'i'); add_end_ch(l1, 'r');
	add_end_ch(l2, 's'); add_end_ch(l2, 'e'); add_end_ch(l2, 'c');
	add_end_ch(l3, 't'); add_end_ch(l3, 'h'); add_end_ch(l3, 'i');
	add_end(chain, s2);
	add_end(chain, s3);
	add_end_ch(l1, 'i');
	//print_all(l1);
	//print_all(l2);
	cr_copy(l1, l2);
	cr_copy(l1, l2->next);
	add_end_ch(l2, 'f');
	printf("l1: "); print_all(l1);
	printf("l2: "); print_all(l2);
	l3=exclusive(l1, l2);
	printf("l1+l2-l1*l2: "); print_all(l3);
	//printf("K in list: %d\n", is_in(chain, 'k'));
	//printf("%c \n", *(l1->elem));
	return 0;
}

