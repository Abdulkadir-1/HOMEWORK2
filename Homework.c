#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student *next;
} Student;

// Function to create a new node with the given data
Node* create_node(int data) {
    Node new_node = (Node)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node to the end of the list
void add_to_end(Node **head, int data) {
    Node *new_node = create_node(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to add a node to the beginning of the list
void add_to_beginning(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to sort the list in descending order
void sort_list(Node **head) {
    Node *i, *j;
    for(i = *head; i != NULL && i->next != NULL; i = i->next) {
        for(j = i->next; j != NULL; j = j->next) {
            if(i->data < j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Function to print the list
void print_list(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Function to create a student
Student* create_student(int number, char *name, int age) {
    Student new_student = (Student)malloc(sizeof(Student));
    new_student->number = number;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = NULL;
    return new_student;
}

// Function to print all students
void print_students(Student *head) {
    Student *temp = head;
    int count = 1;
    while(temp != NULL) {
        printf("%d- %s %d %d\n", count, temp->name, temp->age, temp->number);
        temp = temp->next;
        count++;
    }
}

// Function to search a student by name
Student* search_by_name(Student *head, char *name) {
    Student *temp = head;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
}

// Function to delete the next node of a given node
void delete_next_node(Student *node) {
    if(node == NULL || node->next == NULL)
        return;
    Student *next_node = node->next;
    node->next = next_node->next;
}

// Function to print the student with the longest name
void print_longest_name(Student *head) {
}
