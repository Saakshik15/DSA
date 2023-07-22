/*
Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. 
Find the ‘kth’ positive integer missing from ‘vec’.
*/

/*
Solution :

Approach 1 : brute force 

traverse the array linearly using a for loop,
If vec[i] <= k: increase the value of k by 1.
Otherwise, break out of the loop.
Finally, return the value of k.
*/

//pseudo-code :

int findKthPositive(vector<int>& arr, int k) {
    for(int i=0; i<arr.size(); i++) {
    if(arr[i] <= k) k++;
    else break;
    }
    return k;
}

//time complexity : O(N)
//space complexity : O(1)

/*
Approach 2 : optimal approach using binary search

set low = 0 and high = n-1
calculate mid = (low+high) / 2 
now, there are two cases for eliminating the halves :
calculate the number of missing numbers : missing_numbers = vec[mid] - (mid+1).
1. If missing_numbers < k: we are currently at a smaller index, as we want a larger index, consider the right half(i.e. low = mid+1).
2. we have to consider smaller indices. So, eliminate the right half and consider the left half(i.e. high = mid-1).
Finally the value of (k+high+1) is the kth missing number and return it.
*/

//code :
int findKthPositive(vector<int>& arr, int k) {
    int low=0, high=arr.size()-1;

    while(low<=high){
        int mid = (low+high)/2;
        int missing = arr[mid]-(mid+1);
        if(missing<k) low= mid+1;
        else high= mid-1;
    }
    return k+high+1;
}

//time complexity : O(logN)
//space complexity : O(1)


//if the solution reuqires to find the missing element from the first element of the array and not from 1, then code will be :

int KthMissingElement(int a[], int n, int k){
    if(a[n-1]-a[0]==n-1){
        return -1;
    }
    int low=0, high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(a[mid]-(a[0]+mid)<k){
            low=mid+1;
        } else{
            high=mid-1;
        }
    }
    if(a[0]+high+k>a[n-1]){
        return -1;
    }
    return a[0]+high+k;
}







