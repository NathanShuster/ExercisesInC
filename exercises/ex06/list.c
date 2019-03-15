/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
  Node *curr = *list;
  if (curr != NULL) { //check if list isn't empty
    int val = curr->val; //get val to return
    *list = curr->next; //set head to next Node
    free(curr); //freeee mem
    return val;
  }
  return -1;

}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *new_node = malloc(sizeof(Node)); //allocated space
    new_node = make_node(val, NULL);
    Node *curr = *list;
    while (curr->next != NULL) { //run until you hit the last node
      curr = curr->next;
    }
    curr->next = new_node;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    // Two pointers, one to the current and one to the prev
    // Prev is so that we can reassign after
    Node* prev = NULL;
    Node* curr = *list;

    while(curr != NULL){
      if(curr->val == val){
        if (prev == NULL){
          *list = curr->next; //if node is first
        }
        else{
          prev->next = curr->next; //use pointers to skip current
        }
        free(curr); //freee mem
        return 1;
      }
      prev = curr;
      curr = curr->next;
    }
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
  //did this question a few times while preparing for interviews
  Node* prev = NULL;
  Node* curr = *list;
  Node* next = curr->next;
  while(next != NULL){
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  *list = curr;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
