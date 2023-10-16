/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in 
the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
*/

/*
Explaination of solution:

Approach: Sliding window

In this problem, we can either choose the elements from the begining of the array or from the end of the array.
We also can either choose some elements from the begining and some from the end of the array, the only condition 
we have to meet is either one of the elements we choose is from the begining or from the end or both.

To achieve this, we will not make a window of size k this time, but a window of size n-k, and obtain sum of all the 
elements outside of the window and not the window as we have to get the elements from either end or begining of the 
array or from both so we will keep the window in the middle and obtain sum of the left elements from the boundaries.

So, we will make a window of size n-k.
making this window size, we will get the elements at the boundary.
Now, to find out sum of those elements, we will first find out the sum of all the elements of the array:
totalSum = accumulate(arr.begin(), arr.end(), 0);

then, we will create the window and add the elements of the window in the current sum while creating the window and 
when the window size reaches n-k, we will calculate the max of all scores, by finding out max out of previous max score till now
and sum of elements other than current window elements by subtracting curSum from totalSum.
score = max(score, totalSum-curSum);

then, as the number of elements is constant k, we will maintain the window size and slide the window. while sliding 
the window, we will subtract the i'th character from the curSum variable and increment i for obtaining the next window.
*/


//code:

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int n= arr.size();
        if(n==k) return accumulate(arr.begin(), arr.end(), 0);

        int i=0, j=0;
        int curSum=0, score =0;

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        while(j<n){
            curSum += arr[j];

            if(j-i+1 == n-k){
                score = max(score, totalSum-curSum);
                curSum -= arr[i];
                i++;
            }
            j++;
        }
        return score;
    }
};

//time complexity: O(n)
//space complexity: O(1)

