/*
 Problem Statement :
Given an integer array arr of size N, sorted in ascending order (with distinct values). 
Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.
*/

/*
Approach 1 : brute force approach 
Linearly traversing through the array and finding the minimum element in the array.
*/

//code :

int findMin(vector<int>& arr) {
    int n = arr.size(); 
    int mini = INT_MAX;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
    }
    return mini;
}

//time complexity : O(N)
//space complexity : O(1)

/*
Approach 2: optimal approach using binary search

Observation : if an array is rotated and sorted, then for every index, one of the two halves will be sorted.
thus, we have to identify the sorted half :
If arr[low] <= arr[mid] : In this case, we identified that the left half is sorted.
If arr[mid] <= arr[high] : In this case, we identified that the right half is sorted.
  
pick up the lowest element from the sorted half which always will be the first element
of that sorted half of the array, thus we will eliminate the sorted half after picking the min element from that half :
1. if left half(1st part) is sorted, then pick minimum as arr[low] and move low to low = mid+1 and continue comparing other elements
2. If right half is sorted(second part), then pick minimum as arr[mid] and move high to high= mid-1 and continue comparing other elements
*/

// code :

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

//time complexity : O(logN)
//space complexity : O(1)


  
