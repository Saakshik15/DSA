//Problem statement:
//find the largest element in an array

//approach 1 : linear search 
//code:

int largest(vector<int> arr){
  
  int maxi= INT_MIN;
  for(int =0; i<arr.size(); i++) maxi = max(maxi, arr[i]);
  return maxi;
}

//time complexity: O(n)
//space complexity: O(1)

//approach 2: sorting
//code:

int largest(vector<int> arr){
  
  sort(arr.begin(), arr.end());
  return arr[arr.size()-1];
}

//time complexity: O(nlogn)
//space complexity: O(1)



