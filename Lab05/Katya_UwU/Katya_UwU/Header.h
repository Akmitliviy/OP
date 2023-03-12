#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define student_num 25
#define amount_of_grades 6

#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

typedef struct StudentSt {
    char surname[50];
    char name[50];
    char date[20];
    int grade[amount_of_grades];
    float average;
} Student;

typedef struct NodeSt {
    struct StudentSt value;
    struct NodeSt* next;

} Node;

void File_read(Student students[student_num]);
void setup_list(Node** head, Student student);
void add_node(Node* head, Student student);
void get_last(Node* head, Node** source);
void sort_list(Node* head);
void remove_node(Node* head);
void new_student_value(Student* new_student);
void print_list(Node * head);
