#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  // first check if smaller and larger are garbage values
  // if they are, tset them to nullptr AND THEN call the recursive function
  smaller = nullptr;
  larger = nullptr;
  
  llpivotHelper(head, smaller, larger, pivot);

  head = nullptr;
}

void llpivotHelper(Node*& head, Node*& smaller, Node*& larger, int pivot){
  // check if the linked list is empty (base case)
  if (head == nullptr){
    return;
  }

  if(head->val <= pivot){
    // if the current value is less than/equal to the pivot, add the current Node to the beginning of smaller and update smaller to point to its new first element
    // this preserves the original order that the elements were in
    smaller = head;
    head = head->next;
    llpivotHelper(head, smaller->next, larger, pivot);
  } else {
    // if the current value is greater than the pivot, add current Node to the beginning of larger and update larger to point to its new first element
    // again, this preserves the original order the elements were in
    larger = head;
    head = head->next;
    llpivot(head, smaller, larger->next, pivot);
  }
}