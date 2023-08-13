/*
Problem statement : Implement a stack data structure using a linked list.
*/

/*
Why to represent stack as a linked list:
When the size of the stack is not known in advanced, we can represent a stack using a linked list.
In linked list representation of stack, there is no limitation on how many nodes we can create unless heap memory is not full.

We should prefer the beginning of the linked list, i.e., head of the linked list as top of the stack. Because,
For push operation, new node will be inserted to the stack at the head of the linked list for which time complexity is O(1), 
which is better than inserting at the end of the linked list.
Also, for pop operation, it takes O(1) constant time to pop the head of the linked list and for finding the top of the stack it takes O(1).
But, if we take the end of the linked list as the top of the stack, push() and top() operations will take O(1) constant time, 
but pop() operation will take O(N) time. Thus, beginning of the linked list as the top is preferred.
*/

//code for implementation :

//clas for Node
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

//class for stack
class Stack{
    Node* top = NULL;

public:
    Stack(){}

    int getSize(){
        Node* temp= top;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp= temp->next;
        }
        return cnt;
    }

    bool isEmpty(){
        if(top==NULL) return true;
        return false;
    }

    void push(int x){
        Node* temp = new Node(x);
        if(top==NULL){
            top = temp;
        }else{
            temp->next=top;
            top=temp;
        }
    }

    void pop(){
        if(top) top=top->next;
    }

    int getTop(){
        if(!top) return -1;
        return top->data;
    }
};

