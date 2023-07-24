/*
Problem Statemenet :

whenever you find a valid parenthesis within the string, remove the outer parenthesis of the valid parenthesis.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/

//solution :

//code :

//using brute force approach :

    string removeOuterParentheses(string s) {
        int cnt=0;
        string res;

        for(auto ch : s){
            if(cnt==0 && ch == '(') cnt--;
            else if(cnt == -1 && ch ==')') cnt++;
            else{
                res.push_back(ch);
                if(ch == '(') cnt--;
                else cnt++;
            }
        }
        return res;
    }

//using stack 

/*
Approach :

This is a solution to the problem of removing outermost parentheses from a string containing only parentheses.

The approach used is to keep track of the parentheses using a stack. Whenever an opening parenthesis is encountered, 
it is pushed onto the stack. Whenever a closing parenthesis is encountered, the last opening parenthesis is popped from the stack.

If the stack size is greater than zero after pushing or popping, it means that the parenthesis is not an outer parenthesis, 
and it is added to the result string. If the stack size is zero, it means that the parenthesis is an outer parenthesis and it 
is not added to the result string.

*/

//code :
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string str= "";

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                if(stk.size()>0){
                    str+=(s[i]);
                }
                stk.push(s[i]);
            }else{
                stk.pop();
                if(stk.size()>0){
                    str+=(s[i]);
                }
            }
        }
        return str;
    }

/*
Time complexity:
The time complexity of this solution is O(n), where n is the length of the input string. 
This is because each character in the string is processed once and the push and pop operations on the stack take O(1) time each.

Space complexity:
The space complexity of this solution is O(n), where n is the length of the input string. 
This is because the maximum size of the stack is n/2 (if all the parentheses are opening parentheses), 
and in the worst case, the result string can also have a size of n/2.
*/
















  
