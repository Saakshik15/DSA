/*
Problem statement : find the maximum number of levels of nested parentheses in a given string. 
Nesting depth refers to how many levels of parentheses are enclosed within each other. 
Count the maximum number of levels of nesting in the given string and return that value as the answer.
*/

/*
Approach 1 : using stack

Initialize an empty stack called stk to keep track of opening parentheses encountered in the string.
Initialize an integer variable cnt to 0, which will store the maximum nesting depth found so far.
Iterate through each character ch in the input string s.
If ch is an opening parenthesis '(', push it onto the stack to indicate a new level of nesting.
If ch is a closing parenthesis ')', pop an opening parenthesis from the stack, indicating the completion of a nesting level.
After pushing '(', check if the current stack size (number of opening parentheses encountered so far) is greater than 
the current maximum nesting depth cnt. If so, update cnt to the current stack size.

After processing all characters, return the maximum nesting depth cnt.
*/

//code :

int maxDepth(string s) {
        stack<int> stk;
        int cnt=0;
        
        for(ch: s){
            if(ch == '('){
                stk.push(ch);
                if(stk.size()>cnt)
                    cnt= stk.size();
            }
            else if(ch == ')'){
                stk.pop();
            }
        }
        return cnt;
    }

//time complexity : O(N)
//space complexity : O(N)

/*
Approach 2 : using counter variable

Initialize an integer variable count to 0. 
This variable will keep track of the current nesting depth while iterating through the characters in the string.
Initialize an integer variable ans to the minimum possible integer value (INT_MIN). 
This variable will store the maximum nesting depth found so far.

Iterate through each character s[i] in the input string s.
If the current character s[i] is an opening parenthesis '(', increment the count variable. 
This indicates the start of a new nesting level.
If the current character s[i] is a closing parenthesis ')', decrement the count variable. 
This indicates the completion of a nesting level.
After processing each character, update the ans variable to the maximum value between the current ans and the count. 
This step keeps track of the maximum nesting depth encountered during the iteration.

After processing all characters, return the ans variable, which holds the maximum nesting depth found in the given string.
*/


//code :

int maxDepth(string s) {
        
        int count=0;
        int ans=INT_MIN;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='(')count++;
            else if(s[i]==')')count--;
            ans=max(ans,count);
        }
        return ans; 
    }

//time complexity : O(N)
//space complexity : O(1)
