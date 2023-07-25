/*
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/


/*
Solution :

Approach : 

1. Initialize two empty strings, `temp` and `ans`, to store the current word being processed and the final reversed string, respectively.
2. Find the index of the first non-space character from the left side of the string (`left`), and the index of the last non-space 
character from the right side of the string (`right`).
3. Iterate through the characters of the string from the left side (`left`) to the right side (`right`).
   - If the current character is not a space, add it to the `temp` string, forming the current word.
   - If the current character is a space, check the previous character to avoid consecutive spaces.
     - If the previous character is also a space, skip it and continue to the next character.
     - If the previous character is not a space, the current word is complete, so add it to the beginning of the `ans` string, 
     separated by a space, and reset the `temp` string.
4. After the loop finishes, the `temp` string will contain the last word in the original string. 
Add it to the beginning of the `ans` string, separated by a space.
5. Remove the trailing space at the end of the `ans` string.
6. The `ans` string now contains the reversed words of the original string, separated by a single space between each word.
7. Return the `ans` string as the final result.
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

//time complexity : O(N)
//space complexity : O(N)
