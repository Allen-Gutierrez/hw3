#include "llrec.h"
#include <iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    
    // Base Case For Recursion: Stops when it reaches the end of the list 
    if (head == NULL) { 
        smaller = NULL; // return NULL if head is NULL
        larger = NULL; // return NULL if head is NULL
        return; // ends function
    }
    

    // Store the next node to continue recursion
    Node* temp_node = head;
    head = head -> next; // moves head to next spot 

    // Recursively call to process the next node
    llpivot(head, smaller, larger, pivot);

    // Insert the val into the smaller list if less than or equal to pivot
    if (temp_node->val <= pivot) {
        temp_node->next = smaller;  // Point the current node to the front of the smaller list
        smaller = temp_node;  // Move the smaller list's head to the current node
    } 
    else {
        temp_node->next = larger;  // Point the current node to the front of the smaller list
        larger = temp_node;        // Move the smaller list's head to the current node
    } 
    
  
}
