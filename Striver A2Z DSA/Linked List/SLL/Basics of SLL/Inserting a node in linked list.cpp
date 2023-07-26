/*
Problem statement :
For a given Singly LinkedList, insert a node at the beginning of the linked list.

Example 1:
Input: List = 10->20->30->40->null, Node = 0
Output: 0->10->20->30->40->null
Explanation: Inserted the given node at the beginning of the linked list.

Example 2:
Input: List = 100->200->300->null, Node =700
Output: 700->100->200->300->null
Explanation: Inserted the given node at the beginning of the linked list.
*/

/*
Inserting a Node at the beginning of LinkedList is 3 step Process
Step 1: First create a node with a value that is to be inserted at the beginning of LinkedList.
Step 2: Point the next of the newly created Node to the head of the LinkedList.
Step 3: As the node is inserted at the beginning of LinkedList, this is the first Node in LinkedList. 
  So point the head of the LinkedList to the newly created Node.
*/

//code :

Node* insertAtFirst(Node* head, int newValue) {
    
    Node* temp = new Node(newValue);
    temp->next = head;
    head = temp;

    return head;
}
