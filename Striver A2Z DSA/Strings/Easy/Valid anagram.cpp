/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

/*

Solution :

approach 1 : to sort the strings in lexicographical order 

sort(s.begin(), s.end()); sorts the characters in string s in ascending order. 
This rearranges the characters in s so that they are in alphabetical order.
sort(t.begin(), t.end()); sorts the characters in string t in ascending order. 
Similarly, this rearranges the characters in t to be in alphabetical order.
return s == t; compares the sorted strings s and t using the equality operator (==). 
If the sorted strings are equal, it means that the original strings s and t have the same characters in the same order, 
indicating that they are anagrams. In this case, the function returns true. Otherwise, if the sorted strings are not equal, 
the function returns false, indicating that the strings are not anagrams.
This code takes advantage of the fact that anagrams have the same characters, but in different orders. 
By sorting the characters, the code transforms the problem into a comparison of the sorted strings, simplifying the anagram check.
*/

//code :

bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

//time complexity : O(n logn)
//space complexity : O(1)

/*
approach 2 : using hash table

Create an unordered map count to store the character frequencies. The key of the map represents a character, 
and the value represents its frequency.
Iterate over each character x in string s. For each character, increment its frequency 
in the count map by using the count[x]++ expression.
Iterate over each character x in string t. For each character, decrement its frequency 
in the count map by using the count[x]-- expression.
Iterate over each pair x in the count map. Each pair consists of a character and its corresponding frequency. 
Check if any frequency (x.second) is non-zero. If any frequency is non-zero, it means there is a character that 
appears more times in one string than the other, indicating that the strings are not anagrams. In that case, return false.
If all frequencies in the count map are zero, it means the strings s and t have the same characters in the same frequencies,
making them anagrams. In this case, the function returns true.
*/

//code : 

    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }        
        return true;
    }

//time complexity : O(n)
//space complexity : O(1)
//because the size of the map is independant of the size of the input of strings.

/*
approach 3 : Hash table using array

This approach is simmilar to the approach of using a hash table for storing the frequencies, but the space complexity due to map is more.
Thus, an array of size 26 will be used for the same purpose to check if all alphabets are same in the two strings.
*/

//code :

bool isAnagram(string s, string t) {
        int count[26] = {0};
  
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }  
        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }      
        return true;
    }

//time complexity : O(n)

//space complexity : O(1)
//Although an integer array of size 26 is used to store the character frequencies, the size of the array is constant and 
//independent of the input size. Therefore, the space complexity is considered constant, or O(1).










  
