/*
Problem statement :
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
Approach 1: Brute force

In the brute force approach, for each index in the array, we will find out the immediate next greater element to the right and left.
We will thus find out the minimum- 'mini' of those maximum elements.
Then, we will subtract the height of the current index from the mini variable 
and that number will be the amount water that will be trapped in the block at that index.

Thus, if we are at any current index i, then the water that can be trapped at that index will be

min(NGE(left of i), NGE(right of i)) - value at current index 
*/
//code :


int trap(vector<int> height) {
    int water=0;
    for(int i=0; i<height.size(); i++){
        int maxLeft = INT_MIN, maxRight = INT_MIN;
        int mini = INT_MAX;
      
        //step1: find the max left
        for(int j=0; j<=i; j++)
            maxLeft = max(maxLeft, height[j]);
        
        //step 2: find the max right
        for(int j=height.size()-1; j>=i; j--)
            maxRight = max(maxRight, height[j]);
        
        //step 3: find the min of 1 and 2
        min = min(maxLeft, maxRight);
        water += min - height[i];
    }
    return water;
}

/*
Time and space complexity analysis:
For each index i, we have to find how much water it will trap, this will take a complete loop, i.e. O(N)
Now, for every element at index i, a[i] we have to look for NGE to the right and left, 
this will take a complete iteration from left to right, i.e. O(N)
since these two loops will be nested, we will be requiring O(N^2) time complexity.
also, the space complexity of this will be O(1).
*/


/*
Approach 2: better solution

Now, to optimize the above approach, we will be using prefix sum approach.
We will thus store a prefixMax and a suffixMax array for this
The prefixMax array will store all the maximums for all the elements towards the left (starting from the front)
and the suffixMax will store all the maximums for all the elements towards the right (starting from the back)
Thus, we can remove the nested loops using this approach where we don't need to have nested loops, 
instead, we will ru two loops separately to find the prefixMax and suffixMax arrays.

Now, we can traverse the array same as in brute approach and compute the amount of trapped rain water using the formula:
min(prefixMax[i], suffixMax[i]) - arr[i] 

Thus, the overall time complexity for this approach will be :
O(N) for prefixMax + O(N) for suffixMax + O(N) for iterations = O(3N)
space complexity : O(2N) for prefixMax and suffixMax arrays.
*/


/*
Approach 3 : optimal approach using two pointers

In this approach, we will be using two pointers, left and right.
Left will initially be at index 0 and right at index arr.size()-1 th index.
then, using a while loop, we will traverse the array till the left crosses the right pointer.

then, we will find the left max which will be either height of current left or previous left max.
Similarly, we will find out right max, which will either be current right or previous right max.

there will be thus two conditions according to which one of the left max and right max is lesser:
if left max is lesser, that means the water will be (left max- height[left]), 
  we will thus add it to water and move the left pointer forward.
else, if right max is lesser that means the water stored will be (right max- height[right])
  we will thus add it to total water and move the right pointer backwards.
*/

int trap(vector<int>& height) {
  
        int water = 0, left = 0, right = height.size()-1;
        int lmax = INT_MIN, rmax = INT_MIN; 
  
        while(left < right){          
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);
            
            if(lmax < rmax){
                water += lmax - height[left];
                left++;
            }else{
                water += rmax - height[right];
                right--;
            }
        }
        return water;
    }

//time complexity : O(N)
//space complexity : O(1)
