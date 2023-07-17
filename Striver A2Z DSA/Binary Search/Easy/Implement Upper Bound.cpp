/*
Upper bound : the upper bound is smallest index such that arr[ind] > target

The upper bound algorithm finds the first or the smallest index in a sorted array 
where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.
*/

/*
Brute force approach :
In the brute force approach to this solution we will linearly traverse the array and compare each element 
with the target value.
The index, i, where the condition arr[i] > x is first satisfied, will be the answer.
*/

//Code for Brute force approach:

int upperBound(vector<int> &arr, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            return i;
        }
    }
    return n;
}

/*
In Optimal approach to find the upper bound, we will make use of the binary search algorithm and keep dividing the
search space into half until the condition arr[mid] > x is satisfied.
*/

//code for optimal soultion:

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

//time complexity: O(logN)
//space coplexity : O(1)

//C++ has an in built library function to fnd the upper bound:
upper_bound(arr.begin(), arr.end());




