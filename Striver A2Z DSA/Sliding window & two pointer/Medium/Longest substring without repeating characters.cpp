/*

Problem Statement: 
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
Solution : 

Approach 1 : brute force

this approach includes using two nested for loops for traversing the string using the outer loop and finding out the substring and 
is it possible to form a longest substring without repeating character for that substring and if possible finding out the length
*/

/*
Approach 2: using set

in this appraoch we will be using unordered set in order to keep track of encountered character so far.
now, we will traverse the string using two pointers, l and r which will be the current substring 
initially l will be 0 and we will traverse the string using r pointer
we will check if the currently encountered character is in the set or not:
  1. if current character str[r] is not in the set, the we will increase maxLen by 1 (maxLen = max(maxLen, l-r+1)
  and add the current character to the set.
  2. if current character is already in the set, then we will keep incrementing the left pointer unless the character in the 
  set is reached and we will remove it (str[l]).
we will now insert current character in the set and continue iteration
finally return the maxLen
*/

//code:

int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int maxLen =0;
        unordered_set<char> st;
        int l=0;

        for(int r=0; r<n; r++){
            char ch= s[r];
            
            if(st.count(ch)==0){
                st.insert(ch);
                maxLen = max(maxLen, r-l+1);
            }else{
                while(st.count(ch)){
                    st.erase(s[l]);
                    l++;
                }
                st.insert(ch);
            }
        }
        return maxLen;
    }

//time complexity :O(2N)
//space complexity : O(N)


/*
Approach 3 :

In the approach using set, if there are any repeating characters in the window, then we keep incrementing the left pointer (l) untill 
we find the repeating character to remove it from the window and start iterating again.
this increases unnecessary iterations as instead of directly jumping to the index where the repeating character is present,
we keep iterating to find the repeating character
So, instead of those unnecessary iterations to remove the repeating character, we will simply store the indices of the characters 
along with the characters to directly jump to the desired repeating character.

Here, we will use unordered_map<char, int> in order to store the indices associated with the characters

Algorithm :
using while loop for iterating the string, inside the loop:
Check if the character s[r] is already present in the mpp unordered_map by using mpp.find(s[r]) != mpp.end()  
If the character is in the map, update the left pointer l to be the maximum of its current value and the index stored 
in the map for the character s[r] + 1. This ensures that l points to the next character after the last occurrence of s[r].

Update the index of the character s[r] in the mpp map to the current value of r. 
This keeps track of the most recent occurrence of the character.

Calculate the length of the current substring without repeating characters, which is r - l + 1.
Update maxLen with the maximum of its current value and the calculated length of the current substring.
Increment the right pointer r to move to the next character in the string.

After the loop, maxLen will contain the length of the longest substring without repeating characters in the input string s.
Return maxLen as the result.
*/

//code :

int lengthOfLongestSubstring(string s) {
         unordered_map<char, int> mpp;
        int l=0, r=0, maxLen=0;
        int n= s.size();

        while(r<n){
            if (mpp.find(s[r]) != mpp.end()) 
                l = max(mpp[s[r]] + 1, l);
            mpp[s[r]]=r;
            maxLen= max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }

//time complexity : O(N)
//space complexity :O(N)

