#include "stdio.h"
#include "stdlib.h"

struct node{
	int info; // store data, numbers
	struct node *link; // [1711| x]->[122| x]->[3233| x]->[4244| x]
};

struct node *createList(struct node *start);
void displayList(struct node *start);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);

int main(){
	struct node *start = NULL;
	int choice, data, x, k;
	
	start = createList(start);
	
	while(1){
		printf("\n");
		printf("1. Display list.");
		printf("2. Quit");
		
		printf("\n Enter your choice:");
		scanf("%d", &choice);
		
		if(choice == 2){
			break;
		}
		
		switch(1){
			case 1:
				displayList(start);
				break;
		}
	}

	
	return 0;
}

struct node *createList(struct node *start){
	int i, n, data;
	
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	//Gaurd input validation
	if(n==0){ return start;}
	
	printf("Enter the first element to be inserted: ");
	scanf("%d", &data);
	start = insertInBeginning(start, data); // TODO implement insertInBeginning()
	
	for(i = 1; i<n; i++){
		printf("Enter the next element to be inserted: ");
		scanf("%d", &data);
		insertAtEnd(start, data); // TODO implement insertAtEnd()		
	}
	
	return start;
};/*end createList*/

struct node *insertInBeginning(struct node *start, int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	temp->link = start;
	start = temp;
	
	return start;
};/*end insertInBeginning*/


void insertAtEnd(struct node *start, int data){
	struct node *p, *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	
	p = start;
	while(p->link != NULL){
		p= p->link;
	}
	
	p->link = temp;
	temp->link = NULL;
	
}/*end insertAtEnd*/

void displayList(struct node *start){
	struct node *p;
	
	//Gaurd input validation
	if(start == NULL){
		printf("List is empty\n");
		return;
	}
	
	printf("List is :");
	p = start;
	while(p != NULL){
		printf("%d", p->info);
		p= p->link;
	}
	
}/*end display list*/









