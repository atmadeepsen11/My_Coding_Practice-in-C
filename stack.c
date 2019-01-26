#include <stdio.h>
#include <stdlib.h>

#define INT_MIN -2500000

struct stack
{
	int top;
	unsigned size;
	int* array;
};

struct stack* createStack(unsigned size){
	struct stack* s = (struct stack *)malloc(sizeof(struct stack));
	s->size = size;
	s->top = -1;
	s->array = (int *)malloc(s->size*sizeof(int));
	printf("%d \n",size);
	return s;
}

int isFull(struct stack* st)
{
	return st->top == st->size - 1;
}

int isEmpty(struct stack* st)
{
	return st->top == -1;
}

void push(struct stack* st, int item)
{
	if(isFull(st))
		return;
	st->array[++st->top] = item;
	printf("%d \n", item);
}

int pop(struct stack* st)
{
	if(isEmpty(st))
		return 0;
	return st->array[st->top--];
}

int main()
{
	struct stack* st = createStack(100);
	push(st, 10);
	push(st, 20);
	push(st, 30);
	printf("%d \n",pop(st));
	return 0;
}

	

