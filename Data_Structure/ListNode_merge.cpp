#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void display(ListNode* head) {
	ListNode* p = head;

	while (p != NULL) {
		printf("%d ", p->data);
		p = p->link;
	}
	// printf("\n");
}

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode* a1, * b1;
	ListNode* newhead, * tmp;

	newhead = NULL;
	tmp = NULL;
	a1 = head1;
	b1 = head2;

	while (a1 != NULL && b1 != NULL) {
		if (newhead == NULL) {
			if (a1->data <= b1->data) {
				newhead = a1;
				tmp = newhead;
				a1 = a1->link;
			}
			else if (a1->data > b1->data) {
				newhead = b1;
				tmp = newhead;
				b1 = b1->link;
			}
		}
		else {
			if (a1->data <= b1->data) {
				tmp->link = a1;
				tmp = a1;
				a1 = a1->link;
			}
			else if (a1->data > b1->data) {
				tmp->link = b1;
				tmp = b1;
				b1 = b1->link;
			}
		}
		tmp->link = NULL;
		// display(newhead);
	}
	if (a1 != NULL) {
		tmp->link = a1;
	}
	else if (b1 != NULL) {
		tmp->link = b1;
	}
	return newhead;
}

void main() {
	ListNode* head1, * head2;
	head1 = NULL;
	head2 = NULL;

	// linked list a
	ListNode* p1;
	p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 1;
	p1->link = NULL;
	head1 = p1;

	ListNode* p2;
	p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 2;
	p2->link = NULL;
	p1->link = p2;

	ListNode* p3;
	p3 = (ListNode*)malloc(sizeof(ListNode));
	p3->data = 5;
	p3->link = NULL;
	p2->link = p3;

	ListNode* p4;
	p4 = (ListNode*)malloc(sizeof(ListNode));
	p4->data = 10;
	p4->link = NULL;
	p3->link = p4;

	ListNode* p5;
	p5 = (ListNode*)malloc(sizeof(ListNode));
	p5->data = 15;
	p5->link = NULL;
	p4->link = p5;

	ListNode* p6;
	p6 = (ListNode*)malloc(sizeof(ListNode));
	p6->data = 20;
	p6->link = NULL;
	p5->link = p6;

	ListNode* p7;
	p7 = (ListNode*)malloc(sizeof(ListNode));
	p7->data = 25;
	p7->link = NULL;
	p6->link = p7;


	// linked list b
	ListNode* p8;
	p8 = (ListNode*)malloc(sizeof(ListNode));
	p8->data = 3;
	p8->link = NULL;
	head2 = p8;

	ListNode* p9;
	p9 = (ListNode*)malloc(sizeof(ListNode));
	p9->data = 7;
	p9->link = NULL;
	p8->link = p9;

	ListNode* p10;
	p10 = (ListNode*)malloc(sizeof(ListNode));
	p10->data = 8;
	p10->link = NULL;
	p9->link = p10;

	ListNode* p11;
	p11 = (ListNode*)malloc(sizeof(ListNode));
	p11->data = 15;
	p11->link = NULL;
	p10->link = p11;

	ListNode* p12;
	p12 = (ListNode*)malloc(sizeof(ListNode));
	p12->data = 18;
	p12->link = NULL;
	p11->link = p12;

	ListNode* p13;
	p13 = (ListNode*)malloc(sizeof(ListNode));
	p13->data = 30;
	p13->link = NULL;
	p12->link = p13;

	printf("a = { "); display(head1); printf("}"); printf("\n");

	printf("b = { "); display(head2); printf("}"); printf("\n");

	printf("c = { "); display(merge(head1, head2)); printf("}");

} //Time complexity O(m+n)