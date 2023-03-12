#include "Header.h"
#define len 1000

void File_read(Student students[student_num]) {
    FILE* fp = fopen("C:\\Users\\akmit\\source\\repos\\OP\\Lab05\\Katya_UwU\\Katya_UwU\\List.txt", "r");
    int symb;
    int counter = 0;
    char ir[len];
    while (!feof(fp)) {
        fscanf(fp, "%s", &students[counter].surname);
        fscanf(fp, "%s", &students[counter].name);
        fscanf(fp, "%s", &students[counter].date);
        students[counter].average = 0.0;
        for (int j = 0; j < amount_of_grades; j++) {
            fscanf(fp, "%d", &students[counter].grade[j]);
            students[counter].average += students[counter].grade[j];
        }
        students[counter].average /= amount_of_grades;
        counter++;
    }
    fclose(fp);
}

void setup_list(Node** head, Student student) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->value = student;
    *head = node;
}

void add_node(Node* head, Student student) {
    Node* last;
    Node* newNode = (Node*)malloc(sizeof(Node));
    get_last(head, &last);
    newNode->next = NULL;
    newNode->value = student;
    last->next = newNode;
}

void get_last(Node* head, Node** source) {
    while (head->next != NULL) {
        head = head->next;
    }
    *source = head;
}


void new_student_value(Student* new_student) {
    printf("Enter student`s surname: ");
    scanf("%s", &new_student->surname);
    printf("Enter student`s name: ");
    scanf("%s", &new_student->name);
    printf("Enter student`s birthday: ");
    scanf("%s", &new_student->date);
    new_student->average = 0.0;
    for (int j = 0; j < amount_of_grades; j++) {
        printf("Enter student`s %d grade: ", j + 1);
        scanf("%d", &new_student->grade[j]);
        new_student->average += new_student->grade[j];
    }
    new_student->average /= amount_of_grades;
}


void sort_list(Node* head) {
    Node* p1 = head;

    while (p1->next) {
        Node* p2 = p1->next;

        while (p2) {
            if (p1->value.average > p2->value.average) {
                Student tmp = p1->value;
                p1->value = p2->value;
                p2->value = tmp;
            }

            p2 = p2->next;
        }
        p1 = p1->next;
    }
}

void remove_node(Node* head) {

    if (grades_counter(head)) {
        *head = *(head->next);
    }

    while (head->next) {
        if (grades_counter(head->next)) {
            Node* tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        }
        else head = head->next;
    }
}

int grades_counter(Node* head) {
    int counter = 0;
    for (int j = 0; j < amount_of_grades; j++) {
        if (head->value.grade[j] == 2)
            counter++;
    }
    if (counter == 2)
        return 1;
    else
        return 0;
}


void print_list(Node* head) {

    printf("\n%-15s %-15s %-15s\t\t\t%-20s\t\t\t%s\n", "Surname", "Name", "Date", "Grades", "Average");
    while (head) {
        printf("\n%-20s\t%-15s\t%-15s", head->value.surname, head->value.name, head->value.date);
        for (int j = 0; j < amount_of_grades; j++) {
            printf("%d\t", head->value.grade[j]);
        }
        printf("\t%f\n", head->value.average);
        head = head->next;
    }
}