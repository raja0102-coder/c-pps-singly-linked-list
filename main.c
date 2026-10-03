#include <stdio.h>
#include <stdlib.h>

// Self-referential structure definition for a Linked List Node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node dynamically on the Heap
Node* createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("[ERROR] Memory allocation for node failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert Node at the Beginning of the List
void insertAtBeginning(Node **headRef, int value) {
    Node *newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
    printf("    [INSERT HEAD] Added value %d to beginning.\n", value);
}

// 2. Insert Node at the End of the List
void insertAtEnd(Node **headRef, int value) {
    Node *newNode = createNode(value);
    
    if (*headRef == NULL) {
        *headRef = newNode;
        printf("    [INSERT TAIL] List was empty. Added value %d as head.\n", value);
        return;
    }

    Node *temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("    [INSERT TAIL] Added value %d to end.\n", value);
}

// 3. Delete a Node by Value
void deleteNode(Node **headRef, int target) {
    if (*headRef == NULL) {
        printf("    [DELETE] List is empty. Cannot delete %d.\n", target);
        return;
    }

    Node *temp = *headRef;
    Node *prev = NULL;

    // Target is head node
    if (temp != NULL && temp->data == target) {
        *headRef = temp->next;
        free(temp);
        printf("    [DELETE] Node with value %d deleted from head.\n", target);
        return;
    }

    // Search for the target node
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    // Target not found
    if (temp == NULL) {
        printf("    [DELETE] Value %d not found in list.\n", target);
        return;
    }

    // Unlink the node from linked list and free memory
    prev->next = temp->next;
    free(temp);
    printf("    [DELETE] Node with value %d deleted.\n", target);
}

// 4. Print the entire Linked List
void printList(Node *head) {
    printf("    List Traversal: ");
    if (head == NULL) {
        printf("[ EMPTY LIST ]\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("[%d | *] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 5. Free all dynamic memory allocations in the list
void freeList(Node **headRef) {
    Node *current = *headRef;
    Node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *headRef = NULL;
    printf("\n    [CLEANUP] Entire linked list memory freed successfully.\n");
}

int main() {
    Node *head = NULL; // Initialize empty linked list

    printf("==================================================\n");
    printf("     PPS SINGLY LINKED LIST & NODAL ENGINE        \n");
    printf("==================================================\n\n");

    // 1. Building the Linked List
    printf("[1] BUILDING LINKED LIST:\n");
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    printf("\n");

    // 2. Displaying the List
    printf("[2] DISPLAYING CURRENT LINKED LIST:\n");
    printList(head);
    printf("\n");

    // 3. Node Deletion Operations
    printf("[3] DELETION OPERATIONS:\n");
    deleteNode(&head, 10); // Delete head node
    deleteNode(&head, 30); // Delete middle node
    deleteNode(&head, 99); // Non-existent value check
    printf("\n");

    printf("[4] FINAL LINKED LIST STATE:\n");
    printList(head);

    // 4. Memory Cleanup
    freeList(&head);

    printf("\n==================================================\n");

    return 0;
}
