/*
Problem Statement:
There are n fruit trees that are planted along a road. The trees are nubered from 0 to n-1.
The type of fruit each tree bears is represented by an integer from 1 to n.

A ninja is walking along the road. He has two baskets and wants to put the maximum number of fruits in them.
The restriction is that each basket can have only one type of fruit.

Ninja can start with any tree and end at any tree, but once he has started, he cannot skip a tree, i.e., if he picks fruit from the tree i,
then he has to pick fruit from tree i+1 before going to the tree i+2. He will pick one fruit from each tree until he cannot, i.e., he
will stop when h has to pick a fruit of the third type because only two different fruits can fill both baskets.

You are given an array 'arr'. Then ith integer in this array represents the type of fruit tree i bears. Return the maximum number 
of fruits tree i bears. Return the maximum number of fruit Ninja can put in both baskets after satisfying all the conditions.

Sample Input 1:
4
1 1 2 3
Sample Output 1:
3 

Explaination:
There are four trees and the type of fruits in them are 1, 1, 2, 3 respectively.
One way is that Ninja can start picking fruits from tree 0. He picks one fruit from tree 
0 and put it in the first basket, then he picks one fruit from tree 1 and put it in the first basket, 
then he picks one fruit from tree 2 and put it in the second basket, he cannot pick fruit from tree 3 because
the first basket has the fruit of type 1 and second has the fruit of type 2 and type of fruit in tree-3 is 3. 
Thus he has to stop there. The number of fruits he picks in this way is 3. We can show that this is the maximum 
possible number of fruits ninjas can pick.
*/

/*
Solution :

Approach : Sliding window 

As you iterate through the array, you increment the count of the current fruit type in the map mp.
When mp.size() becomes equal to 2, it means there are two types of fruits in the basket. At this point, 
you calculate the length of the current consecutive sequence (i - j + 1) and update maxi if it's greater than the previous maximum.
If the map mp contains more than two types of fruits, you enter the while loop. This loop iterates over the elements 
from the start of the window (j) and decreases their counts in the map. If the count reaches 0, it removes that fruit type from the map. 
This process continues until there are only two types of fruits left in the map.
The function returns the value of maxi, which stores the maximum consecutive number of fruits for both baskets.

---we will use a map and have a condition that there can only be max 2 type of fruits in the map. If it exceeds, we will remove the
type of fruits from the left until we are left with only two types of fruits in the basket, i.e., in map.

So, in short, w have to find a largest substring number of unique characters =2. 
this problem can be reduced to the similar problem -"longest substring with k unique characters" where k=2.
*/

//code 1:

int totalFruit(vector<int>& s) {

        int i=0, j=0, maxlen= INT_MIN;
        unordered_map<int, int>mp;
        
        while(j<s.size()){
            mp[s[j]]++;

            if(mp.size()<=2)
                maxlen= max(maxlen, j-i+1);
            
            else if(mp.size()>2){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxlen;
    }

// code 2:

int findMaxFruits(vector<int> &arr, int n) {
    unordered_map<int,int>mp;
    int cnt=0,ans=0,maxi=0,j=0;
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp.size()==2)
            maxi=max(maxi,i-j+1);
        
        while(mp.size()>2 and j<n){
            mp[arr[j]]--;
            if(mp[arr[j]]==0) mp.erase(arr[j]);
            j++;
        }
    }
    return maxi;
}

//time complexity : O(N)
// space complexity: O(N)



