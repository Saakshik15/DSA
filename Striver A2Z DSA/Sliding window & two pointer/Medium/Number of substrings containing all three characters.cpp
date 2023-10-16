/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are 
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
*/

/*
Solution Intuition and explaination:

consider the example:
s = "a b a b c a a b"
     0 1 2 3 4 5 6 7
     
possible valid substrings in this case are:


iteration 0:
1st window having all three characters and all valid substrings after getting all three chars:

 i       j
 0 1 2 3 4  5 6 7 
[a b a b c]
[a b a b c] a
[a b a b c] a a
[a b a b c] a a b

(this iteration will thus have in total 4 substrings because we have to include a, b, c characters 
AT LEAST once in the substring. thus when we get the window from i to j, we also consider all the 
substrings including characters after the j as all these substring fulfill the requirement of having at
least one a, b, c character in it. Thus, the total count of substrings will be 4 in the 1st iteration)


iteration 1: 2nd window:

 i     j 
 1 2 3 4  5 6 7
[b a b c]      
[b a b c] a    
[b a b c] a a  
[b a b c] a a b

(total substrings in this iteration : 4)


iteration 2: 3rd window:

 i   j
 2 3 4  5 6 7
[a b c]      
[a b c] a    
[a b c] a a  
[a b c] a a b

(total substrings in this iteration: 4)


iteration 3: 4th window:

 i   j
 3 4 5  6 7
[b c a]
[b c a] a
[b c a] a b

(total substrings in this iteration: 3)


iteration 4: 5th window:

 i     j
 4 5 6 7
[c a a b] 

Now, how do we actually count all the substrings when we get the window having all the three characters?

For counting all the substrings after we get the window, we subtract the j'th index from the size of the substring.
ie, str.length()-j will give us all the substrings after we get the window size.
eg. in the first iteration, our j'th index is at 4th index, and the string length in this case is 8. (7+1)
thus using str.length()-j, that is, 8-4 we get total number of substrings as 4.
Which can also be verified from the iteration 1 above, that is we get total 4 substrings when we get all three 
characters from i to j window.

By using sliding window when we get the 1st valid window containing a, b, c then the number of valid substrings will be:
1 (for current window) + (remaining characters outside this window)

*/

//code:

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.length();
        int i=0, j=0, count=0;

        unordered_map<char, int> mpp;

        while(j<n){
            mpp[s[j]]++;

            while(mpp['a']>=1 && mpp['b']>=1 && mpp['c']>=1){
                count += (n-j);
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};
