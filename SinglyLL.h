#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char patientName[20];
    struct Node* next;
};

void insertAtBeginning(struct Node** head, const char *newPatientName);
void insertAtEnd(struct Node** head, const char *newPatientName);
void insertAtMid(struct Node** head,const char *newPatientName, int index);
void deleteAtPosition(struct Node** head, int index);

#ifndef SINGLYLL_H
#define SINGLYLL_H

#endif //SINGLYLL_H
