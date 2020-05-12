#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *root = NULL;

void insertFront(int num){
	if(search(num)==0){
			printf("\nData already exist. try again.\n");
		return;
	}
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->next =  root;
	root = temp;
}

void removeFront(){
	struct node *p;
	p = root;
	root = root->next;
	free(p);
}

void createLinkedList(int size){ // function to create linked list with specific size
	int i,num;
	struct node *temp,*p;

	for(i=0;i<size;i++){
		temp = (struct node*)malloc(sizeof(struct node));
	here:printf("Position no. %d: ",i);
		scanf("%d",&num);
		
		if(search(num)==0){
			printf("\nData already exist. try again.\n");
			goto here;
		}
	
		temp->data = num;
		temp->next = NULL;
		
		if(root == NULL)
			root = temp;
		else{
			p = root;
			while(p->next != NULL)
				p = p->next;
		p->next = temp;
		}
	}
}

void printLinkedList(){
	struct node *p = root;
	int pos = 0 ;
	while(p!=NULL){
		printf("\n\n\nPosition no. %d\n",pos++);
		printf("Data: %d\n",p->data);
		printf("Address: %x\n",p->next);
		p = p->next;
	}
}

int search(int data){
	struct node *p = root;
	while(p!=NULL){
		if(p->data == data)
			return 0;
		p = p->next;
	}
	return 1;
}


void insertAtPost(int pos, int num){
	int i;
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*p; // allocate nenory for temp node;
	
	if(pos==0)
		insertFront(num); // put the num in front
	else{
		temp->data = num;
		p = root;
		for(i=0;i<pos-1;i++)// iterate to find the position before the insertion point
			p = p->next;   
	temp->next= p->next; // getting the address of the next address for the node to be inserted
	p->next = temp;  // change to new address of the node that have been inserted
	}
}

void removeAtPos(int pos){
	if(pos==0)
		removeFront();
}

void menu(){
	printf("Linked List Operations\n");
	printf("1. Create Linked List\n");
	printf("2. Print Linked List\n");
	printf("3. Insert at Pos\n");
	printf("4. Insert at Front\n");
	printf("5. Remove at Pos\n");
	printf("6. Remove Item\n");
	printf("7. Remove Front\n");
	printf("8. Locate Index\n");
	printf("9. Locate item\n");
	printf("10. Sort (Ascending & Descending)\n");
	printf("11. Exit\n");
}


int main(){
	
	int size;
	
	menu();
	
	printf("Enter size: ");
	scanf("%d",&size);
	
	createLinkedList(size);
	printLinkedList();
	return 0;
}

