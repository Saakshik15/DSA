/*
Approach :

First, to implement queue using an array, we will be declaring an array of a pre-defined size.
Then, we will declare variables called 'rear' and 'front', which can be used as the insertion and deletion points of the queue respectively.
  Initially, the value of rear and front bot will be -1 as the queue is empty.
  
We will define the following operations for the class stack:
1. push(int x) : this operation will push an element to the queue from the rear.
2. pop() : this operation will pop the element at the front of the queue.
3. top() : this operation will return the rear element of the queue.
4. isEmpty() : this fuction will return true if the queue is empty, false otherwise.
5. isFull() : if the queue is full, this operation will return true, and false otherwise.
6. display() : this function will print all the elements of the queue fron front to rear.
*/
	
//Menu-driven code for implementation of queue:

#include<bits/stdc++.h>
using namespace std;

class Queue{
	int size;
	int *arr;
	int front;
	int rear;

public:
    Queue(int size) : size(size), front(-1), rear(-1) {
        arr = new int[size];  
    }
    
    void push(int x);
    int getTop();
    void pop();
    bool isEmpty();
    bool isFull();
    void display();
};

void Queue::push(int x){
	if(rear==-1 && front ==-1) front++;
    rear++;
    arr[rear] = x;
}
int Queue::getTop(){
	if(rear == -1 || rear<front) return 0;
    return arr[rear];
}
void Queue::pop(){
    arr[front]= 0;
    front++;
}
bool Queue::isEmpty(){
    if(rear==-1 || rear<front) return true;
    return false;
}
bool Queue::isFull(){
    if(rear==size-1) return true;
    return false;
}
void Queue::display(){
    for(int i=front; i<=rear; i++)
        cout<<arr[i]<<" ";
}

int main(){
    
    int n;
    cout<<"Enter Queue size: ";
    cin>>n;
    int choice;
    
    Queue que(n);
    
    do{
    	cout<<"\n\n\n____MENU____\n\n";
    	cout<<"Enter the operation you want to perform with the Queue\n\n";
    	cout<<"1. Insert from rear of the queue\n";
    	cout<<"2. Delete from the front of the queue\n";
    	cout<<"3. Get rear of the queue\n";
    	cout<<"4. Check if queue is empty\n";
    	cout<<"5. Check if the queue is full\n";
    	cout<<"6. Display all the elements of the queue\n";
    	cout<<"7. Exit";
    	cout<<"\n Enter your choice : ";
    	cin>>choice;
		
		switch (choice){
      
		  case 1 : 
			if(que.isFull()){
				cout<<"Cannot Insert! The queue is full\n\n\n";
			}else{
				cout<<"Enter the element you want to insert: ";
				int ele;
				cin>>ele;
				que.push(ele);
			} break;
		  case 2 : 
			if(que.isEmpty()){
				cout<<"Cannot delete! Queue is already empty!!!\n\n\n";
			}else{
				cout<<"Deleted from the front of the queue\n\n\n"; que.pop();
			} break;
		  case 3 : 
      			cout<<"Rear element of the queue is: "<<que.getTop()<<"\n\n";
			break;
		  case 4: 
      			(que.isEmpty()) ? cout<<"Queue is empty.\n" : cout<<"Queue is not empty\n\n\n";
			break;	
		  case 5 : 
      			(que.isFull()) ? cout<<"Queue is full.\n" : cout<<"Queue is not full.\n\n\n";
			break;	
		  case 6 : 
      			cout<<"Elements of the Queue are : \n"; que.display();
			break;	
		  case 7 : 
      			cout<<"exiting...";
			break;	
		  default : 
      			cout<<"Enter a valid choice!!!\n";
		} 
	}while(choice!=7);
    return 0;
}
