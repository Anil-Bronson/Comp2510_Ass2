#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SinglyLL.h" // Ensure this file contains the definition for struct Node

/**
 * Inserts a new node with the given patient name at the beginning of the list.
 *
 * @param head Pointer to the head pointer of the linked list.
 * @param newPatientName The name of the patient to insert.
 */
void insertAtBeginning(struct Node** head, const char *newPatientName) {
    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the patient name to the node and ensure null termination
    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0';

    // Link the new node to the current head and update the head pointer
    newNode->next = (*head);
    (*head) = newNode;
}

/**
 * Inserts a new node with the given patient name at the end of the list.
 *
 * @param head Pointer to the head pointer of the linked list.
 * @param newPatientName The name of the patient to insert.
 */
void insertAtEnd(struct Node** head, const char *newPatientName) {
    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the patient name to the node and ensure null termination
    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0';
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse the list to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the new node to the end of the list
    temp->next = newNode;
}

/**
 * Inserts a new node with the given patient name at a specified position.
 *
 * @param head Pointer to the head pointer of the linked list.
 * @param newPatientName The name of the patient to insert.
 * @param index The position (1-based) where the new node should be inserted.
 */
void insertAtMid(struct Node** head, const char *newPatientName, const int index) {
    if (index <= 0) {
        printf("Invalid position.\n");
        return;
    }

    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the patient name to the node and ensure null termination
    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0';
    newNode->next = NULL;

    // Special case: inserting at the beginning
    if (index == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to the node before the desired position
    struct Node* current = *head;
    for (int i = 1; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Check if the position is out of bounds
    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return;
    }

    // Insert the new node at the desired position
    newNode->next = current->next;
    current->next = newNode;
}

/**
 * Deletes a node at a specified position from the linked list.
 *
 * @param head Pointer to the head pointer of the linked list.
 * @param index The position (1-based) of the node to delete.
 */
void deleteAtPosition(struct Node** head, const int index) {
    if (index <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // Special case: deleting the head node
    if (index == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse to the node before the one to be deleted
    struct Node* prev = NULL;
    for (int i = 1; i < index && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Check if the position is out of bounds
    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    // Remove the node from the list and free its memory
    prev->next = temp->next;
    free(temp);
}

/**
 * Prints the linked list from the head to the last node.
 *
 * @param head Pointer to the head of the linked list.
 */
void printList(struct Node* head) {
    struct Node* temp = head;

    // Traverse the list and print each node's data
    while (temp != NULL) {
        printf("%s -> ", temp->patientName);
        temp = temp->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}

/**
 * Main function to test the singly linked list operations.
 *
 * @return Exit code (0 for success).
 */
int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, "John");
    insertAtBeginning(&head, "Brian");
    insertAtBeginning(&head, "Anneliese");

    // Print the current list
    printList(head);

    // Insert a node at position 2
    insertAtMid(&head, "Anil", 2);
    printList(head);

    // Delete the node at position 3
    deleteAtPosition(&head, 3);
    printList(head);

    return 0;
}
