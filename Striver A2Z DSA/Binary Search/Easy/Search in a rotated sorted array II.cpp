/*
This question is similar to the search in a rotated sorted array, but the only difference is that the 
array might contain some duplicate elements.
Now, a problem may occur when we have duplicate elements in the array like :

[3, 1, 2, 3, 3, 3, 3]
  now, here, the mid, low and high are the same element, which is 3.
thus, it is diffucult to compare them on the basis of the previously used conditions.
  to get rid of this problem, we will trim down the search space as :
  high= high-1 and low= low+1 in coditions like these
and rest of the conditions and comparisons will be similar to the rotated sorted array
*/

//code :

int search(vector<int>& arr, int target) {
       int low=0, high=arr.size()-1;

        while(low <= high){

            int mid=(low+high)/2;
            if(arr[mid]==target) return true;

            //condition where mid=high=low
            if(arr[low]==arr[mid] && arr[low]==arr[high]){
                high=high-1;
                low=low+1;
                continue;
            }
            //check if left is sorted
            if(arr[low] <= arr[mid]) {
                if(arr[low] <= target && target <= arr[mid] ){
                    high = mid-1;
                }else{
                low = mid+1;
                }
            }
            //check if right is sorted    
            else{
                if (arr[mid]<= target && target<=arr[high]){
                    low = mid+1;
                }else{
                    high=mid-1;
                }
            }   
        }
        return 0;
    }

//time complexity : O(logN)
//space complexity : O(1)
