/*
Problem statement:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

/*
Approach 1: Using pairs to store the value and minimum element till now. 

We will be using a stack of pairs in order to store the elements of the stack to make it easier to retrieve minimum element.
We will thus be storing the element given by the push operation and minimum element in the stack till now in pair. ie, (x, min).
The first element in the pair will store the value and the second element will store the minimum element till now.
When the first push operation comes in we will push the value and store it as minimum itself in the pair. 
In the second push operation, we will check if the top element’s minimum is less than the new value. If it is then we will 
push the value with minimum as the previous top’s minimum. To get the getMin element to take the top’s second element.
*/

//code :

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

//time complexity : O(1)
//space complexity : O(2N)


/*
Approach 2 : optimized approach

Declare a variable that stores the minimum number. SO, whenever a push operation is called, we will check if the number to be pushed
is lesser than the current min and update the min variable accordingly.

Push operation : 
Now if there is a push operation, check is the number is smaller than min we will push a modified value which is apush(2 * Val – min)
into the stack and will update min to the value of the original number. If it’s not then we will just push it as it is.

getMin() operation:
We will just return the value of stored min.

Pop operation:
While performing pop we will check if the top value is lesser than min, If it is then we must update min to its previous value
using min = (2 * min) – (top) and we will pop the element.

top operation : 
before returning top we will check if the top value is lesser than min, If it is then we must update min to its previous value 
by min = (2 * min) – (top) and we will return the top element.
*/

//code :

class MinStack {
public:

    stack<long long> stk;
    long long mini;

    MinStack() {}
    
    void push(int val) {
        long long x= val;
        if (stk.empty()) {
            mini = x;
            stk.push(x);
        }
        else if (x < mini) {
            stk.push(2 * x - mini);
            mini = x;
        }
        else
            stk.push(x);
    }
    
    void pop() {
        if (stk.empty()) return;
    
        long long t = stk.top();
        stk.pop();
 
        if (t < mini) mini = 2 * mini - t;    
    }
    
    int top() {
        if (stk.empty()) return -1;
 
        long long t = stk.top(); 
        return (t < mini) ? mini : t;
    }
    
    int getMin() {
        if(stk.empty()) return -1;
        return (long long)mini;
    }
};

//time complexity : O(1)
//space complexity : O(N)
