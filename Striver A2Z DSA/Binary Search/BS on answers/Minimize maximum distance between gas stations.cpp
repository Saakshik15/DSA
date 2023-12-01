/*
Problem:

On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.size()
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.

Eg. 1:
Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
*/

/*
Problem understanding and approach to solve:

Understanding the problem first,
we have given N gas stations, placed at a certain distance from each other, and the distance is given in an array,
arr = [s1, s2, s3.....sN] where s1, s2 are the co-ordinates where the gas stations will be placed at.
We are then given a number K, where K is the number of new gas stations we have to place in between these gas stations, 
such that the distance between these gas stations after placing the new gas stations will be minimized.
At the end, we have to return the maximum distance among all the gas stations, after the mininmization.

Now, for example let us suppose that the given number of gas stations N=10 and the number of new gas stations we have to place, 
i.e., K = 9. 
The gas stations are given to be on co-ordinates such that:
Arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Placing the new gas stations as minimizing as possible, we can place the 9 gas stations in between the 10 gas stations like this;

arr = [1, 1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5, 10]
Thus, in this way, the distance between the gas stations will be 0.5 for all, we cannot minimize this distance further.
Thus, the maximum of all distances is 0.5.


Now, how do we actually place new gas stations and how to decide where to place them?

For that, we will calculate the distance between all the gas stations, and for each new to-be-placed gas station, 
we will find the two gas stations who have the maximum distance in between them and reduce the distance by placing the new gas station
in between these two gas stations.

For example, given gas stations are [1, 5, 7, 8, 9] and we have to place 1 new gas station in between, then the max distance of all is
between the gas stations which are on co-ordinates 1 and 5, thus we will minimize distance by placing new station in between, ie,
[1, 3, 5, 7, 8, 9] thus the max distance which was previously 5-1=4, now has become 3-1=2 or 5-3=2.

When we have to place 2 or more gas stations instead of 1 gas station in between two fixed co-ordinates, then we will divide the total 
distance by the number of gas stations to be placed.
that is, if we have a distance of 12 between two fixed gas stations and we have to place 3 new, then we will place them as:
12/3 = 4, that is at a distance of 4 from each other.
*/


/*
Approach 1: Brute force:

//array howManyPlaced[] has the number of gas stations placed bwn two gas stations for all adj gas stations, 
//eg, howManyPlaced = [1, 0, 2], ie 1 placed bwn 1st & 2nd, 0 placed bwn 2nd & 3rd, 2 placed bwn 3rd & 4th.
                      
for(gas i->k) {     //gas station will start from 1 and go till k
  maxDist= -1       //max distance between two gas stations
  maxInd= -1        //where the max value is occuring
                    
  for(i=0 to n-1) {                       //loop from 1 to N over the given array
    diff = arr[i+1] - arr[i]             //diff = dist bwn two gas stations
    secLen = diff/(howManyPlaced[i]+1)   //+1 because the sections will be divided in 2 if 1 is placed & so on
  }                                                          
}
*/
