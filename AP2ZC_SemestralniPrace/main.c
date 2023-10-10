// Importing libraries
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>

// Defining struct named node with parameters position and pointer to next node
struct node {
    int coordinate;
    struct node *next;
};

// Defining alias for struct node
typedef struct node node_t;

// Pointer on head is given value NULL
node_t *head = NULL;

// Function for adding new node to Linked List
node_t *createNewNode(int coordinate) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->coordinate = coordinate;
    newNode->next = NULL;
    return newNode;
}

// Function for inserting pointer to new head at start of Linked List
node_t *insertAtHead(node_t *head, node_t *newNode) {
    newNode->next = head;
    return newNode;
}

// Function for recursively printing Linked List
void recursivePrint(node_t *head) {
    if (head != NULL) {
        printf("%d ", head->coordinate);
        recursivePrint(head->next);
    } else {
        printf("\n\n");
    }
}

// Function for sum of all powered nodes of Linked List
int sumOfAllNodes(node_t *head) {
    if (head != NULL) {
        int result = pow(head->coordinate, 2) + sumOfAllNodes(head->next);
        return result;
    } else {
        return 0;
    }
}

// Function for calculating size of vector
float sizeOfVector(node_t *head) {
    float result = sqrt(sumOfAllNodes(head));
    return result;
}

// Main function
int main() {
    // Defining all coordinates (node_t)
    node_t *head = NULL;
    node_t *y1;
    node_t *x2;
    node_t *y2;

    // Inserting coordinates to nodes
    y1 = createNewNode(0);
    head = insertAtHead(head, y1);
    x2 = createNewNode(7);
    head = insertAtHead(head, x2);
    y2 = createNewNode(8);
    head = insertAtHead(head, y2);

    // Printing of function results
    printf("Given Linked List: ");
    recursivePrint(head);
    printf("Size of vector is %f", sizeOfVector(head));

    // Asserting of all values
    assert(head->next->next->coordinate == 0);
    assert(head->next->coordinate == 7);
    assert(head->coordinate == 8);
    assert(sumOfAllNodes(head) == 113);
    assert(sizeOfVector(head) == 10.630146);

    return 0;
}
