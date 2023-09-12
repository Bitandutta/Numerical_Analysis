// c   all credits goes to cutest priyanka <3

#include<stdio.h>
#include<stdlib.h>

typedef struct information{
	int id;
	float salary;
	struct information *next;
}node;

void insert(node **head, node **tail, int i, float s){
//	**head = add of head pointer
//	*head = head pointer
//	head = add of the head node
	
	// creating a new node
	node *n;
	n = (node*)malloc(sizeof(node));
	// inserting data into the newnode
	n->id=i;
	n->salary=s;
	n->next=NULL;
	// insertion
	if(*head==NULL && *tail==NULL){ // first time
		*head=n;
		*tail=n;
	}
	else {
		(*tail)->next=n;
		(*tail)=n;
	}
}

void display(node *t){
	while(t != NULL){
		printf("\nID: %d", t->id);
		printf("\nSalary: %f\n", t->salary);
		t=t->next;
	}
}

int search(node *h, int target){
	while(h!=NULL) {
		if(h->id == target)
			return 1;
		h=h->next;
	}
			
	return 0;
}

int del(node **head, node **tail, int i){
	if(*head==NULL) return 0;
	
	node *t = *head;
	if(i==0){ // delete head node
		*head = (*head)->next; // next node is made head node
		free(t); // old head node is deleted
		
		if(*head==NULL) *tail=NULL;
		return 1;
	}
	else{
		node *lastT;
		while(i>0){
			lastT=t;
			t=t->next;
			i--;
			if(t==NULL) return 0;
		}
		if(t->next == NULL){ // t is last block
			lastT->next=NULL;
			*tail=lastT;
			free(t); // t node deleted
		}
		else { // t is not last block
			lastT->next=t->next;
			free(t);
		}
		return 1;
	}
}

int main(){
	
	//  head points to first node
	node *head=NULL, *tail=NULL;
	// tail points to last node
	
	int i, id, no;
	float sal;
	printf("Enter number of employee: ");
	scanf("%d", &no);
	
	for(i=1; i<=no; i++){
		printf("Enter employee %dth id: ", i);
		scanf("%d", &id);
		printf("Enter employee  %dth salary: ", i);
		scanf("%f", &sal);
		insert(&head, &tail, id, sal);
	}
	printf("The created linked list is:\n");
	display(head);
	
	printf("\nEnter id to search: ");
	scanf("%d", &id);
	
	if( search(head, id) ) printf("Found\n");
	else printf("Not found!\n");
		
	printf("\nEnter block no to delete: ");
	scanf("%d", &i);
	
	if( del(&head, &tail, i) ){
		printf("After deleting the %d th block\n", i);
		display(head);
	}
	else printf("%d th block doesn't exist", i);
	
	
	return 0;
}
