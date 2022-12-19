/*
Написати програму, яка реалізує побудову дерева за заданим кодом Прюфера. Етапи розв'язання задачі виводити на екран.

Алгоритм побудови дерева за заданим кодом Прюфера (розпакування коду Прюфера дерева):
Вхід: Масив int А[n-1] of 1..n - код Прюфера дерева Т.
Вихід: Дерево Т(V, Е), задане множиною ребер Е, вершини дерева пронумеровані числами 1..n.
E= ; // спочатку множина ребер порожня;
B=1..n; // множина невикористаних номерів вершин;
for (i=1; i<=n-1; i++) {
v=min (k B && j  i : k! A[ j]);
// вибираємо вершину v – невикористану вершину з найменшим номером, який не зустрічається в коді Прюфера
;
E = E + (v, A[i]); // додаємо ребро (v, A[i]);
B = B - v;         // вилучаємо вершину v зі списку невикористаних;
}
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define N 100
void TakeInput(int array[N], int* size);
int i = 0;

struct Node {
    int value;
    struct Node* next;
};

void CreateNodeListFromArr(struct Node first, int A[], int n);
void CreateNodeList(struct Node** first, int sizeP);

void ShowList(struct Node* p);
int MinNode(struct Node* first);
void RemoveItemInList(struct Node** first, int position);
void PruferCode(struct Node* firstP, struct Node* firstV, int sizeP, int PArr[]);
void deleteNode(struct Node** head_ref, int key);
void DeleteFirstNode(struct Node** head);
void delete_first_node(struct Node** head);

int main(void)
{
    // int P[N] = {0};
    // int size1 = 0;
    // TakeInput(P, &size);

    struct Node* P = NULL;
    struct Node* V = NULL;

    int sizeP = 10, sizeV = 0;
    int PArr[N] = { 1, 9, 1, 8, 1, 7, 1, 6, 1, 5 };
    PruferCode(P, V, sizeP, PArr);
    // struct Node *M = NULL;
    // CreateNodeList(&M, sizeP);
    // int min = MinNode(M);
    // RemoveItemInList(&M, min);
    // ShowList(M);

    return 0;
}

void TakeInput(int array[N], int* size) {
    printf("Enter number of elements in array: ");
    scanf("%d", size);
    printf("Set values of matrix:\n");

    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
}

void CreateNodeList(struct Node** first, int sizeP) {
    int n = sizeP + 2;
    struct Node* fnNode, * last;
    int value = 1, i;
    *first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *first;

    if (temp == NULL) {
        printf(" Memory can not be allocated.");
    }

    else {
        temp->value = value;
        (*first)->next = NULL;
        last = temp;

        // Creating n nodes and adding to linked list
        for (i = 2; i <= n; i++) {
            fnNode = (struct Node*)malloc(sizeof(struct Node));
            if (fnNode == NULL) {
                printf(" Memory can not be allocated.");
                break;
            }
            else {
                value++;
                fnNode->value = value;
                fnNode->next = NULL;
                last->next = fnNode;
                last = last->next;
            }
        }
    }
    ShowList(temp);
}

void CreateNodeListFromArr(struct Node** first, int A[], int sizeP) {
    int i;
    *first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fnNode = NULL;
    struct Node* last = *first;
    struct Node* temp = *first;

    if (temp == NULL) {
        printf("Memory can not be allocated.");
    }

    temp->value = A[0];
    (*first)->next = NULL;

    for (i = 1; i < sizeP; i++) {
        fnNode = (struct Node*)malloc(sizeof(struct Node));
        if (fnNode == NULL) {
            printf("Memory can not be allocated.");
            break;
        }
        else {
            fnNode->value = A[i];
            fnNode->next = NULL;
            last->next = fnNode;
            last = fnNode;
        }
    }
    ShowList(temp);
}

void ShowList(struct Node* first)
{
    while (first != NULL)
    {
        printf("%d ", first->value);
        first = first->next;
    }
    printf("\n");
}

int MinNode(struct Node* first)
{
    int min = 100;
    while (first != NULL)
    {
        if (min > first->value)
            min = first->value;
        first = first->next;
    }
    return min;
}

void PruferCode(struct Node* firstP, struct Node* firstV, int sizeP, int PArr[]) {
    CreateNodeListFromArr(&firstP, PArr, sizeP);
    CreateNodeList(&firstV, sizeP);

    int num = sizeP + 2, null = 0, k = 0, i = 0;
    int minElement = 0, newV[N] = { 0 };
    struct Node* tempP = firstP;
    struct Node* tempV = firstV;
    struct Node* newTempV = tempV;
    // struct Node *tempVDel = firstV;

    minElement = MinNode(tempV);
    while (tempP != NULL) {     // 12 iteration
        k = 0;
        while (tempP != NULL) {
            if (minElement == tempP->value)
                k++;
            tempP = tempP->next;
        }
        tempP = firstP;

        if (k != 0) {
            newTempV = newTempV->next;
            minElement = newTempV->value;
            continue;
        }
        else {

            newV[i] = minElement;
            deleteNode(&tempV, minElement);
            deleteNode(&tempP, tempP->value);
            firstP = tempP;
            // delete_first_node(&tempVDel);
            i++;
            minElement = MinNode(tempV);
            newTempV = tempV;
        }
    }
}

void delete_first_node(struct Node** head) {
    struct Node* tmp;
    if (head == NULL || *head == NULL) return;
    tmp = *head;

    *head = (*head)->next;
    free(tmp);
}


void deleteNode(struct Node** first, int value)
{
    struct Node* temp = *first, *prev = NULL;

    // If head node itself holds the value to be deleted
    if (temp != NULL && temp->value == value) {
        *first = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    // Search for the value to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

// func for delete iten in lisst by index

// void RemoveItemInList(struct Node **first, int position) {
//     struct Node* temp = NULL;
//     struct Node* prev = NULL;
//     temp = *first;
//     prev = *first;
//     for (int i = 0; i < position; i++) {
//         if (i == 0 && position == 1) {
//             *first = (*first)->next;
//             free(temp);
//         }
//         else {
//             if (i == position - 1 && temp) {
//                 prev->next = temp->next;
//                 free(temp);
//             }
//             else {
//                 prev = temp;

//                 if (prev == NULL)
//                     break;
//                 temp = temp->next;
//             }
//         }
//     }
// }


void RemoveItemInList(struct Node** first, int value) {
    if (*first != NULL) {
        struct Node* temp = *first;

        if (temp->value == value) {
            struct Node* deleted = temp;
            *first = temp->next;
            free(temp);
            return;
        }

        while (1) {
            if (temp->next == NULL) {
                temp = temp->next;
                if (temp->next->value == value) {
                    break;
                }
                continue;
            }
            else {
                printf("element was not found in the list");
                return;
            }
        }

        struct Node* deleted = temp->next;

        if (temp->next->next != NULL) {
            temp->next = temp->next->next;
            free(deleted);
        }
        else {
            temp->next = NULL;
        }
    }

    else {
        printf("There is no element in list.\n");
    }

}