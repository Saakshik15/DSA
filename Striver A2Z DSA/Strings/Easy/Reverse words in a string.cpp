/*
Problem Statement: Given a string s, reverse the words of the string.

Examples:

Example 1:
Input: s=”this is an amazing program”
Output: “program amazing an is this”

Example 2:
Input: s=”This is decent”
Output: “decent is This”

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

*/

/*
approach : optimal approach
  
There can be 4 cases of spaces (" "). All 4 need to be taken care of.

Before the first non space character
Exactly one space in between two words
Extra spaces in between two words
After the last non space character

Take two pointers (left and right) and make them point to the first and last non space characters respectively.
Now start the traversal from left to right. When you get a space, check if the character just before it was also a space or not. 
1.If yes, ignore it and continue; (A good example where this is useful is testcase 3)
2.Else add the current word (temp) before the current ans (ans = temp + " " + ans)
when reaching the end, left == right, append the last word before the ans
erase the last extra space in the final ans (ans.erase(ans.begin() + ans.length() - 1);)

*/

//code :

string reverseWords(string s) {

        string temp = "";
        string ans = "";

        int left = 0;
        while (s[left] == ' ') left++;

        int right = s.length() - 1;
        while (s[right] == ' ') right--;

        while (left <= right) {
            if (s[left] != ' ') 
                temp += s[left];
            
            else {
                if (s[left - 1] == ' ') {
                    left++;
                    continue;
                }
                else {
                    ans = temp + " " + ans;
                    temp = "";
                }
            }
            left++;
        }
        ans = temp + " " + ans;
        ans.erase(ans.begin() + ans.length() - 1);
        return ans;
    }

//Time Complexity: O(N), N~length of string

//Space Complexity: O(1), Constant Space



