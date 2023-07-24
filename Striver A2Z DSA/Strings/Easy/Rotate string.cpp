/*

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
 
Example 1:
Input: s = "abcde", goal = "cdeab"
Output: true
  
Example 2:
Input: s = "abcde", goal = "abced"
Output: false
*/

/*

solution : 

approach : 1

The function takes two input strings s and goal.
It initializes two integers n and m to store the lengths of s and goal, respectively.
It performs a quick check to see if the lengths of s and goal are different (n != m). If they are different, 
it is not possible to obtain goal by rotating s, so the function returns false.
The function enters a loop that will rotate the string s through all possible shifts.
In each iteration of the loop, it checks if s is equal to goal. If they are equal, it means the rotation has 
successfully produced goal, and the function returns true.
If s is not equal to goal, it performs a single left rotation on s by moving the first character to the end of 
the string using s.substr(1) + s[0].
The loop continues for n iterations, ensuring that s is rotated through all possible shifts.
If no match is found after all rotations, the function returns false.
*/

// code : 

bool rotateString(string s, string goal) {
        int n= s.size(), m= goal.size();

        if(n!=m) return false;

        for(int i=0; i<n; ++i){
            if(s==goal) return true;
            else s= s.substr(1) + s[0];
        }
        return false;
    }

//time complexity : O(n*n)
//space complexity : O(1)

/*
approach 2 :

The function rotateString takes two input strings s and goal.
It first checks for the edge case where lengths of s and goal are not equal. 
1. If they are not equal, it is impossible to get goal with performing rotations with s.
2. If they are equal, create a new string s2 by concatenating s with itself. This effectively doubles the string s, 
so s2 contains two copies of s back-to-back.
The function then checks two conditions using the if statement:
a. s2.contains(goal): This condition checks if the string goal is a substring of the s2. 
  If goal is present as a substring in s2, it means goal can be obtained by rotating s. This is because if we rotate s, 
  s2 will contain all possible rotations of s.
  If this condition is true, we may conclude that we can get goal after performing certain rotations on s.
If this condition is false, the function returns false, indicating that goal cannot be obtained by rotating s.
*/

//code :

bool rotateString(string s, string goal) {
        int n= s.size(), m= goal.size();
        if(n!=m) return false;

        string s2 = s+s;
        if(s2.find(goal) != string::npos){
            return true;
        }else return false;
    }

//time complexity :  O(n + m) due to the concatenation and substring search operations.
//space complexity : O(1)






  
