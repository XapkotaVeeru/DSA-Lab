#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node *insertBeforePosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);

    if (head == NULL || position <= 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    struct Node *current = head;
    int currentPosition = 1;

    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

struct Node *insertAfterPosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (head == NULL || position < 1) {
        return newNode;
    }

    struct Node *current = head;
    int currentPosition = 1;

    while (currentPosition < position && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }

    current->next = newNode;
    return head;
}

struct Node *deleteAtBeginning(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    free(head);
    printf("Deleted the first node.\n");
    return newHead;
}

struct Node *deleteAtEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(current);
    printf("Deleted the last node.\n");
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (position <= 1) {
        return deleteAtBeginning(head);
    }

    struct Node* current = head;
    int currentPosition = 1;
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL) {
        printf("Position not found. Cannot delete.\n");
        return head;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Deleted node at position %d.\n", position);
    return head;
}

void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    do {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a position\n");
        printf("4. Insert after a position\n");
        printf("5. Delete at the beginning\n");
        printf("6. Delete at the end\n");
        printf("7. Delete at a position\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert before: ");
                scanf("%d", &position);
                head = insertBeforePosition(head, data, position);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert after: ");
                scanf("%d", &position);
                head = insertAfterPosition(head, data, position);
                break;
            case 5:
                head = deleteAtBeginning(head);
                break;
            case 6:
                head = deleteAtEnd(head);
                break;
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 8:
                displayList(head);
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    struct Node *current = head;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
