#include <stdio.h>
#include <stdlib.h>

/* Node structure for linked list */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Function to add a new node at the beginning of the linked list */
void addNode(Node** headRef, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

/* Function to swap two nodes in the linked list */
void swapNodes(Node* prev1, Node* node1, Node* prev2, Node* node2) {
    prev1->next = node2;
    prev2->next = node1;
    Node* temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}

/* Function to perform bubble sort on a linked list */
void bubbleSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;  // Linked list is empty or has only one node
    }
    int swapped;
    Node* node;
    Node* prev = NULL;
    do {
        swapped = 0;
        node = head;
        while (node->next != prev) {
            if (node->data > node->next->data) {
                swapNodes(prev, node, node, node->next);
                swapped = 1;
            }
            prev = node;
            node = node->next;
        }
    } while (swapped);
}

/* Function to print the linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Main function to test bubble sort on linked list */
int main() {
    Node* head = NULL;
    addNode(&head, 4);
    addNode(&head, 2);
    addNode(&head, 1);
    addNode(&head, 3);
    printf("Original linked list: ");
    printList(head);
    bubbleSort(head);
    printf("Sorted linked list: ");
    printList(head);
    return 0;
}
