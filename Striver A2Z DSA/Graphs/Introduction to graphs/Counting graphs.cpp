/*
Problem statement
Return the number of undirected graphs that can be formed using 'N' vertices, allowing for disconnected 
components within the graph. Self-edges and multiple edges are not allowed.

For Example:
For N = 2,
Count is 2.

Sample Input 1: 3
Sample Output 1: 8

Sample Input 2: 5
Sample Output 2: 1024

Constraints:
1 <= ‘N’ <= 8
Time Limit: 1 sec
*/

/*
Approach:

Approach:
To determine the total number of edges possible in a graph with 'N' vertices, we can use the combination formula. 
Each edge requires two vertices so we can choose any two vertices from the 'N' vertices. Therefore, the total number 
of edges possible, denoted as 'E', is given by the formula E = (N * (N-1)) / 2.

Now, when counting the total number of graphs, we can consider that each edge in the graph may either exist or not exist. 
This gives us two options for each edge. Since there are 'E' edges, the total number of possible combinations of edge choices 
is 2^E. This represents all the different possible graphs that can be formed.

By right-shifting 1 'E' times, we essentially multiply 1 by 2 'E' times, which is equivalent to 2^E. This reduces the time complexity 
from O(log E) due to the power function to O(1). 

Although ‘E’ is relatively small but it is a good practice to use right shift instead of power for calculating a power of 2.
*/

//code:

int countingGraphs(int N){

    int ans,E;
    
    E = (N * (N-1)) / 2;      // Calculating the total number of edges possible in the graph.
    ans = 1 << E;             // Calculating the total number of graphs.

    return ans;
}

/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/
