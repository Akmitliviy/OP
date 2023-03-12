#include "Header.h"

int main() {
    Node* head = NULL;

    Student students[student_num];

    File_read(students);

    setup_list(&head, students[0]);
    for (int i = 1; i < student_num; i++)
        add_node(head, students[i]);

    sort_list(head);



    Student new_student;
    new_student_value(&new_student);
    add_node(head, new_student);

    sort_list(head);

    remove_node(head);

    print_list(head);

    return 0;
}