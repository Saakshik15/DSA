/*
Problem statement: Given an infix expression, convert it into a postfix expression.
*/

/*
We will be using a stack to convert a given infix expression to postfix expression.

We will use the following procedure in order to convert the infix expression to postfix expression.

Traversing the infix expression, we will use the following algorithm:
there are following cases that an operand can be:
( :
  In case the character encountered is '(' , we will simply push it onto the stack.
Operand : 
  In case it is an operand, we will simply print it.
) : 
  In case the character encountered is ')' we will pop characters from the stack until we encounter '(' and pop it.
Operator : 
  In case the encountered character is an operator, we will check if:
  1. if the stack is empty, we will push the operator.
  2. else : compare the current operator with the operator on the top of the stack
    if the current operator has higher precedance than top of the stack, 
        push the currnt operator on the stack.
    else if the current operator has lower or equal precedance than top of the stack,
        Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator
  3. If the expression is traversed fully, keep popping from the stack till the stack is empty.
*/


//code :

//function to find precedance of operators
int prec(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string InfixToPostfix(string s){
  stack<char> stk;
  string result;

//traversing the string
  for (int i = 0; i < s.length(); i++){

    //if the character is opening bracket, push it onto the stack
      if(s[i] == '(') 
          stk.push(s[i]);

    //if the character is an operand, append it to the result
      else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
          result += s[i];

    //if the character is a closing bracket, pop all the characters from the stack until we encounter an opening bracket
      else if (s[i] == ')') {
          while (stk.top() != '(') {
            result += stk.top();
            stk.pop();
          }
        //finally, pop the opening bracket as well
          stk.pop();
        }
        
    //else if the character encountered is an operator, check its precedance
    //if the precedance of the current operator is less than or equal to the top of stack, pop the operators
    else {
        while (!stk.empty() && prec(s[i]) <= prec(stk.top())) {
          result += stk.top();
          stk.pop();
        }
      //finally after popping the operators with higher precedance, push the current operator onto the stack
        stk.push(s[i]);
      }
//pop all remaining elements from the stack until the stack is not empty
  while (!stk.empty()) {
    result += stk.top();
    stk.pop();
  }
    return result;
}

      
