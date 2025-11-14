#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
	int *base;
	int *top;
	int size;
}stack;

int initstack(stack *s){
	s->base = (int*)malloc(20 * sizeof(int));
	if(s->base == NULL) return 0;
	s->top = s->base;
	s->size = 20;
}

int push(stack *s, int m){
	if(s->top - s->base == s->size) return 0;
	*(s->top)= m;
	s->top++;
	
}

int pop(stack *s){
	int t;
	if(s->top == s->base) return 0;
	s->top--;
	t= *(s->top);
	return t;
}

int main(){
	stack s;
	int a;
	int m;
	scanf("%d", &a);
	initstack(&s);
	while(a!=0){
		m = a%2;
		push(&s, m); 
		a=a/2;
	}

	while(s.top!=s.base){
	printf("%d", pop(&s));
}

	return 0;
}
