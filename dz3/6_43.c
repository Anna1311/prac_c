#include <stdio.h>
#include <stdlib.h>


struct list {
	int elem;
	struct list* next;
};

struct stack {
	struct list *frnt, *rear;
	};
	
struct list *init_l(int a) //создать список
{
	struct list *lst;
	lst=(struct list*)malloc(sizeof(struct list));
	lst->elem=a;
	lst->next=NULL;
	return lst;
}

struct list* addelem(struct list *lst, int number) //добавить в список текущий
{
	struct list *temp, *p;
	p=lst;
	temp=(struct list*)malloc(sizeof(struct list));
	temp->elem=number;
	temp->next=p;
	lst=temp;
	return lst;
	
	
	/*struct list *temp, *p;
	temp=(struct list*)malloc(sizeof(struct list));
	p=lst->next;
	lst->next=temp;
	temp->elem=number;
	temp->next=p;
	return temp; */
	
	
}
	
void init(struct stack *st) //создать стек
	{
		st->frnt=0;
		st->rear=0;
	}


int isempty(struct stack *st) // проверка 1-пустой 0-не пустой
	{
		if (st->rear==0)
			return 1;
		else
			return 0;
	}
	
void push(struct stack *st, int x) // добавление в стек(последним)
{
	if ((st->rear==0)&&(st->frnt==0)) {
		st->frnt=init_l(x);
		st->rear=st->frnt;
	}
	else 
		st->rear=addelem(st->rear, x);
}

void print(struct stack *st) //вывод всех в стеке
{
	struct list *h;
	if (isempty(st)==1)
		{
			printf("stack is empty\n");
			return ;
		}
		h=st->rear;
	while (h!=NULL) 
	{
		printf("%d ", h->elem);
		h=h->next;
	}
	printf("\n");
	return;
}

int pop(struct stack *st) //удаление первого из стека
{
	struct list *temp;
	int x;
	if (isempty(st)==1)
	{
		printf("СТЕК пустой\n");
		return 0;
	}
	x=st->rear->elem;
	temp=st->rear;
	st->rear=st->rear->next;
	free(temp);
	return x;
}		

	
int test (struct stack *st) //получение первого из стека (без удаления)
{
	int x;
	x=st->rear->elem;
	return x;
}
int main(int argc, char **argv)
{
	struct stack *st;
	int a;
	st=(struct stack*)malloc(sizeof(struct stack*));
	init(st);
	print(st);
	for(int i=0;i<5;i++) 
	{
		printf("Введите элемент стека: ");
		scanf("%d", &a);
		push(st, a);
	}
	print(st);
	
	while(st->rear!= NULL) {
    a = pop(st);
    printf("Удален элемент %d\n", a);
    print(st);
  }
  push(st, 7);
  push(st, 8);
  push(st, 9);
  a=test(st);
  printf("%d\n", a);
	return 0;
}

