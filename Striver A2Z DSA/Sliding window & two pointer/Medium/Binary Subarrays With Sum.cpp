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
