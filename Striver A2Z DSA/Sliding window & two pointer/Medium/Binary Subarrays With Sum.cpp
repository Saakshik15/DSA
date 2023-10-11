/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
*/

//code:

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0, total =0;
        int i=0, j =0;

        if(goal==0){
            while(j<nums.size()){
                while(i<=j && nums[j]){
                    i++;
                }
                total+= j-i+1;
                j++;
            }
            return total;
        }

        while(j<nums.size()){
            sum+=nums[j];

            if(sum>goal){
                while(sum>goal){
                    sum-=nums[i];
                    i++;
                }
            }
            if(sum==goal){
                total++;
            }
            
            int x=i;
            while(nums[x]==0 && sum==goal){
                total++;
                x++;
            }
            j++;
        }
        return total;
    }
};

//code 2:

class Solution {
public:

    int atMost(vector<int>& nums, int goal){
        if(goal<0) return 0;

        int i=0, j=0, ans=0, count=0;

        while(j<nums.size()){
            count += nums[j];

            while(count>goal){
                count -= nums[i];
                i++;
            }
            ans+= j-i+1;
            j++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};

/*
atMost(nums, goal):
When you use atMost(nums, goal), it calculates the number of subarrays where the sum of elements is at most goal. 
This includes subarrays that have a sum less than goal and those that have a sum equal to goal.
This means that atMost(nums, goal) counts all the subarrays with sum less than or equal to goal.

atMost(nums, goal-1):
When you use atMost(nums, goal - 1), it calculates the number of subarrays where the sum of elements is at most goal - 1. 
This includes subarrays that have a sum less than goal - 1 and those that have a sum equal to goal - 1.
By subtracting atMost(nums, goal - 1) from atMost(nums, goal), you are essentially excluding the subarrays whose 
sum is less than goal - 1, leaving only the subarrays with sum equal to goal.
*/
