/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/

/*
solution :

Approach 1 : brute force 

keep a variable called longest and initialize it to 1 as in any case the longest consecutive sequence will be 1.
iterate over the array, and for the current element, find the next element (element+1) in the array by iterating throgh the array again
if the next element is not found, iterate to the next element in the array.
if the next element is found, then again iterate through the array and find the next element to it, (element+2, element+3....& so on)
meanwhile also update the longest variable.
*/
  
//pseudo-code : 

longest = 1;
for(int i=0; i<n; i++){
  x = arr[i];
  count = 1;
  while(linearSearch(arr, x+1) == true) {
    x = x+1;
    count += 1;
  }
}

bool linearSearch(arr, num){
  for(int i=0; i<n; i++){
    if(arr[i] == num) return true;
  }
  return false;
}

// Time complexity : O(N*N)
// Space complexity : O(1) 


/*
approach 2 : (better solution)

sort the array and the elements in the array will be placed in consecutive order.
Initialize a variable LastSmaller to INT_MIN 
Iterating over the loop, if we now encounter a number which is greater than 1 than the LastSmaller element, 
  we will update the last smaller element with the element which is geater than 1 and also update the count variable as count+1
If we do not encounter any number in the array which is greater than 1 than the LastSmaller element, the we will start again and
  now update the LastSmaller element as the current element ad reapeat the process updating the counter variable if the counter is 
  smaller than the pervious counter
*/

//pseudo-code

int longest=1, count=1;
LastSmaller = INT_MIN;

for (int i=0; i<n; i++){
  if(arr[i]-1 == LastSmaller) {
    count = count+1;
    LastSmaller = arr[i];
  }
  else if (arr[i] != LastSmaller) {
    count = 1;
    LastSmaller = arr[i];
  }
longest = max(count, longest);
}
return longest;


/*
  
Approach 3 : Optimal solution

we will first store all the elements in an unordered set, which will erase all the duplicate elements from the array
then, for each element, we will check if that element is the starting point of the sequence by checking if 
  previous element is present in the set or not.
  if previous element is present in the set, then the element is not the starting point of the sequence and 
    to avoid further unnecessary calculations, we will skip that element.
  if for an element a previous element is not present, then that element might be the starting point of a sequence,
    thus, in this case we will look for the next elements for that starting element and find all possible next elements
*/

//code :

int longestConsecutive(vector<int>& arr) {
        
        int n= arr.size();
        if(n==0) return 0;
        int longest=1;
        int x=0, cnt=0;

        unordered_set<int> st;

        for(int i=0; i<n; i++){
            st.insert(arr[i]);
        }

        for(auto it:st){
            if(st.find(it-1)==st.end()){    
            //check if it is the first element of the sequence(if not found iterator reaches end of set)
                cnt=1;
                x=it;
            }
            while(st.find(x+1) != st.end()){
            // find if the next elements of the sequence are present in the set
                x= x+1;
                cnt= cnt+1;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }

// Time complexity : O(N)
// Space complexity : O(N)
