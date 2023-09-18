/*
Problem statement: 
Given an integer array of length n and a target sum k, find out the maximum length of subarray having sum of elements target k.
*/

/*
Approach : 1 brute force approach 
In the brute force approach, we will use two nested for loops and find out the sum of each subarray.
Comparing the sum of the subarrays with the target k, we will find out length of all subarrays with the target sum 
and return the maximum length of the subarray which has sum as target sum k.
*/

//time complexity : O(N^2)
//space complexity : O(1)


/*
Approach 2: sliding window

In this approach, we will be using the sliding window approach and slide the window according to three conditions:
1. if the sum of the current subarray is equal to the target sum k:
  then we will simply find out the length of the current subarray and compare it with 'maxi', which is the 
  maximum lenght encountered in all previous subarrays having sum k. If the length of the current subarray 
  is greater than the previous max length, we will update maxi
2. If the sum of the current subarray is lesser than the target sum:
  in this case, we will do nothing but just increment j and go for next iteration to find if sum is equal to target sum
3. If the sum of the current subarray is greater than the target sum:
  in this case, we need to reduce the window and we will achieve this by subtracting arr[i] th elmenet from the 
  sum variable and increment i so as to reduce the window and go for next iteration.

NOTE: 
THIS APPROACH DOES NOT WORK FOR NEGATIVE NUMBERS
*/

//code :

int lenOfLongSubarr(int arr[],  int N, int k) 
    { 
        // Complete the function
        int i=0, j=0, sum=0, maxi = INT_MIN;
        
        while(j<N){
            sum += arr[j];
            
            //if sum is equal to target sum calculate window size and compare with previous max window size.
            //if greater than previous max window size, update the max
            if(sum == k){
                maxi= max(maxi, j-i+1);
            }
            //else if sum is greater than target, we subtract i from the sum and increment i to reduce the window size
            else if(sum > k){
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return maxi;
    } 

//time complexity: O(N)
//space complexity : O(N)

/*
APPROACH FOR NEGATIVE NUMBERS

why this approach doesn't work for negative numbers in the array?
  because, when we find out the sum within the window to be greater than the desired value, we start reducig size of window
  by doing i++. Here, we assumed once the sum of the elements within the window become greater than target, then increasing window 
  size will just add the sum and hence, we will not attain tagget sum again.

the approach we will use in case of negatives: prefix sum using hashmap.

Instead, for negative numbers, we will be using a hashmap to store the prefix sum and find out the length of the
maximum subarray having the target sum k.

*/


//code for negative numbers:

int lenOfLongSubarr(int a[],  int N, int k) {
  
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
  
        for (int i = 0; i < N; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
           return maxLen;
}
