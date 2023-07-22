/*
Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. 
The packages must be shipped within ‘d’ days.
The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor belts 
every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.
*/

/*
Solution :

approach 1 : brute force approach

we will traverse from the maximum weight to the sum of all weights and for each number, 
check if it is possible to load all the weights within given days or not.
we will check if it is possible or not by passing the parameters to a function which checks if the number of days are equal to the given days.

*/

//pseudo-code :

int capacity(wt,days){
  for(capacity= max to sum){
    int cap = findDays(wt, capacity);
    if(daysReq<=days) return cap;
  }
}
int func(wt, capacity){
  days=1, load=0;
  for(i=0 to n-1){
    if (load + wt[i] > cap){
      days= days+1;
      load = wt[i];
    }
    else 
      load += wt[i]
  }
  return days;
}

//time complexity : O((sum-max)+1) * O(N)
//space complexity : O(1)


/*
approach 2 : optimal approach using binary search

first, find the maximum element of the given array of weights and the summation of all weights.
set two pointers, low= max(arr[]) and high = sum(arr[])
calculate mid by mid= (high+low)/2

there are now two possibilities:
1. numberOfDays <= d:  number ‘mid’ is one of the answers
  But as we want the minimum number, eliminate the right half and consider the left half(i.e. high = mid-1).
2. Otherwise, the value mid is smaller than the number required.
  that is, number greater than mid should be considered so we will consider the right half by eliminating left half by low= mid+1.
At the end of the loop, the low pointer will be pointing to the answer.

*/

//code :

//function to find the number of days required
int findDays(vector<int> &weights, int cap) {
    int days = 1, load = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (load + weights[i] > cap) {
            days += 1; 
            load = weights[i]; 
        }
        else {
            load += weights[i];
        }
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int days) {
   int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while(low<= high){
        int mid= low+(high-low)/2;
        int daysReq= findDays(weights, mid);

        if(daysReq <= days) high=mid-1;
        else low= mid+1;
    }
    return low; 
}

//time compleixty : O(log(sum-max+1)) * O(N)
//space complexity : O(1)










