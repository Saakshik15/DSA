/*
problem statement : Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/

/*
Solution :

Approach 1 : Brute force (three nested loops)

Declare a helper function that takes a reference to the input string s, and two integers i and j as arguments. 
This function will check if the substring from index i to index j (inclusive) is a palindrome by comparing characters 
from the outer ends inward. If the characters at both ends do not match, return false. If all characters match, return true.
Function longestPalindrome that takes the input string s and returns the longest palindromic substring found.
Initialize variables n, starting_index, and max_len to keep track of the length of the input string, 
the starting index of the longest palindromic substring found so far, and its length, respectively.

Iterate over all possible starting indices i from 0 to n-1 in the input string s:

For each iteration i, iterate over all possible ending indices j from i to n-1 in the input string s:
Call the check function to determine if the substring from i to j is a palindrome.
If the substring is a palindrome:
Calculate its length as j - i + 1.
If the length is greater than the current max_len, update max_len and starting_index to store the new longest palindromic substring.
After both loops finish, return the longest palindromic substring using s.substr(starting_index, max_len).
*/

//code :

bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }

//time complexity : O(N^3)
//space complexity : O(1)

/*
Approach 2 : brute force (two nested loops)

The check function iteratively checks if a given substring from i to j is a palindrome by comparing characters from both ends inward.

The longestPalindrome function:

Initializes an empty string finalans to store the final longest palindromic substring found.
Generates all possible substrings of the input string s using two nested loops.
For each substring, calculates its length and checks if it is a palindrome using the check function.
Keeps track of the longest palindromic substring found so far in finalans.
Returns the finalans, which represents the longest palindromic substring found.
*/

//code :

bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

string longestPalindrome(string s) {
        int n = s.size();
        vector<string> substring;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                substring.push_back(temp);
            }
        }
        int max_len = 0;
        string finalans = substring[0];
        int m = substring.size();
        for(int i=0; i<m; i++){
            int s = substring[i].size();
            if(check(substring[i], 0, s-1)){
                if(s > max_len){
                    max_len = s;
                    finalans = substring[i];
                }
            }       
        }
        return finalans;
    }

//time complexity :  O(N^2)
//space complexity : O(N^2 *N)

/*
approach 3 : optiamal approach using dp

solve is a helper function that uses dynamic programming to determine if the substring from index i to index j (both inclusive) is a palindrome:
If i is equal to j, it's a single character and hence a palindrome.
If j - i is 1, check if the characters at i and j are the same to determine if it's a palindrome.
If the characters at i and j are the same and the substring from i+1 to j-1 is also a 
palindrome (dp[i+1][j-1] is true), then the entire substring from i to j is a palindrome.

longestPalindrome is the main function that finds the longest palindromic substring using dynamic programming:

Initializes variables startIndex and maxlen to store the starting index and length of the longest palindromic 
substring found so far, respectively.
Initializes a 2D vector dp of size n x n, where dp[i][j] will store whether the substring from index i to index j is a palindrome.
Uses two nested loops to generate all possible substrings of the input string s.
For each substring, calls the solve function to determine if it's a palindrome and updates dp accordingly.
Keeps track of the longest palindromic substring found so far and its length in startIndex and maxlen.
Returns the longest palindromic substring using s.substr(startIndex, maxlen).
*/

//code :

bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
        if(i == j){
            return dp[i][j] = true;
        }
        if(j-i == 1){
            if(s[i] == s[j]){
                return dp[i][j] = true;
            }
            else{
                return dp[i][j] = false;
            }
        }
        if(s[i] == s[j] && dp[i+1][j-1] == true){
            return dp[i][j] = true;
        } else {
            return dp[i][j] = false;
        }
    }

string longestPalindrome(string s) {
        int n = s.size();
        int startIndex = 0; int maxlen = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++, j++){
                solve(dp, i, j, s);
                if(dp[i][j] == true){
                    if(j-i+1 > maxlen){
                        startIndex = i;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(startIndex, maxlen);
    }

//time complexity : O(N^2)
//space complexity : O(N^2)



































