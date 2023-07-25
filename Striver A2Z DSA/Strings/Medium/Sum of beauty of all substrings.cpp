/*
The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Example 1:
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

Example 2:
Input: s = "aabcbaa"
Output: 17
*/


/*
solution :

Approach : brute force 

Iterate through all possible starting indices i of the substrings in the input string s (from 0 to n-1).
For each starting index i, initialize a character frequency map mp to store the character counts of the current substring.
Use another loop to generate all possible substrings starting from index i.
For each ending index j (from i to n-1), expand the substring and update the character frequency in the mp map.
Calculate the most frequent character count (mostFreq) and the least frequent character count (leastFreq) in the current substring using the mp map.
Calculate the beauty score of the current substring as mostFreq - leastFreq.
Add the beauty score of the current substring to the overall beauty sum (sum).
Continue the process until all substrings starting from index i have been considered.
Repeat steps 1 to 8 for all starting indices i to cover all possible substrings.
The final sum variable will contain the total beauty sum of all substrings.
Return the sum as the final result.
*/

//code : 

int beautySum(string s) {
        int sum=0, n=s.size();

        for(int i=0; i<n; i++){
            map<char,int> mp;

            for(int j=i; j<n; j++){
                mp[s[j]]++;

                int mostFreq= 0, leastFreq = INT_MAX;
                for(auto ch:mp){
                    mostFreq = max(mostFreq, ch.second);
                    leastFreq = min(leastFreq, ch.second);
                }
                sum += (mostFreq-leastFreq);
            }
        }
        return sum;
    }

//time complexity : O(N^2)
//cause the third loop can run at most 26 times which is constant
//space complexity : O(1) space for the map which is 26, which is constant



/*
Approach 2 : optimized approach

Iterate through all possible starting indices i of the substrings in the input string s.
For each starting index i, use a map mp to track the character frequencies of the current substring.
Use a nested loop to generate all possible substrings starting from index i.
For each ending index j (from i to n-1), expand the substring and update the character frequency in the mp map.
Iterate through the mp map to find the most frequent character count (mostFreq) and the least frequent character 
count (leastFreq) in the current substring.
Calculate the beauty score of the current substring as mostFreq - leastFreq.
Add the beauty score of the current substring to the overall beauty sum (sum).
Continue the process until all substrings starting from index i have been considered.
Return the sum as the final result.
*/

//code :

int beautySum(string s) {
        int sum=0, n=s.size();

        for(int i=0; i<n; i++){
            map<char,int> mp;
            multiset<int> st;

            for(int j=i; j<n; j++){
                if(mp.find(s[j])!=mp.end())
                    st.erase(st.find(mp[s[j]]));
                mp[s[j]]++;
                st.insert(mp[s[j]]);

                sum += (*st.rbegin()-*st.begin());
            }
        }
        return sum;
    }

//time complexity : O(N^2 * logN)
//space complexity : O(N)
