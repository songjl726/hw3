#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  // first check if smaller and larger are garbage values
  // if they are, tset them to nullptr AND THEN call the recursive function
  if (smaller != nullptr || larger != nullptr){
    smaller = nullptr;
    larger = nullptr;
  }
  
  llpivotHelper(head, smaller, larger, pivot);
}

void llpivotHelper(Node*& head, Node*& smaller, Node*& larger, int pivot){
  // check if the linked list is empty (base case)
  if (head == nullptr){
    return;
  }

  // save the value of the next Node from the original list for later
  Node* temp = head->next;

  if(head->val <= pivot){
    // if the current value is less than/equal to the pivot, add the current Node to the beginning of smaller and update smaller to point to its new first element
    // this preserves the original order that the elements were in
    head->next = smaller;
    smaller = head;
  } else {
    // if the current value is greater than the pivot, add current Node to the beginning of larger and update larger to point to its new first element
    // again, this preserves the original order the elements were in
    head->next = larger;
    larger = head;
  }
  
  head = temp;

  llpivotHelper(head, smaller, larger, pivot);
}