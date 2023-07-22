/*
Problem Statement: You are given an array of integers ‘arr’ and an integer i.e. a threshold value ‘limit’. 
Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, 
the sum of the division’s result is less than or equal to the given threshold value.
*/

/*
Solution : 

Approach 1 : brute force approach 

To find the minimum value which can satisfy the condition ( divisor<=threshold) 
we can linearly check for each number from 1 to max(arr[]) and return the element when found.
*/

//pseudo-code :

int SmallestDivisor(int arr[], int threshold){
  for(i =1 to max(arr[])){
    if(isDivisor == true) return i;
  }
}

//function to find if the number is smallest divisor or not
bool isDivisor(int arr[], int num, int threshold) {
  for(i = 0 to arr.size()-1){
    sum += ceil(arr[i]/num);
  }
  if(sum <= threshold) return true;
  return false;
}

//time complexity : O(max * N)
//space comlexity : O(10


/*
  
Approach 2 : optimal approach using binary search

We will first set two pointers, low = 1 and high= max(arr[])
then, calculating mid= (high+low)/2
checking if the mid is the divisor, there are two possible cases :
1. the mid is not a possible answer
  in this case, the ceil value determined by dividing elements of array by mid might be greater than thrshold value
  thus, we will search in the right half and eliminate left half by low = mid+1
2. the mid is a possible answer
  in this case, as we have to find the minimum value, we will look further to the left half by high = mid-1
finally, when the search space will be exhausted, we will return the answer which will be number pointed by low.

*/

//code :


//function to find if the mid is a possible divisor or not
bool isDivisor(vector<int>& arr, int num, int thr){
    double sum=0;
    for(int i=0; i<arr.size(); i++){
        sum += ceil((double)arr[i]/(double)num);
    }
    if(sum<=thr) return true;
    return false;
}

//function which returns the smallest possible divisor
int smallestDivisor(vector<int>& nums, int threshold) {
    int low=1;
    int high= *max_element(nums.begin(), nums.end());
    int ans=0;

    while(low<=high){
        int mid = low+ (high-low)/2;

        if(isDivisor(nums, mid, threshold)){
            ans= mid;
            high= mid-1;
        }
        else low= mid+1;
    }
    return ans;
}

//time complexity : O(log(max) * N)
//space complexity : O(1)






