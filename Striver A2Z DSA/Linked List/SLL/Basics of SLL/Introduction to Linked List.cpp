/*
Linked List is a linear data structure, in which elements are not stored at a contiguous location, 
rather they are linked using pointers. Linked List forms a series of connected nodes, where each node 
stores the data and the address of the next node.


Node Structure: A node in a linked list typically consists of two components:
Data: It holds the actual value or data associated with the node.
Next Pointer: It stores the memory address (reference) of the next node in the sequence.
Head and Tail: The linked list is accessed through the head node, which points to the first node in the list. 
The last node in the list points to NULL or nullptr, indicating the end of the list. This node is known as the tail node.

Definition of linked list:

  class Node {

  public:
      int data;
      Node* next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node* next) : data(x), next(next) {}
  };
  
*/

/*
Problem Statement : 
Given an array arr of size N consisting of positive integers.
Make a linked list from the array and return the head of the linked list.
The head of the linked list is the first element of the array and tail is the last element.
*/

//code :

Node* constructLL(vector<int>& arr) {
    
    Node* temp = new Node(arr[0]);
    Node* head = temp;

    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}


  
