/*
Problem statement : given a sorted array, find the first and last occurance of an element in the array, else return -1
*/

/*
Brute force approach :
In the brute force approach we will be traversing the array lineraly and find out the first and last occurance of that element in the array
*/

//pseudo code for brute force approach :

first=-1, last=-1;
for(i=0 to n-1){
  if(arr[i] == x){
    if(first = -1) {
      first = i
    }
    last=i;
  }
}

//time complexity : O(N)

/*
Optimal solution :
In the optimal solution we will be using the lower bound and upper bound to find the first and last occurances of the element in the array.

First occurance :
Initially consider the start=0 and the end=n-1 pointers and result as -1.

Till start does not crossover end pointer compare the mid element :
1.If the mid element is equal to the key value, store the mid-value in the result and move the end pointer to mid-1(move leftward)
2.Else if the key value is less than mid element then end= mid-1(move leftward)
3.Else do start = mid+1 (move rightwards)
  
Last occurance :
Initially consider the start=0 and the end=n-1 pointers and the result as -1.

Till start does not crossover end pointer compare the mid element :
1.If the mid element is equal to the key value, store the mid-value in the result and move the start pointer to mid+1(move leftward)
2.Else if the key value is less than the mid element then end= mid-1(move leftward)
3.Else do start = mid+1 (move rightwards)
*/

//code for first and last occurances:

int LastOccurance(int n, int key, vector < int > & v) {
  int start = 0;
  int end = n - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      start = mid + 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

int FirstOccurance(int n, int key, vector < int > & v) {
  int start = 0;
  int end = n - 1;
  int res = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (v[mid] == key) {
      res = mid;
      end = mid - 1;

    } else if (key < v[mid]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return res;
}

  
