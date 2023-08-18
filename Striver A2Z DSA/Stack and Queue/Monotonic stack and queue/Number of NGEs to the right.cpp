/*
Problem statement :
You are given an array 'arr' of length N.
Given Q queries, for each query, an index is given (0-based indexing) 
Answer to each query is the number of the strictly greater elements to the right of the given index element.
You must return an answer array of length M where answer[i] is the answer to the i th query.

Sample Input 1:
1 3 6 5 8 9 13 4
0 1 5

Sample output 1:
7 6 1
*/

/*
Approach 1: brute force approach

In the first apporach, we will simply iterate the array of queries and for each query index, 
we will be iterating the array of given numbers and compare all the numbers on the right to the number at the query index.
If the number to the right is greater, then we will increase the count and for each queury, 
we will find out the number of greater elements on the right.
*/

//code for brute force approach :

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
	int n = arr.size(), q = query.size();

	vector<int> answer(q, 0);

	for (int i = 0; i < q; i++) {
		int queryIndex = query[i];
    
		for (int j = queryIndex + 1; j < n; j++) {
			if (arr[j] > arr[queryIndex]) {
				answer[i]++;
			}
		}
	}
	return answer;
}

//time complexity : O(N*Q)
//space complexity : O(1)

/*
approach 2:

In this approach, we will create a stack, and traverse through the query array and for each element of the query array, we will
initialize a stack and traverse the given array from the last element to the current element from the query array.
If the element traversing from the last is greater than the query[i] then, we will push the arr[last] to the stack as it is greater 
than current element. 
We will keep pushing all the greater elements to the stack traversing from the last of the array to the current 
query[i] element. 
and finally, we will store the size of the stack, i.e. total no of elements greater than query[i] to the right of the 
array in the ans[i] th index.
*/

//code :

vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    
    vector<int>ans(query.size(),-1);
     int ind=query.size()-1;

    for(int i=query.size()-1;i>=0;i--){
	    
        int el=arr[query[i]];
        stack<int>st;
        int last=arr.size()-1;
        while(last!=query[i]){
            if(arr[last]>el)
                st.push(arr[last]);
            last--;
        }
        ans[ind]=st.size();
        ind--;
    }
    return ans;
}

//time complexity : O(N)
//space complexity : O(N)
