#include <stdio.h>
#include <stdlib.h>
struct list {
	int elem;
	struct list* next;
};

struct queue {
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
	temp=(struct list*)malloc(sizeof(struct list));
	p=lst->next;
	lst->next=temp;
	temp->elem=number;
	temp->next=p;
	return temp;
}

void init(struct queue *q) //создать очередь
	{
		q->frnt=0;
		q->rear=0;
	}

int isempty(struct queue *q) // проверка 1-пустая 0-не пустая
	{
		if (q->frnt==0)
			return 1;
		else
			return 0;
	}
	
void insert(struct queue *q, int x) // добавление в очередь(последним)
{
	if ((q->rear==0)&&(q->frnt==0)) {
		q->rear=init_l(x);
		q->frnt=q->rear;
	}
	else 
		q->rear=addelem(q->rear, x);
}
	
void print(struct queue *q) //вывод всех в очереди
{
	struct list *h;
	if (isempty(q)==1)
		{
			printf("Очередь пуста\n");
			return ;
		}
		h=q->frnt;
	while (h!=NULL) 
	{
		printf("%d ", h->elem);
		h=h->next;
	}
	printf("\n");
	return;
	}
	
int delete_one(struct queue *q) //удаление первого из очереди
{
	struct list *temp;
	int x;
	if (isempty(q)==1)
	{
		printf("Очередь пуста\n");
		return 0;
	}
	x=q->frnt->elem;
	temp=q->frnt;
	q->frnt=q->frnt->next;
	free(temp);
	return x;
}	
	
int test (struct queue *q) //получение первого из очереди (без удаления)
{
	int x;
	x=q->frnt->elem;
	return x;
}




int main(int argc, char **argv)
{
	struct queue *q;
	int a;
	q=(struct queue*)malloc(sizeof(struct queue*));
	init(q);
	print(q);
	for(int i=0;i<5;i++) 
	{
		printf("Введите элемент очереди: ");
		scanf("%d", &a);
		insert(q, a);
	}
	print(q);
	
	while(q->frnt!= NULL) {
    a = delete_one(q);
    printf("Удален элемент %d\n", a);
    print(q);
  }
	return 0;
}

