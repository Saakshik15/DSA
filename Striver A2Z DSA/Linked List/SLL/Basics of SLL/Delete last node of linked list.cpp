/*
Problem Statement: Given a Singly LinkedList, Delete the Last Node in the LinkedList.

Example 1:
Input: List = 10->20->30->40->null
Output: 10->20->30->null
Explanation: Deleted the last node of the linked list.

Example 2:
Input: List = 100->200->300->null
Output: 100->200->null
Explanation: Deleted the last node of the linked list
*/

/*
Deletion of Last Node in Singly LinkedList is 3 step process.

Step 1: Find the last Node and second Last Node of the LinkedList. To Find the Nodes, take two ListNode pointers let’s say prev, curr. 
Initially curr points to the head and prev points to the Null. Move the curr and prev pointers ahead in the LinkedList until the curr 
reaches the last Node. 
Next of the Last Node points to null, If for any node it’s next is null, then it is the last node in LinkedList.
After step1 curr points to the last node and prev points to the second Last Node in LinkedList.

Step 2: We need to remove the Last node, so break the link connecting the LastNode with List. In order to break the link, make prev→next = NULL

Step 3: Delete the curr Node, which means the Last Node.
*/

//code 1 :

//if there is no node in the linked list
if (head == nullptr) return 0;

//if head is the only node 
if (head -> next == nullptr) {
    delete head;
    head = nullptr;
} else {
  //other cases 
  ListNode* curr = head, *prev = nullptr;
  while (curr -> next != nullptr) {
    prev = curr;
    curr = curr -> next;
  }
}
prev -> next = nullptr;
delete curr;


//code 2: (other way using a single pointer temp)
Node *deleteLast(Node *head){
 
    Node* temp= head;

    while(temp->next->next){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}














