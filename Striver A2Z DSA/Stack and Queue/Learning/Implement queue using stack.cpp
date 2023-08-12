/*
Problem statement 1 :

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a 
normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

You must use only standard operations of a stack, which means only push to top, peek/pop from top,size, and is empty operations are valid.
*/

/*
Approach 1 : brute force appraoch

To implement a queue using two stacks, first initialize two stacks, namely s1 and s2.
Now, in order to perform the push and pop operations, perform the following steps:

For push(int x) :
1. Push all the elements of stack s1 one by one to s2.
2. Push x to s1.
3. Push all the elements of s2 one by one to s1.

For pop():
1. s1.pop()

For top():
1. s1.top()

In this way, we can implement a queue using two stacks.

time complexity for the push operation in this case is O(N)
space complexity for push operation is approximately O(2N)
*/

//code from leetcode for approach 1:

class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // Transfer all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element onto s1
        s1.push(x);
        // Transfer all elements from s2 back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


/*
Approach 2: optimal approach

to reduce the time complexity of the push operation to O(1), we can perform the following operations to implement queue using two stacks:

initialize two stacks named input and output
Now, in order to perform the push and pop operations, perform the following steps:

push(int x):
1. push int x to input stack

pop():
if output stack is NOT empty:
  output.pop()
else if output stack is empty:
  push all elements of input stack to output stack one by one.
  output.pop()

top():
if output stack is NOT empty:
  return output.top();
else if output stack is empty:
  push all elements of input stack to output stack one by one
  return output.top();

Now, in these cases, the time complexity of the push operation is reduced to O(1),
but the time complexity of the pop and top operations is is increased to O(N) in worst case,
but amortized time complexity (which is, in most cases) is O(1) for pop and top operations as well.
*/

//pseudo-code for second approach :

push(int x){
  input.push(x);
}

pop(){
  if(!output.empty()) 
    output.pop();
  else
    while(!input.empty()){
      output.push(input.top());
      input.pop();
    }
  output.pop();
}

top(){
  if(!output.empty())
    output.top();
  else{
    while(!input.empty()){
      output.push(input.top());
      input.pop();
    }
  output.top();
  }
}

//code from leetcode for approach 2:

class MyQueue {

    stack<int> input, output;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int a= output.top();
            output.pop();
            return a;
        }
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int a=output.top();
            output.pop();
            return a;
        }
        return -1;
    }
    
    int peek() {
        if(!output.empty())
            return output.top();
        else{
            while(!input.empty()){
            output.push(input.top());
            input.pop();
            }
        return output.top();
        }
        return -1;
    }
    
    bool empty() {
        return output.empty() && input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



