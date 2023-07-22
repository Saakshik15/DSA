/*
Problem Statement: You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/

/*
Solution :

Approach 1: brute force 

*/

//pseudo-code :

int aggressiveCows(int arr[], int cows){
  sort(arr, arr+n);
  for(i=0 to max-min){
    if(canPlace(arr, i, cows)) continue;
    else return (i-1);
  }
}

//function to fint out if we can place a cow using the distance or not
bool canPlace(int arr[], int dist, int cows){
  cowsCnt = 1, prevCow = arr[0];
  if(arr[i]- prevCow >= dist) {
    cowsCnt ++;
    prevCow = arr[i];
  }
  if (cowsCnt >= cows) return true;
  else return false;
}

//time complexity : O(max-min) * O(N)
//space complexity : O(1)

/*
Approach 2 : optimal approach using binary search 

sort the given array.
set low = 1 and high = max(arr[])-min(arr[])
calculate mid = (low+high)/2
Eliminate the halves based on the boolean value returned by canPlace(arr[], dist, cows):
canPlace(arr[], dis, cows) This function will return true if it is possible to place all the cows with a minimum distance of mid.
there are two cases based on the returned value:
1. If true, mid’ can be answer, but we want max number, so eliminate the left half and consider the right half(i.e. low = mid+1).
2. Otherwise, mid is greater, so eliminate the right half and consider the left half(i.e. high = mid-1).
Finally, return the value of high as the pointer will be pointing to the answer.

*/

//code :

//function to find if we can place or not
bool canPlace(vector<int> &position, int dist, int cows) {
    int n = position.size(); 
    int cntCows = 1; 
    int last = position[0]; 
    for (int i = 1; i < n; i++) {
        if (position[i] - last >= dist) {
            cntCows++;
            last = position[i]; 
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    int n = position.size(); 
    sort(position.begin(), position.end());

    int low = 1, high = position[n - 1] - position[0];
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(position, mid, m) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

//time complexity : O(log(max-min)) * O(N)
//space complexity : O(1)
