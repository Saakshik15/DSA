/*
Problem Statement: Koko is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. 
An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.

Each hour, Koko chooses a non-empty pile of bananas and eats ‘k’ bananas. 
If the pile contains less than ‘k’ bananas, then Koko consumes all the bananas and won’t eat any more bananas in that hour.

Find the minimum number of bananas ‘k’ to eat per hour so that Koko can eat all the bananas within ‘h’ hours.
*/

/*
Solution :

approach 1 : brute force approach 

to check all possible answers from 1 to max(a[]). The minimum number for which the required time <= h, is the ans.

Find the maximum value i.e. max(a[]) in the given array.
Running a loop(i) from 1 to max(a[]), check all possible answers.
For each number i, calculate the hours required to consume all the bananas from the pile using a different function
The first i, for which the required hours <= h, we will return that value of i.
*/

//pseudo-code :

BS(arr[], maxHours){

for(i=1 to max(arr[]) {
  reqTime = func(arr,i);
  if (reqTime<= maxHours) return i;
}

//function to calculate hours 
func(arr, hourly){
  totalHrs=0;
  for(i=0 to n-1){
    totalHrs += ceil(arr[i]/hourly);
  }
return totalHrs;
}

//time complexity : O(max) * O(N)
//space complexity : O(1)
//gives TLE

/*

Approach 2 : optimal appproach using binary search

The maximum number of Bananas required to eat per hour by Koko at maximum will always be the maximum
number of bananas in the pile, ie max element of the array.
Ans the minimum number of bananas to eat per hour will always be 1
So, the search space for applying the binary search will be from 1 to max element of the pile.

So, initially low=1, high = max(arr[]) 
find out mid by mid = (high+low)/2
there will be two cases in this problem,
1. number of hours determined by mid exceed max hours
  in this case, we will move the low to mid+1 th index
2. number of hours determined by mid is a possible case
  in this case, as we have to find for the minimum ans possible, we will move high to high= mid-1
finally, when the search space will be exhausted, ie, when high crossess low, the ans will be the number at which low will be pointing.
*/

//pseudo-code :

BS(arr[], maxHours){

  int low=1, high = maxEle(arr[]);
  while(low<=high){
  
    int mid= (low+high)/2;
  
    totalHrs = func(arr, mid);
  
    if(totalHrs <= maxHours){
      ans = mid;
      high = mid-1;
    }
    else low = mid+1;
}
//function to calculate the total hours
func(int mid, int arr[]){
  totalHrs=0;
  for(i=0 to n-1){
    totalHrs += ceil(arr[i]/hourly);
  }
return totalHrs;
}

//time complexity : O(log MaxEle) * O(N)
//space complexity : O(1)
