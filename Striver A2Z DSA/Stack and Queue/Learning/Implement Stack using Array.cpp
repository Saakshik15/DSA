/*
Approach :

First, to implement stack using an array, we will be declaring an array of a pre-defined size.
Then, we will declare a variable called 'top', which can be used as the top of the stack.
  Initially, the value of top will be -1 as the stack is empty.
  
We will define the following operations for the class stack:
1. push(int x) : this operation will push an element to the top of the stack.
2. pop() : this operation will pop the top element of the stack.
3. top() : this operation will return the top element of the stack.
4. isEmpty() : this fuction will return true if the stack is empty, false otherwise.
5. isFull() : if the stack is full, this operation will return true, and false otherwise.
6. display() : this function will print all the elements of the stack.
*/
	
//Menu-driven code for implementation of stack:


#include<bits/stdc++.h>
using namespace std;

class Stack{
	int size;
	int *arr;
	int top;

public:
    Stack(int size) : size(size), top(-1) {
        arr = new int[size];  
    }
    
    void push(int x);
    int getTop();
    void pop();
    bool isEmpty();
    bool isFull();
    void display();
};

void Stack::push(int x){
    top++;
    arr[top] = x;
}
int Stack::getTop(){
	if(top == -1) return 0;
    return arr[top];
}
void Stack::pop(){
    arr[top]= 0;
    top--;
}
bool Stack::isEmpty(){
    if(top==-1) return true;
    return false;
}
bool Stack::isFull(){
    if(top==size-1) return true;
    return false;
}
void Stack::display(){
    for(int i=top; i>=0; i--)
        cout<<arr[i]<<"\n";
}

int main(){
    
    int n;
    cout<<"Enter stack size: ";
    cin>>n;
    int choice;
    
    Stack stk(n);
    
    do{
    	cout<<"\n\n\n____MENU____\n\n";
    	cout<<"Enter the operation you want to perform with the stack\n\n";
    	cout<<"1. Insert at top of the stack\n";
    	cout<<"2. Delete the top of the stack\n";
    	cout<<"3. Get top of the stack\n";
    	cout<<"4. Check if stack is empty\n";
    	cout<<"5. Check if the stack is full\n";
    	cout<<"6. Display all the elements of the stack\n";
    	cout<<"7. Exit";
    	cout<<"\n Enter your choice : ";
    	cin>>choice;
		
		switch (choice){
      
		  case 1 : 
			if(stk.isFull()){
				cout<<"Cannot Insert! The stack is full\n\n\n";
			}else{
				cout<<"Enter the element you want to insert: ";
				int ele;
				cin>>ele;
				stk.push(ele);
			} break;
		  case 2 : 
			if(stk.isEmpty()){
				cout<<"Cannot delete! Stack is already empty!!!\n\n\n";
			}else{
				cout<<"Deleted the top of the stack\n\n\n"; stk.pop();
			} break;
		  case 3 : 
      			cout<<"Top element of the stack is: "<<stk.getTop()<<"\n\n";
			break;
		  case 4: 
      			(stk.isEmpty()) ? cout<<"Stack is empty.\n" : cout<<"Stack is not empty\n\n\n";
			break;	
		  case 5 : 
      			(stk.isFull()) ? cout<<"Stack is full.\n" : cout<<"Stack is not full.\n\n\n";
			break;	
		  case 6 : 
      			cout<<"Elements of the stack are : \n"; stk.display();
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
