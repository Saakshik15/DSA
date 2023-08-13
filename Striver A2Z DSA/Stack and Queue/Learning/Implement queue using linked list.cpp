/*
Problem statement: implement a queue data structure using a linked list.
*/

/*
To implement Queue using a linked list, we will use two pointers, front and rear.
Initially, when there are no nodes in the linked list, both front and rear will be pointing to NULL.
When we add elements in the linked list, they will be added at the end of the list and rear will be the end of the list.
Front will be pointing to the head of the linked list.
For finding if the queue is empty, initially, when front is pointing to NULL, queue will be empty, and after deleting all the elements of
the queue, front will be pointing to the next node of rear, which is NULL, thus queue will be empty.
Thus, we can conclude that queue is empty when front is poiting to NULL.
In the peek() operation, we will return the front of the linked list.
*/

//code for implementation of queue using a linked list :

//Definition of linked list
class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

//Definition of Queue
struct Queue {
  Node* front;
  Node* rear;
  void push(int);
  int pop();
  
  Queue() {
    front = rear = NULL;
  }
};

Node*front = NULL;
Node*rear = NULL;

void Queue::push(int x) {

    Node * newNode = new Node(x);
    if(front==NULL){
        front  = newNode;
        rear = front;
        return;
    }
    rear->next= newNode;
    rear=rear->next;
    return;
}

int Queue::pop() {
    if(front==NULL)return -1;
    
    int ans = front->data;
    Node *temp = front->next;
    front->next = NULL;
    delete front ;
    front = temp;
    return ans;
}
