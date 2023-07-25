/*
Problem statement : given a string str and an integer k, return the count of all possible substrings with k distinct characters.

Sample Input 1 :
aacfssa    
3
Sample Output 1 :
5  
Given 'str' = “aacfssa”. We can see that the substrings with only 3 distinct characters are {aacf, acf, cfs, cfss, fssa}. 
Therefore, the answer will be 5.

Sample Input 2 :
qffds
4
Sample Output 2 :
1
*/

/*
Solution : 

Approach :

 The idea is to check for all the substrings of the given string and then check for each substring whether it 
 contains exactly K different characters or not.

Declare COUNT = 0 for storing the answer.
Run two nested loops for generating the indices of all the substrings of the string say i and j (i starting from 0 and j starting from i).
Take the substring from index i to j.
Check for the characters in the substring i.e. count the number of different characters in the substring.
Declare a hashmap ‘HASH_MAP'
Count the frequency of each character in the substring i.e. put the key and value of each character in the HASH_MAP.
Now, COUNT the number of keys in the HASH_MAP.  If the number of keys in the 'HASH_MAP' is equal to K, than increment the COUNT because keys will give the total distinct characters present.
Else move to the next iteration.
Return COUNT.
*/


//code : 

int countSubStrings(string str, int k) {

    int num = 0;
    for(int i=0;i<str.size()-k+1;i++){
        string s = "";
        unordered_set<char> distinct;
        for(int j=i;j<str.size();j++){
            s+=str[j];
            distinct.insert(str[j]);
             if(j<k-1){
                 continue;
            }
            if(s.size()>=k && distinct.size()==k ){
                num++;
            }
        }
    }
    return num;

//time complexity : O(N ^ 3), where ‘N’ denotes the length of the given string.
//We are calculating all possible substrings of the string and then we are calculating the count of characters in each substring. 
//So, the time complexity will be O(N ^ 3)(for calculating every substring)  + O(N)(for counting) = O(N ^ 3).

//space complexity : O(N), where ‘N’ denotes the length of the given string.
//Since we are using a hashmap for storing the string characters, the net space complexity will be O(N).


/*
Approach 2 :

The idea is the same as the previous approach to check for all the substrings of the given string and then check for each 
substring whether it contains exactly K different characters or not. Here, we will use an array of 26 length to store the count 
of each character in the substring.

Declare an array 'COUNT' of length 26 to store the count of characters from ‘a’ to ‘z’ and a variable RESULT = 0 for the answer.
Run two nested loops for generating the indices of all the substrings of the string say i and j (i starting from 0 and j starting from i).
For each substring, fill the 'COUNT' array with zeros for every ith iteration.
Declare a variable DISTINCT_CHARS = 0 to count the distinct characters in substrings.
Now, count the unique characters and check if that character is appearing for the first time or not.
If yes, then increase the DISTINCT_CHARS and count in the array at that index.
Check if the DISTINCT_CHARS is equal to K increment the result.
Finally, after the loops return the result

*/

//code : 

int countSubStrings(string str, int k) {
    int result = 0;
    vector<int>count(26);

    for (int i = 0; i < str.size(); i++) 
    {
        int distinctChars = 0;
        fill(count.begin(), count.end(), 0);

        for (int j = i; j < str.length(); j++) {
            if (count[str[j] - 'a'] == 0) {
                distinctChars++;
            }
            count[str[j] - 'a']++;
            if (distinctChars == k) {
                result++;
            }
        }
    }
    return result;
}

//Time Complexity : O(N ^ 2), where ‘N’ denotes the length of the given string.
//Since we are running two nested loops for the indices i and j, the total time complexity will be O(N) * O(N) = O(N ^ 2).

//Space Complexity : O(1), Since we are using an array of length 26 to store the characters, therefore, the space complexity here is O(1).

/*
Approach 3 : 

The idea is to use a sliding window to count the number of substrings with at most K different characters because 
finding substrings with exactly K characters will again cost us N ^ 2 times. Therefore we will count as the number of 
substrings with exactly K different characters will be the number of substrings with at most K different characters - 
number of substrings with at most (K-1) different characters.

Declare a helper function HELPER to count substrings with at most K different characters.
Declare two indices i and j starting from zero and CURR_COUNT = 0(for storing the count of different characters in the substring).
Declare an array COUNT of length 26 to store the count of characters from ‘a’ to ‘z’ and a variable RESULT = 0 for the answer.
Now run a while loop and increment the COUNT for the characters in the COUNT array. If the COUNT is 1 for that particular 
character in the array, then increment the CURR_COUNT.
If the CURR_COUNT is greater than K:
While CURR_COUNT > K, decrease the count of that particular character in the COUNT array and if it becomes zero, 
then decrement CURR_COUNT and increase i th pointer for the substring.
For result, add j - i + 1 (for the total substrings with at most K different characters.
Increment jth pointer.
Now, in the original function call the HELPER function for at-most K different characters and 
for at-most K-1 different characters HELPER(K) - HELPER(K-1).
Return this difference.
*/

//code :

int helper(string str, int k) {

    int i = 0, j = 0, currCount = 0;
    int result = 0;
    vector<int>count(26, 0);

    while (j < str.size()) {
        int index = str[j] - 'a';
        count[index] += 1;

        if (count[index] == 1) {
            currCount++;
        }
        while (currCount > k) {
            count[str[i] - 'a']--;
            if (count[str[i] - 'a'] == 0) {
                currCount--;
            }
            i++;
        }
        result += (j - i + 1);
        j++;
    }
    return result;
}

int countSubStrings(string str, int k) {
    int ans = helper(str, k) - helper(str, k - 1);
    return ans;
}

//Time Complexity: O(N)
//Space complexity: O(1)











