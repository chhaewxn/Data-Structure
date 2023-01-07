//#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode* llink;
	struct StackNode* rlink;
} DlistNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// initialise the stack
void init(LinkedStackType* s)
{
	s->top = (StackNode*)malloc(sizeof(StackNode));
	s->top->llink = s->top;
	s->top->rlink = s->top;
}

// check if the stack is empty
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}

// push the item into the stack
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}
	else {
		temp->item = item;
		temp->rlink = s->top;
		temp->llink = s->top->llink;
		s->top->llink->rlink = temp;
		s->top->llink = temp;
		s->top = temp;
	}
}

// pop the top item from the stack
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int item = temp->item;
		s->top->rlink->llink = s->top->llink;
		s->top->llink->rlink = s->top->rlink;
		s->top = s->top->rlink;
		free(temp);
		return item;
	}
}

// get the data of top item of the stack
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

void main()
{
	LinkedStackType s;
	StackNode head;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}