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
	system("cls");
	struct node *p = root;
	int pos = 0 ;
	while(p!=NULL){
		printf("\n\nPosition no. %d\n",pos++);
		printf("Data: %d\n",p->data);
		printf("Address: %x\n",p->next);
		p = p->next;
	}
	getch();
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


void insertAtPost(int pos, int num,int size){
	int i;
	struct node *temp = (struct node*)malloc(sizeof(struct node)),*p; // allocate nenory for temp node;
	
	if(pos==0)
		insertFront(num); // put the num in front
	else if(pos<0 || pos > size)
		printf("Invalid. Try again!");
	else if(pos == size){
		temp->data = num;
		temp->next = NULL;
		p = root;
			while(p->next != NULL)
				p = p->next;
		p->next = temp;
	}
	else{
		temp->data = num;
		p = root;
		for(i=0;i<pos-1;i++)// iterate to find the position before the insertion point
			p = p->next;   
	temp->next= p->next; // getting the address of the next address for the node to be inserted
	p->next = temp;  // change to new address of the node that have been inserted
	}
}

void removeAtPos(int pos,int size){
	struct node *p,*l;
	
	if(pos==0)
		removeFront();
		
	for(i=0;i<pos-1;i++)
		p = p->next;	
	
}

void menu(){
	system("cls");
	printf("Linked List Operations\n");
	printf("A. Create Linked List\n");
	printf("B. Print Linked List\n");
	printf("C. Insert at Pos\n");
	printf("D. Insert at Front\n");
	printf("E. Remove at Pos\n");
	printf("F. Remove Item\n");
	printf("G. Remove Front\n");
	printf("H. Locate Index\n");
	printf("I. Locate item\n");
	printf("J. Sort (Ascending & Descending)\n");
	printf("X. Exit\n");
}

char select(char c){
	printf("\nEnter your choice: ");
	fflush(stdin);
	scanf("%c",&c);
	return toupper(c);
}

int main(){
	
	int size,pos,num;
	char opt;
	
	while(1){
		menu();
		opt = select(opt);
		
		switch(opt){
			case 'A':
				printf("Enter Size: ");
				scanf("%d",&size);
				createLinkedList(size);
				break;
			case 'B':
				printLinkedList();
				break;
			case 'C':
				printf("Enter value: ");
				scanf("%d",&num);
				printf("Enter position: ");
				scanf("%d",&pos);
				insertAtPost( pos, num,size);
				break;
			case 'D':
				printf("Enter value: ");
				scanf("%d",&num);
				insertFront(num);
				break;
			case 'E':
				break;
			case 'F':
				break;
			case 'G':
				break;
			case 'H':
				break;
			case 'I':
				break;
		}
	}
	return 0;
}

