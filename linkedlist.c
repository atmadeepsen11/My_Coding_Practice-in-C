#include <stdio.h>
#include <stdlib.h>

struct Node* mergeList(struct Node* l, struct Node* r);
struct Node
{
	struct Node  *next, *prev;
	int val;
};

//inserting a node at the head
void insert(struct Node** head, int data)
{
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->val = data;
	newNode->next = *head;
	*head = newNode;
}

//creating a new node without head
struct Node* newNode(int data)
{
	struct Node* n = (struct Node *)malloc(sizeof(struct Node));
	n->val = data;
	n->next = NULL;
	return n;
}

//insert a node after a given node
void insertAfter(struct Node* node, int data)
{
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->val = data;
        newNode->next = node->next;
        node->next = newNode;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->val);
     node = node->next;
  }
}

//delete a specific node
struct Node* deleteNode(struct Node* head, int data)
{	
	struct Node* curr = newNode(0);
	curr->next = head;
	struct Node* p = curr;
		
	while(p != NULL && p->next != NULL)
        {
                if(p->next->val == data){
                        p->next = p->next->next;
                }
                else{
                        p = p->next;
                }
        }
	return curr->next;
/*
	while(curr != NULL && curr->next != NULL)
	{
		if(curr->next->val == data){
			curr->next = curr->next->next;
		}
		else{
			curr = curr->next;
		}
	}
*/
}

//printing the linklist in reverse order
void printReverse(struct Node* head)
{
    if (head == NULL)
       return;

    printReverse(head->next);
    printf("%d  ", head->val);
}

struct Node* getNext(struct Node* head, int data){
	struct Node* curr = head;
	while(curr->val != data){
		curr = curr->next;
	}
	return curr->next;
}
struct Node* getPrev(struct Node* head, int data){
	struct Node* curr = head;
	while(curr->next->val != data){
		curr = curr->next;
	}
	return curr;
}

//delete all occurence of the nodes with same key value
int main()
{
	struct Node* head = NULL;
	struct Node* p;
	struct Node* new = newNode(2);
	printf("%d \n", new->val);
	insert(&head, 8);
	insert(&head, 3);
	insert(&head, 6);
	insert(&head, 5);
//	insertAfter(head->next, 5);
//	p = deleteNode(head, 5);
//	sortList(head);
//	p = getNext(head, 6);
	p = getPrev(head, 8);
	printf("\n the next node is %d \n", p->val);
  	printf("\n Created Linked list is: \n");
//	printList(p);
	printf("\n");
//	printReverse(head);
//	printf("\n");
  	return 0;
}
