/*
Problem statement:

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character.
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
*/

/*
Approach 1: Brute force approach

In the first approach, we will find out all the substrings of the given string.
Then, for each substring, we will find out the character wihch is repeted most in the substring.
Then, we will be subtracting the given k, which is the limit for replacement of characters from the window size.
ie,  windowsize - count <= k 
then we will get a candidate for the longest substring which we have to find, and thus for each string we will 
be calculating the max window size which will satisfy the condition of replacement of characters.
*/

//time complexity : O(N^2)
//space complexity: O(1)


/*
Approach 2:

In this approach, we will be unsing a sliding window approach and while we slide the window, we will be finding out the character
which is repeated the most frequently in the substring and thus find out the max window size in that consequence using the formula:
windowsize - count for maximun occurred character <= k

For this approach, we will be storing the count of each character in a vector called counts.
We will initialize count as vector<int> (26,0) as there are only uppercase English alphabets in the string and count for each
character at first will be initialized to 0.

Then, we will run a loop on the string and add the character count to the vector counts for the respective characters
and for each char added in the counts vector for the current window, we will find out if the current character has greater frequency
than the previous max frequency character. for this, we will use :
maxchar = max(maxchar, counts[s[j]-'A']);

Then, for each count incremented, we will find out if the current window is potential candidate for the max window
which satisfies the condition given in problem statement.
for this, we will use the condition:
windowsize- maxchar/count(for the max occurred char) <= k;

now, when we exceed k, ie, when the windowsize  - maxchar is greater than k, then we will shrink the window size by 
incrementing i, ie, the left pointer of the current window and slide the window like this.
Simultaneously, from counts vector, we will be decremeting the count of the character which was at the i'th place 
since it is no longer a part of the window. for this, 
while(j-i-maxchar+1 > k){
    counts[s[i]-'A']--;
    i++;
}
            
finally at the end step, we will be finding out the max window size which can satisfy the condition of replacing characters
by comparing it to previous max and update the result variable.
*/

//code:

int characterReplacement(string s, int k) {
        
        vector<int> counts(26,0);
        int i=0, j=0, maxchar = 0, result =0;
        int n= s.length();

        while(j<n){
            counts[s[j]-'A']++;

            maxchar = max(maxchar, counts[s[j]-'A']);

            while(j-i-maxchar+1 > k){
                counts[s[i]-'A']--;
                i++;
            }
            result= max(result, j-i+1);
            j++;
        }
        return result;
    }

//time complexity: O(N)
//space complexity: O(1) 




