/*
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given 
array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that 
each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done
of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

  OR

Problem Statement: Given an integer array ‘A’ of size ‘N’ and an integer ‘K’. Split the array ‘A’ into ‘K’ non-empty 
subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.
*/

/*

Solution : 

Approach : optimal approach using binary search

set low= max(arr[]) and high = sum(arr[])
find mid = (low+high)/2
Eliminate the halves based on the number of students returned by countStudents():
1.If students > m: we will eliminate the left half and consider the right half(i.e. low = mid+1).
2.else mid is possible answer but we want minimum ans, so eliminate right half and consider the left half(i.e. high = mid-1).
finally return low as low will be pointing to answer.
*/

// code :

    int helper(vector<int>& arr, int mid){
        int arrays=1, alloted=0;
        for(int i=0; i<arr.size(); i++){
            if(alloted+arr[i] <= mid){
                alloted+=arr[i];
            }else{
                arrays++;
                alloted= arr[i];
            }
        }
        return arrays;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low= *max_element(nums.begin(), nums.end());
        int high= accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid= low+(high-low)/2;

            if(helper(nums,mid)>k) low=mid+1;
            else high= mid-1;
        }
        return low;
    }

//time complexity : O(log(sum-max+1)) * O(n)
//space complexity : O(1)
