/*
Given a word str1 and a text str2. Return the count of the occurrences of anagrams of the word in the text.


Example 1:
Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
*/

/*
Solution : 

Approach : sliding window

Create unordered map for storing count of all characters, create another variable count to store count of distinct characters and
a variable ans for storing count of anagrams.

Inside while loop, compare rth character to keys of map. 
If character is found in map, decrement its corresponding value. 
If value of any of the keys become 0, decrement count variable as it stores the count of all distinct variables.
(we used count because otherwise using the map only we would have to traverse the whole map in O(k) complexity)

when reaching the window size, 
if count becomes 0, ans++
sliding the window: before sliding, we need to remove all calculations of lth character if it exists in the map
then increment the correspondig alu of lth character if it exists in the map.

again, in while loop we will continue to compare rth value with map keys.
*/

//code :

int search(string pat, string txt) {
        
        //First count all character freq, 
        unordered_map<char, int> mp; 
        for(int i = 0; i < pat.size(); i++) {
            mp[pat[i]]++; 
        }
  
        int cntAnagram = 0; // total anagram 
        int count = mp.size();  //to store the number of distinct characters in the map
        
        //Initially sliding window size
        int l = 0, r = 0; 
        while(r < txt.size()) {
            
            // it r'th part present then we reduce count whenever it's freq become zero 
            if(mp.find(txt[r]) != mp.end()) {
                mp[txt[r]]--; 
                if(mp[txt[r]] == 0) 
                    count--; 
            }
            // if we not reach, pat.size() window, that increae window
            if(r-l+1 < pat.size()) {
                r++; 
            } 
            // If you reach window size, then find the answer, and slide the window 
            else if(r-l+1 == pat.size()) {
                if(count == 0) {
                    cntAnagram++; 
                }
                //If character is already present in map then reduce 
                if(mp.find(txt[l]) != mp.end()) {
                    mp[txt[l]]++; 
                    if(mp[txt[l]] == 1) {
                        count++; 
                    }
                }
                // slide window
                r++, l++; 
            }
        }
        return cntAnagram; 
    }


//time complexity : O(n+k) assume map to be working in constant time
//space complexity : O(26)
