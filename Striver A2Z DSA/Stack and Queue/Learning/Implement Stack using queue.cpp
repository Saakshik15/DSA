/*
Problem Statement 1 :
Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, 
size and is empty operations are valid.
*/
/*
Approach :

Steps:
Initialize two empty queues

Operation : push(x)
1. Add x to Q2
2. Push all elements from Q1 to Q2 one by one
3. Swap the elements in Q1 and Q2.

Operation : pop()
1. Remove the top of Q1

This can be done for implementing stack using two queues.

time complexity of push operation : O(N)
space complexity : O(N)
*/

//Pseudo-code :

queue<int> Q1;
queue<int> Q2;

Push(x){
  Q2.push(x);
  while(!Q1.empty()){
    Q2.push(Q1.front());
    Q1.pop();
  }
swap(Q1, Q2);

pop(){
  Q1.pop();
}

top(){
  return Q1.front();
}

/*
Problem Statement 2:
Implement a Stack using a single Queue.

For implementing stack using only one queue, we can perform the following operations:

Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, 
hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.
*/

//pseudo-code :

push(x){
  Q1.push(x);
  for(int i=0; i<Q1.size()-1; i++){
    Q1.push(Q1.front());
  }
  Q1.pop();
}

pop(){
  Q1.pop();
}

top(){
  Q1.front();
}

//time complexity of push operation : O(N)
//space complexity : O(N)
