/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

/*
approach 1 : using hashing (array)
this approach can be implemented using a hashmap too, instead of an array

initialize a vector of pairs, mp, of size 62 (to account for uppercase letters, lowercase letters, and digits) 
to store the frequency of characters in the input string s.
iterate through each character ch in the input string s.
For each character ch, check whether it is an uppercase letter, lowercase letter, or digit
calculate the corresponding index for the character in the mp vector and increment the frequency count for that character.
After counting the frequencies, the code sorts the mp vector in ascending order based on the frequency using sort.
then reverse the sorted vector to get the characters in descending order of their frequency using reverse.
Next, reconstruct the sorted string by iterating through the sorted mp vector.
For each pair in the mp vector, it represent a character and its frequency. 
append the character to the final string s freq times, where freq is the frequency of that character.
The final sorted string is returned.
*/

//code :

 string frequencySort(string s) {
        vector<pair<int, char>> mp(62);
        for (auto &ch : s) {
            if (isupper(ch)) mp[ch-'A'] = {++mp[ch-'A'].first, ch};
            else if (islower(ch)) mp[ch-'a'+26] = {++mp[ch-'a'+26].first, ch};
            else mp[ch-'0'+52] = {++mp[ch-'0'+52].first, ch};
        }

        sort(begin(mp), end(mp));
        reverse(begin(mp), end(mp));

        int i = 0;
        for (auto &[freq, ch] : mp) {
            if (!freq) break;
            while (freq--) s[i++] = ch;
        }

        return s;
    }

//time complexity : O(n)
//Counting the frequency of characters in the input string s takes O(N) time, where N is the length of the input string.
//Sorting the mp vector using sort takes O(62 log 62) time, which is equivalent to O(1) since 62 is a constant value.
//Reversing the mp vector using reverse takes O(62) time, which is equivalent to O(1) since 62 is a constant value.
//Reconstructing the sorted string by iterating through the mp vector and appending characters takes O(N) time, where N is the length of the input string.
//therefore, the overall time complexity is O(n)

//space complexity : O(1)
//The space complexity is primarily determined by the vector mp of size 62 (constant value) to store the frequency of characters. 
//Thus, the space complexity for this vector is O(1).
//Apart from the mp vector, the function uses additional constant space for other variables and constants used in the function.
//therefore, overall space complexity is O(1)

/*
Approach 2 : using bucket sort 

initialize an unordered_map named map to store the frequency of each character in the input string s. 
The keys of the map are characters, and the values are the corresponding frequencies.

Iterate through the characters in the string for each character c, increment its frequency in the map.
After counting the frequencies of characters, the function creates a vector of strings named bucket, 
with a size of s.size() + 1. The bucket vector is used for bucket sort.

Next, the function iterates through the map. For each character c and its frequency freq, it appends the character c 
to the corresponding bucket in the bucket vector. The bucket index is determined by the frequency of the character. 

The function initializes an empty string named ans, which will be used to store the final sorted string.
It then iterates through the bucket vector in reverse order (from the highest frequency to the lowest frequency).
For each non-empty bucket, it appends the characters in that bucket to the ans string. 
The characters are appended in descending order of their frequency.
*/

//code :

string frequencySort(string s) {
        unordered_map<char, int> map;
        for(auto c : s){
            map[c]++;
        }
        vector<string> bucket(s.size()+1, "");
        for(auto [c, freq] : map){
            bucket[freq].append(freq, c);
        }
        string ans;
        for(int i=s.size(); i>=1; i--){
            if(!bucket[i].empty()){
                ans.append(bucket[i]);
            }
        }
        return ans;
    }

/*
Time Complexity : O(N), Here we are inserting the characters into a unordered_map(map). It will take O(N)
    time where N is the length of the string. then we are appending all the element of unordered_map(map) in
    vector(bucket) which also takes O(N) then finally we traverse the string and store the answer in string(ans).
    So the overall time complexity is O(N).

Space Complexity : O(N), The space complexity of the above code is O(N) because we are using unordered_map
    (map) and vector(bucket) which creates the space complexity.
*/

/*
approach 3 : using priority queue 

initialize an unordered_map named map to store the frequency of each character in the input string s. 
The keys of the map are characters, and the values are the corresponding frequencies.
It then iterates through each character c in the input string s.

For each character c, increment its frequency in the map.
After counting the frequencies of characters, the function creates a priority_queue named pendingNodes. 
The priority_queue is a max-heap, which means that the pair with the highest frequency will be at the top of the heap. 
The pair consists of the frequency as the first element and the character as the second element.
  
Next, the function iterates through the map. For each character c and its frequency freq, 
it pushes a pair containing {freq, c} into the pendingNodes priority_queue.

The function initializes an empty string named ans, which will be used to store the final sorted string.
It then enters a loop that continues until the pendingNodes priority_queue becomes empty.
Inside the loop, the function retrieves the top element (pair with the highest frequency) from the pendingNodes priority_queue 
using top(), and then removes it from the queue using pop().

For each pair, it appends the character c to the ans string freq times, where freq is the frequency of that character.
This step is done using string(curr.first, curr.second), which creates a string with curr.first copies of the character curr.second.

The loop continues until all characters are processed and the pendingNodes priority_queue becomes empty.
Finally, the function returns the ans string, which represents the sorted string with characters arranged by their frequency in descending order.
*/

//code : 

string frequencySort(string s) {
        unordered_map<char, int> map;
        for(auto c : s){
            map[c]++;
        }
        priority_queue<pair<int, char>> pendingNodes;
        for(auto [c, freq] : map){
            pendingNodes.push({freq, c});
        }
        string ans;
        while(!pendingNodes.empty()){
            auto curr = pendingNodes.top();
            pendingNodes.pop();
            ans += string(curr.first, curr.second);
        }
        return ans;
    }

/*
Time Complexity : O(NlogN), Here we are inserting the characters into a unordered_map(map). It will take O(N)
    time where N is the length of the string. Then we sort the list of characters using priority_queue
    (pendingNodes) on the basis of frequency after that on the basis of their ASCII value. It will take O(NlogN)
    time. So the overall time complexity is O(NlogN).

Space Complexity : O(N), The space complexity of the above code is O(N) because we are using unordered_map
    (map) and priority_queue(pendingNodes) which creates the space complexity.
*/











