#include <algorithm>

#include "Heap.h"

Heap::Heap() {
  numItems = 0; 
}

/*Inserts a PrintJob to the heap without
violating max-heap properties.*/
void Heap::enqueue (PrintJob* job) {
  int index = numItems;

  if (numItems < MAX_HEAP_SIZE) {
     // inserts PrintJob pointer obj into array @ index numItems
    arr[index] = job; 
    // increments numItems
    ++numItems; 
    // arranges so that array does not violate max-heap properties 
    MaxHeapPercolateUp(index);
  }
}

/*Removes the node with highest priority from the heap. 
Follow the algorithm on priority-queue slides. */
void Heap::dequeue ( ) {

  if (numItems == 1) {
    arr[0] = 0; 
    numItems = 0; 
    return;
  }
  else if (numItems > 1) {
    arr[0] = arr[numItems - 1]; 
    --numItems;
    trickleDown(0);
  }

}

/*Returns the node with highest priority.*/
PrintJob* Heap::highest() {

  if (numItems == 0) {
    return 0;
  }

  return arr[0]; 
}

/*Prints the PrintJob with highest priority in the following format:
Priority: priority, Job Number: jobNum, Number of Pages: numPages
(Add a new line at the end.)*/
void Heap::print () {
  PrintJob *highPriority;

  if (numItems == 0) {
    return;
  }

  highPriority = highest();

  cout << "Priority: " << highPriority->getPriority() << ", Job Number: "
    << highPriority->getJobNumber() << ", Number of Pages: " << highPriority->getPages()
    << endl; 
}

/*This function is called by dequeue function
to move the new root down the heap to the 
appropriate location.*/
void Heap::trickleDown(int value) {

  for (int i = 0; i < numItems; ++i) {
    if (arr[value]->getPriority() <  arr[i]->getPriority()) {
      swap(arr[value], arr[i]);
      // PrintJob *tmp = arr[value];
      // arr[value] = arr[i];
      // arr[i] = tmp; 
    }
  }
}

void Heap::MaxHeapPercolateUp(int nodeIndex) {
  int parentIndex;

  while (nodeIndex > 0) {
    parentIndex = (nodeIndex - 1) / 2;
    
    if (arr[nodeIndex]->getPriority() <= arr[parentIndex]->getPriority()) {
      return;
    }
    else {
      swap(arr[nodeIndex], arr[parentIndex]);
      nodeIndex = parentIndex;
    }
  }
}

/*
TEST CASE:
1
98 50 22
1
49 47 14
1
77 44 55
1
32 22 60
1
88 80 33
2 
1
85 80 33
1
98 37 10
2
4

should print: 98 50 22
*/
