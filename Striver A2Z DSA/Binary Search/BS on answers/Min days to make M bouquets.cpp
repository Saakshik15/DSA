/*
Problem Statement: You are given ‘N’ roses and you are also given an array ‘arr’ 
where ‘arr[i]’  denotes that the ‘ith’ rose will bloom on the ‘arr[i]th’ day.
You can only pick already bloomed roses that are adjacent to make a bouquet. 
You are also told that you require exactly ‘k’ adjacent bloomed roses to make a single bouquet.
Find the minimum number of days required to make at least ‘m’ bouquets each containing ‘k’ roses. Return -1 if it is not possible.
*/

/*
solution:

approach 1: brute force approach

to check all possible answers from min(arr[]) to max(arr[]). The minimum number for which all making the bouquets is possible is the ans.

running a loop from min(arr[]) to max(arr[]), check all possible answers.
Next, for each day we will check if creating the bouquets is possible or not with the help of a function
if it is possible we will return the day, and if it's not we will iterate to next element.
If loop ends we can conclude that is impossible to make m bouquets, return -1.
Edge case: If m*k > arr.size: This means we have insufficient flowers. So, it is impossible to make m bouquets and we will return -1.
*/

//pseudo-code:

bool possible(arr[], day, m, k){
  cnt=0, noOfBouquets=0;
  for(i=0 to n-1){
    if(arr[i] <= day) cnt++;
    else {
      noOfBouquets = (cnt/k);
      cnt=0;
    }
  }
  noOfBouquets += (cnt/k);
  
if(noOfBouquets>=m) return true;
return false;
}

int minDays(int bloomDay[], int m, int k){

  if(m*k > bloomDay.size()) return -1;

  for(i= mini to i= maxi){
    if(possible(bloomDay, i, m, k) return i;
  }
  return -1;
}

//time complexity : O(maxi-mini+1) * O(N)


/*
approach 2: optimal approach using binary search

If m*k > arr.size: it is impossible to make m bouquets and we will return -1.
set high= max(arr[]), and low= min(arr[]) 
now, mid = (low+high)/2,
check if for that mid it is possible to make bouquets or not using a function 
Eliminate the halves based on the value returned by possible():
1. If possible() returns true: mid is one of the possible answers, but we want the minimum number.
  So, we will eliminate the right half and consider the left half ( high = mid-1).
2. If possible() returns false the value mid is smaller 
  so, we will eliminate the left half and consider the right half(i.e. low = mid+1).
Finally return the value of low as the pointer will be pointing to the answer.

*/

//code :

bool isPossible(vector<int>& arr, int mid, int m, int k){
        int cnt=0, curr=0;

        for(int i=0; i<arr.size(); i++){
            if(mid>=arr[i]) curr++;
            else{
                cnt += curr/k;
                curr=0;
            }
        }
        cnt += curr/k;
        return cnt>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= 1ll*m * 1ll*k;
        if(bloomDay.size()<val) return -1;

        int low= *min_element(bloomDay.begin(), bloomDay.end());
        int high= *max_element(bloomDay.begin(), bloomDay.end());

        while(low<=high){
            int mid= (low+high)/2;
            if(isPossible(bloomDay, mid, m, k)) high= mid-1;
            else low= mid+1;
        }
        return low;
    }

//time complexity: O(log(max-min+1) * N)
//space comlexity : O(1)


  
