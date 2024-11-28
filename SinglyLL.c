#include <stdio.h>
#include <stdlib.h>
#include "SinglyLL.h"


// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, const char *newPatientName) {
    struct Node* newNode = malloc(sizeof(struct Node));

    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0'; // Ensure null termination

    newNode->next = (*head);
    (*head) = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head,  const char *newPatientName) {

    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Copy the string into the patientName array
    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0'; // Ensure null termination
    newNode->next = NULL;

    // If head is NULL, it is an empty list
    if (*head == NULL) {
        *head = newNode;
    }

    // Traverse to the end of the list and insert the new node
    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtMid(struct Node** head, const char *newPatientName, const int index) {

    if (index <= 0) {
        printf("Invalid position.\n");
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Copy the string into the patientName array
    strncpy(newNode->patientName, newPatientName, sizeof(newNode->patientName) - 1);
    newNode->patientName[sizeof(newNode->patientName) - 1] = '\0'; // Ensure null termination
    newNode->next = NULL;

    // If inserting at the beginning
    if (index == 1) {
        newNode->next = *head;
        *head = newNode;
    }

    struct Node* current = *head;

    // Traverse to the node just before the desired position
    for (int i = 1; i < index && current != NULL; i++) {
        current = current->next;
    }

    // If the position is out of bounds
    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
    }

    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtPosition(struct Node** head, const int index) {

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (index <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if(*head == NULL) {
        printf("Linked list is empty. \n");
        return;
    }

    //case 1: head is to be deleted
    if(index == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    //case 2: node is deleted from the middle of the list
    for (int i = 1; i < index && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        printf("Position is out of bounds.\n");
    }

}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->patientName);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // original = value , & reference ; change the original value; null will be replaced with 1,2...
    // value: original ; and add more values; null, 1,2 ......
    insertAtBeginning(&head, "John");
    insertAtBeginning(&head, "Brian");
    insertAtBeginning(&head, "Anneliese");
    printList(head);
    insertAtMid(&head, "Anil", 2);
    printList(head);
    deleteAtPosition(&head, 3);
    printList(head);
    return 0;
}
