#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node *root = NULL;

void createLinkedList(int size){
	int i,num;
	struct node *temp;
	struct node *p;

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

int main(){
	
	int size;
	
	printf("Enter size: ");
	scanf("%d",&size);
	
	createLinkedList(size);
	printLinkedList();
	
	return 0;
}

