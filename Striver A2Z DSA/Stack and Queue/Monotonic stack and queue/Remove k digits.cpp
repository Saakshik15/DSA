/*
Problem Statement :
Given string num representing a non-negative integer num, and an integer k, return the smallest
possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
*/

/*
Approach : monotonic increasing stack

we will be using a monotonic increasing stack in this case.
there might be mainly two cases, either the digits are in increasing oder or decreasing order.
  eg. if the digit is 54321 then we will surely remove 5 because we know that only removing 5, which is comparatively greater than 
the next elements is going to minimize the number and no othernumber can
but, if the number is in decrasing order, something like 12345, then we will be removing the last 5 in this case too.
  
thus, the obervation here is we need a monotonous ncreasing stack in this case.
when the next digit is lesser than previous digit, we will remove the current digit to add the next digit.
but, if the next digit is following monotonous stack property and is greater than current digit then we will continue pushing to the 
stack until we come across a digit which is not following monotonous stack property or until the digit is completely traversed.
*/

//code explaination in comments :

    string removeKdigits(string num, int k) {
        // number of operation greater than length we return an empty string
        if(num.length() <= k) return "0";
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0) return num;
        
        string res = "";  //result string
        stack <char> s;   //char stack- monotonous increasing stack

        s.push(num[0]); 
        for(int i = 1; i<num.length(); i++){
            while(k > 0 && !s.empty() && num[i] < s.top()){
                // if k greater than 0 and our stack is not empty and the upcoming digit,
                // is less than the current top than we will pop the stack top
                --k;
                s.pop();
            }
            s.push(num[i]);
    
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
         // for cases like "456" where every num[i] > num.top()
        while(k && !s.empty()){
            --k;
            s.pop();
        }
      
        while(!s.empty()){
            res.push_back(s.top()); 
            s.pop(); 
        }  
        reverse(res.begin(),res.end()); 

        return (res.length())? res:"0";
    }

//time complexity : O(N)
//space complexity : O(N)

//code without comments :

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() <= k) return "0";
        if(k == 0) return num;
        
        string res = "";
        stack <char> s; 

        s.push(num[0]); 
        for(int i = 1; i<num.length(); i++){
            while(k > 0 && !s.empty() && num[i] < s.top()){
                --k;
                s.pop();
            }
            s.push(num[i]);
            
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }

        while(k && !s.empty()){
            --k;
            s.pop();
        }

        
        while(!s.empty()){
            res.push_back(s.top()); 
            s.pop(); 
        }  
        reverse(res.begin(),res.end()); 

        return (res.length())? res:"0";
        
    }
};
