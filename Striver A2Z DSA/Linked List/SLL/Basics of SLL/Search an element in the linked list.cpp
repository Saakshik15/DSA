/*
Problem statement : given a singly linked list of integers with a head pointer.
Every node of the linked list has a value.
Now, given an integer value K, check if a node with value K exists in the linked list.
Return 1 if node exists else return 0.
*/

//code :

int searchInLinkedList(Node<int> *head, int k) {

    Node<int>* temp = head;
    
    while(temp != NULL){
        if(temp->data == k) return 1;
        temp= temp->next;
    }
    return 0;
}
