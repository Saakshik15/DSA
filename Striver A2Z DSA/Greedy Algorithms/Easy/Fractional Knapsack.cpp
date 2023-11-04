/*
Problem:

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

 Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

Complete the function fractionalKnapsack() that receives maximum capacity , 
array of structure/class and size n and returns a double value representing the maximum value in knapsack.
Note: The details of structure/class is defined in the comments above the given function.
*/

//approach: greedy

//code:

//class implemented

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    
    static bool cmp(pair<pair<int,int>,double>p, pair<pair<int,int>,double>q){
        return p.second > q.second;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        
        vector<pair<pair<int,int>,double>>vec;
        
        for(int i=0; i<n; i++){
            vec.push_back({{arr[i].value,arr[i].weight},(double)arr[i].value/(double)arr[i].weight});
        }
        
        sort(vec.begin(),vec.end(),cmp);
         double total = 0;
        
        for(int i=0; i<n; i++){
            if(W==0) break;
            if(W>=vec[i].first.second){
                total+= vec[i].first.first;
                W = W-vec[i].first.second;
            }
            else{
                total+= (vec[i].first.second - (vec[i].first.second-W)) * vec[i].second;
                W=0;
            }
        }
        return total;
    }    
};

//time complexity: O(nlogn)
//space complexity: O(N)

