/*
Reverse a givenstack of N integers using recursion. You are required to make changes in the input parameter itself.
You are not allowed to use any extra space other than the internal stack space used due to recursion.
*/

/*
We will be using two recursive methods:
To Reverse the Stack: We will use recursion to iterate through the stack. For each top element, we will pop it and use recursion 
to reverse the remaining stack. After getting the stack reversed by recursion we can simply push the popped element to the bottom 
of the stack. The procedure to push the element at the bottom of stack is explained in following paragraph.
To Push an element to the Bottom of Stack: For this, we will be using recursion. Now to push a given element to the bottom of the stack, 
we will iterate through the stack recursively. For each top element, we will pop it and call recursion to insert a given element at the 
bottom of the remaining stack. After recursive function does its work and adds the given element to the bottom of stack, then we can 
simply push the popped element to the top of the stack.

Algorithm :
ReverseStack(stack)
If the stack is empty, then return
Pop the top element from the stack as top
Reverse the remaining elements in the stack, call reverseStack(stack) method
Insert the top element to the bottom of the stack, call InsertAtBottom(stack, top) method
InsertAtBottom(stack, ele)
If the stack is empty, push ele to stack, return
Pop the top element from the stack as top
Insert the ele to the bottom of the stack, call InsertAtBottom(stack, ele) method
Push top to the stack.
*/

//code :

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &stack, int ele) {
    if (stack.empty()) {
        // If the stack is empty, simply push the element
        stack.push(ele);
        return;
    }
    // If the stack is not empty, remove the top element
    int top = stack.top();
    stack.pop();
    // Recursively call insertAtBottom to insert the element at the bottom
    insertAtBottom(stack, ele);
    // Push the removed top element back onto the stack
    stack.push(top);
}
// Function to reverse the elements of the stack
void reverseStack(stack<int> &stack) {
    if (stack.empty())  return;
        // Base case: If the stack is empty, no elements to reverse
        
    // If the stack is not empty, remove the top element
    int top = stack.top();
    stack.pop();
    // Recursively call reverseStack to reverse the remaining elements
    reverseStack(stack);
    // After reversing the remaining elements, insert the removed top element at the bottom
    insertAtBottom(stack, top);
}

//Time Complexity: O(N^2)
//Space Complexity: O(N)
