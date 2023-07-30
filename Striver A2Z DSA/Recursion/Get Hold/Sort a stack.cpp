/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.
*/

/*
Approach : recursive 

First, we will hold all values in a Call Stack until the stack becomes empty.
When the stack becomes empty, insert all held items one by one(from the call stack) in sorted order.
We will do this by using a function sortedInsert() which will sort these elements.
In the sortedInsert() function we will first check if the stack is empty and if the current element is greater than the top element of the stack, if these conditions are met then we push that current element to the stack.
Then we pop the top element of the stack and again recursively call the stack with the remaining elements.
Now we push the earlier top element which we popped in step 5 back into the stack.
Finally, we will print our sorted stack.
*/

//code : (recursive)

void sortedInsert(stack<int> &stack, int current) {
    	if (stack.empty() || current > stack.top()){
    		stack.push(current);
    		return;
    	}
    	// Remove the top element
    	int top = stack.top();
    	stack.pop();
    	// Recursion for the remaining elements in the stack
    	sortedInsert(stack, current);
    	// Insert the popped element back in the stack
    	stack.push(top);
}

// Recursive method to sort a stack
void sortStack(stack<int> &stack){
    	// Base case: stack is empty
    	if (stack.empty()) return;
    
    	// Remove the top element
    	int top = stack.top();
    	stack.pop();
    	// Recursion for the remaining elements in the stack
    	sortStack(stack);
    	// Insert the popped element back in the sorted stack
    	sortedInsert(stack, top);
}

//Time Complexity : O(N^2), where N is the number of elements in the stack. 
//Space Complexity : O(N), where N is the number of elements in the stack. 

