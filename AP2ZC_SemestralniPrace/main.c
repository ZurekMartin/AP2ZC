#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <assert.h>

/**
 * Defining struct named node with parameters position and pointer to next node
 */
struct node {
    int coordinate;
    struct node *next;
};

/**
 * For easier typing we can use node_t which is alias for struct node
 */
typedef struct node node_t;

/**
 * Pointer on head is given value NULL
 */
node_t *head = NULL;

/**
 * Function which add new node to linkedlist
 * @param coordinate it represents coordinate value (int)
 * @return newNode (node_t)
 */
node_t *createNewNode(int coordinate) {
    node_t *newNode = malloc(sizeof(node_t));
    newNode->coordinate = coordinate;
    newNode->next = NULL;
    return newNode;
}

/**
 * Function which is inserting pointer to new head at start of linkedlist
 * @param head current pointer on head of linkedlist (node_t)
 * @param newNode new pointer on head of linkedlist(node_t)
 * @return newNode (node_t)
 */
node_t *insertAtHead(node_t *head, node_t *newNode){
    newNode->next = head;
    return newNode;
}

/**
 * Function which recursively print linkedlist
 * @param head pointer on head of linked list (node_t)
 * @return without return (void)
 */
void recursivePrint(node_t *head) {
    if (head != NULL) {
        printf("%d ", head->coordinate);
        recursivePrint(head->next);
    } else {
        printf("\n\n");
    }
}

/**
 * Function which sum all of powered nodes of linkedlist
 * @param pointer on head of linked list (node_t)
 * @return result sum of all powered nodes (int)
 */
int sumOfAllNodes(node_t *head)
{
    if ( head != NULL ) {
        int result = pow(head->coordinate, 2) + sumOfAllNodes(head->next);
        return result;
    }
    else{
        return 0;
    }
}

/**
 * Function which calculate size of vector
 * @param head pointer on head of linked list (node_t)
 * @return result size of vector (float)
 */
float sizeOfVector(node_t *head){
    float result = sqrt(sumOfAllNodes(head));
    return result;
}

int main() {
    /**
    * Defining all coordinates (node_t)
    */
    node_t *head = NULL;
    node_t *y1;
    node_t *x2;
    node_t *y2;

    /**
    * Filling all nodes with coordinate values
    */
    y1 = createNewNode(0);
    head = insertAtHead(head, y1);
    x2 = createNewNode(7);
    head = insertAtHead(head, x2);
    y2 = createNewNode(8);
    head = insertAtHead(head, y2);

    printf("Zadany linkedlist: ");
    recursivePrint(head);
    printf("Velikost vektoru je %f", sizeOfVector(head));

    /**
    * Asserting of all values
    */
    assert(head->next->next->coordinate == 0);
    assert(head->next->coordinate == 7);
    assert(head->coordinate == 8);
    assert(sumOfAllNodes(head) == 113);
    assert(sizeOfVector(head) == 10.630146);

    return 0;
}
