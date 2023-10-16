/*
Given a string str and an integer k, your task is to find the length of the largest substring with at most k distinct characters.

sample input 1:
2
2
abbbbbbc
3
abcddefg

sample output 1:
7
4
*/

/*
Solution explaination:

we have to find the longest substring having at most k distinct characters.
So, we will create a hashmap to store the count of characters we have got. The size of map will 
give number of characters in the substring.

while map size is less than the number of distinct characters count k, we will increment the window size and keep adding 
j'th character to the map with its frequency count.

once we get the map size as k, we will find out the length of the substring and find out max length of the substrings obtained by:
len = max(len, j-i+1);

when map size becomes greater than distinct character count k, we will decrement count of i'th character from the map and 
increment i to slide the window, until the count of the i'th character in the map becones zero and once it becomes 0, 
we will erase this character from the map.

then we will slide the window to find longer string having k distinct characters till we reach end of the window.
*/


//code:

int kDistinctChars(int k, string &str)
{
    int n = str.size();
    int i = 0, j = 0, len = 0;
  
    unordered_map<char,int> mp;
  
    while(j < n){
        mp[str[j]]++;
      
        while(mp.size() > k){
            mp[str[i]]--;
            if(mp[str[i]] == 0){
                mp.erase(str[i]);
            }
            i++;
        }
        len = max(len, j-i+1);
        j++;
    }
    return len;
}

//time complexity: O(n)
//space complexity: O(26)
