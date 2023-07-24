/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
  
Example 2:
Input: s = "foo", t = "bar"
Output: false
  
Example 3:
Input: s = "paper", t = "title"
Output: true
*/


/*
solution :

approach :

Check if the lengths of strings s and t are different. If they are, then the strings cannot be isomorphic, so return false.
Create two vectors s2t and t2s, both of size 256 (ASCII characters), to map characters from string s to string t and vice versa. 

Loop through each character of the strings using the variable i.
Check if the current character s[i] has not been mapped in s2t and t[i] has not been mapped in t2s. 
This is the first occurrence of the character in both strings.
a. If both conditions are met, create mappings between s[i] and t[i] in s2t and t2s, respectively.
If the current character s[i] has been mapped in s2t but the corresponding character in t2s is not equal to t[i], 
it means there's a conflict in the mapping, and the strings are not isomorphic. In this case, return false.
If the loop completes without any conflicts, it means the strings are isomorphic, and the function returns true.

*/

// code :

bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) return false;
        
        vector<int> s2t(256, 0), t2s(256, 0);

        for (int i = 0; i < s.length(); ++i) {
            if (s2t[s[i]] == 0 && t2s[t[i]] == 0) {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else if (s2t[s[i]] != t[i]) {
                return false;
            }
        }
        return true;
    }

//time complexity : O(N)
//space complexity : O(2N)

