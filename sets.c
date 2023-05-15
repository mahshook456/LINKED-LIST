#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	};

struct Node* head1=NULL;
struct Node* head2=NULL;
struct Node* intersection_head=NULL;
struct Node* union_head=NULL;

// Function to insert an element in linked list
void insert(int x, struct Node** headptr){
	struct Node* temp= (struct Node*) malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=*headptr;
	*headptr=temp;
}

// Function to insert elements in linked list
void print(struct Node* headptr){
    struct Node* temp = headptr;
	printf("The elements are: ");
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}

// Function to search an element in linked list
int search(struct Node* head, int x) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            return 1; // element found
        }
        temp = temp->next;
    }
    return 0; // element not found
}



int main(){
	int i,n,x,m;

	// Reading the 1st set
	printf("Enter the number of elements in the 1st set: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("Enter the number: ");
		scanf("%d",&x);
		insert(x, &head1);

	}


	// Reading the second set
	printf("\nEnter the number of elements in the 2nd set: ");
	scanf("%d", &m);
	for(i=0;i<m;i++){
		printf("Enter the number: ");
		scanf("%d",&x);
		insert(x, &head2);

	}



	// Finding the intersection of the sets
	struct Node *temp1 = head1;
    while (temp1 != NULL) {
        struct Node *temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data && search(intersection_head,temp1->data)==0) {
                insert(temp1->data, &intersection_head);
                break;  // no need to continue searching in this list
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }



    // Finding the union of the sets
    struct Node *temp3 = head1;
    while (temp3 != NULL) {
        if (search(union_head,temp3->data)==0) {
                insert(temp3->data, &union_head);
            }
            temp3 = temp3->next;
    }
    struct Node *temp4 = head2;
    while (temp4 != NULL) {
        if (search(union_head,temp4->data)==0) {
            insert(temp4->data, &union_head);
            }
            temp4 = temp4->next;
    }


    printf("\n1st  :: ");
    print(head1);

    printf("\n2nd  :: ");
    print(head2);

    printf("\nIntersection:: ");
    print(intersection_head);

    printf("\nUnion:: ");
    print(union_head);



	return 0;

}
