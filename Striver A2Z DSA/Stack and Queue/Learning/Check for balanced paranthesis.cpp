/*
Problem Statement:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

/*
Since the last bracket that is opened must also be the first one to be closed, it makes sense to use a data structure 
that uses the Last In, First Out (LIFO) principle. Therefore, a stack is a good choice here.

If a bracket is an opening bracet, we'll just push it on to the stack. If it's a closing bracket, then we'll check if it's the correct 
type of bracket (first pop the last opening bracket encountered, find the corresponding closing bracket, and compare it with the 
current bracket in the loop). If the wrong type of closing bracket is found, then we can exit early and return False.

If we make it all the way to the end and all open brackets have been closed, then the stack should be empty. 
This will return True if the stack is empty, and False if it's not.
*/


//code :

bool isValid(string s) {
        
  stack<char> stk;

    for(int i=0; i<s.size(); i++){
        char ch= s[i];

        if(s[i]=='(' || s[i]=='[' || s[i] =='{') 
            stk.push(s[i]);
        else {
            if(!stk.empty()){
                char top = stk.top();
                if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top == '{')) 
                    stk.pop();
                else 
                    return false;
            }
            else return false;
        }
    }
return stk.empty();
}

