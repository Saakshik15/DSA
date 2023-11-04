/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
Your goal is to maximize the number of your content children and output the maximum number.
*/

//Approach : two pointer and greedy

/*
Sort the greed factors of children and the sizes of cookies in non-decreasing order.
Initialize a variable count to 0 to keep track of the number of children that can be content with a cookie.
Use two pointers i and j to point to the current child's greed factor and the current cookie size, respectively.
Iterate over the two sorted arrays, and for each cookie size, check if it can satisfy the current child's greed factor. 
If so, assign the cookie to the child, increment count and move on to the next child and cookie. 
If not, move on to the next cookie.
Return count.
*/


//code:

lass Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0;
        int count =0;

        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                count++; i++; j++;
            } else {
                j++;
            }
        }
        return count;
    }
};

//time complexity: O(nlogn)
//space complexity: O(1)
