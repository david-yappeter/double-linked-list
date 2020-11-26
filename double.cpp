#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	
	struct Node *next;
	struct Node *prev;
};

struct Node* InitializeNode(){
	return (struct Node*) malloc(sizeof(struct Node));
}

struct Node* CreateNode(int val) {
	struct Node *curr = InitializeNode();
	curr->val = val;
	curr->next = NULL;
	curr->prev = NULL;
	return curr;
}

void NodePushFront(struct Node **head, struct Node **tail, struct Node *curr){
	if((*head) == NULL){
		(*head) = (*tail) = curr;
	}
	else{
		(*head)->prev = curr;
		curr->next = (*head);
		(*head) = curr;
	}
}

void NodePushBack(struct Node **head, struct Node **tail, struct Node *curr){
	if((*head) == NULL){
		(*head) = (*tail) = (curr);
	}
	else{
		(*tail)->next = curr;
		curr->prev = (*tail);
		(*tail) = curr;
	}
}

void NodePopBack(struct Node **head, struct Node **tail){
	if((*head) == NULL){
		return;
	}
	else if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
	}
	else if((*head) != NULL){
		struct Node *curr = (*tail)->prev;
		(*tail) = NULL;
		free((*tail));
		(*tail) = curr;
		(*tail)->next = NULL;
	}
}

void NodePopFront(struct Node **head, struct Node **tail){
	if((*tail) == NULL){
		return;
	}
	else if((*head) == (*tail)){
		(*head) = (*tail) = NULL;
	}
	else if((*tail) != NULL){
		struct Node *curr = (*head)->next;
		(*head) = NULL;
		free((*head));
		(*head) = curr;
		(*head)->prev = NULL;
	}
}

void NodeInsertIndex(struct Node **head, struct Node **tail, struct Node *inserted, int index){
	if(index < 0){
		return;
	}
	if((*head) == NULL){
		NodePushBack(head, tail, inserted);
		return;
	}
	struct Node *curr = (*head);
	while(index--){
		if(curr == NULL){
			NodePushBack(head, tail, inserted);
			return;
		}
		curr = curr->next;
	}
	if(curr == (*head)){
		NodePushFront(head, tail, inserted);
		return;
	}
	curr->prev->next = inserted;
	inserted->prev = curr->prev;
	inserted->next = curr;
	curr->prev = inserted;
}

void NodeInsertSorted(struct Node **head, struct Node **tail, struct Node *inserted){
	if((*head) == NULL){
		(*head) = (*tail) = inserted;
	}
	else if(inserted->val <= (*head)->val){
		NodePushFront(head, tail, inserted);
	}
	else if(inserted->val >= (*tail)->val){
		NodePushBack(head,tail,inserted);
	}
	else{
		struct Node *curr = (*head);
		while(inserted->val > curr->val){
			curr = curr->next;
		}
		
		inserted->prev = curr->prev;
		inserted->next = curr;
		curr->prev->next = inserted;
		curr->prev = inserted;
	}
}

void NodeDeleteIndex(struct Node **head, struct Node **tail, int index){
	if(index < 0){
		return;
	}
	struct Node *curr = (*head);
	
	while(index--){
		if(curr == NULL){
			return;
		}
		curr = curr->next;
	}
	if(curr == (*head)){
		NodePopFront(head, tail);
	}
	else if(curr == (*tail)){
		NodePopBack(head, tail);
	}
	else{
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		curr = NULL;
		free(curr);	
	}
}

void PrintNodes(struct Node **head){
	while((*head) != NULL){
		printf("%d\n", (*head)->val);
		(*head) = (*head)->next;
	}
}

void PrintNodesReverse(struct Node **tail){
	while((*tail) != NULL){
		printf("%d\n", (*tail)->val);
		(*tail) = (*tail)->prev;
	}
}

bool SearchNode(struct Node **head, int value){
	while((*head) != NULL){
		if((*head)->val == value){
			return true;
		}	
		(*head) = (*head)->next;
	}
	
	return false;
}

int main(){
	
//// 	Initialization
//	struct Node *head = NULL;
//	struct Node *tail = NULL;
//
////	Add Node
//	struct Node *curr = CreateNode(1);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(2);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(3);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(4);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(5);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(6);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(9);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(12);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(100);
//	NodePushBack(&head, &tail, curr);
//	curr = CreateNode(200);
//	NodePushBack(&head, &tail, curr);
//
////	Insert sorted (like a set)
//	curr = CreateNode(3);
//	NodeInsertSorted(&head, &tail, curr);
//	curr = CreateNode(1);
//	NodeInsertSorted(&head, &tail, curr);
//	curr = CreateNode(200);
//	NodeInsertSorted(&head, &tail, curr);
//	
//
////	Delete At An Index
//	NodeDeleteIndex(&head, &tail, 1);
//	NodeDeleteIndex(&head, &tail, 1);
//	NodeDeleteIndex(&head, &tail, 1);
//	NodeDeleteIndex(&head, &tail, 1);
//	
//
////	Insert At Index
//	curr = CreateNode(9);
//	NodeInsertIndex(&head, &tail, curr, 0);
//	curr = CreateNode(8);
//	NodeInsertIndex(&head, &tail, curr, 8);
//	curr = CreateNode(11);
//	NodeInsertIndex(&head, &tail, curr, 5);
//
////	Pop Front & Pop Back
//	NodePopFront(&head, &tail);
//	NodePopBack(&head, &tail);
//
////	Print All Nodes From Head
//	curr = head;
//	PrintNodes(&curr);
//
////	Print All Nodes From Tail
//	curr = tail;
//	PrintNodesReverse(&curr);
	
	return 0;
}
