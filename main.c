#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=dti0F7w3yOQ

typedef struct {
	void *next;
	int data;
} Node;

Node *head = NULL;

//add
Node *addNode(int data) {
	Node *new = NULL;
	new = malloc(sizeof(Node));
	if (new == NULL)
		return NULL;

	if (head == NULL)
		new->next = NULL;
	else
		new->next = head;

	new->data = data;
	head = new;

	return new;
}

//remove
int removeNode(int data) {
	Node *curr = head;
	Node *prev = head;
	while (curr != NULL) {
		if (curr->data == data) {
			if (curr == head) {
				head = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr);
			curr = NULL;
			return 0;
		}
		prev = curr;
		curr = curr->next;
	}
	printf("Out of range");
	return 1;
}

//insert
Node *insertNode(int data, int pos) {
	Node *curr = head;
	if (curr == head && pos == 0) {
		Node *new = malloc(sizeof(Node));
		new->data = data;
		head = new;
		return new;
	}

	while (curr->next != NULL) {
		if (pos != 0) {
			curr = curr->next;
			pos -= 1;
		}
	}

	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = curr->next;
	curr->next = new;
	return new;
}

//print
void printList() {
	Node *current = head;
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;
	}
	printf("\n");
	return;
}

//printMenu
void printMenu() {
	printf("1. Add a node\n");
	printf("2. Remove a node\n");
	printf("3. Insert a node\n");
	printf("4. Get node data\n");
	printf("5. Quit\n");
}

int main(int argc, char** argv) {

/*	if (argc == 2) {
		switch (&argv) {
			case 'a':
				printf("a");
				break;
		}
	}
*/

	Node *new = NULL;
	int option = -1;
	int option2 = 0;
	int option3 = 0;
	while (option != 5) {
		printMenu();
		int num_received = scanf("%d", &option);
		if (num_received != 1) {
			printf("Improper Input!\n");
			printf("Quitting...\n");
			return 1;
		}
		switch (option) {
			case 1:
				printf("Data to be added:\n");
				scanf("%d", &option2);
				new = addNode(option2);
				break;
			case 2:
				printf("Data to be removed:\n");
				scanf("%d", &option2);
				removeNode(option2);
				break;
			case 3:
				printf("Data to be inserted:\n");
				scanf("%d", &option2);
				printf("Position to insert:\n");
				scanf("%d", &option3);
				new = insertNode(option2, option3);
				if (new == NULL) {
					printf("Failed to insert\n");
				}
				break;
			case 4:
				printList();
				break;
			case 5:
				printf("Quitting...\n");
				break;
			default:
				printf("Improper input\n");
				break;
		}
	}

	return 0;
}
