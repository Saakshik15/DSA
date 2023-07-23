/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. 
There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. 
If the allocation of books is not possible. return -1
*/

/*

Solution :

Approach 1 : brute force 

We will linearly check for the possibility whether we can assign a specific number of pages to a student 
by linearly cheking through each possibility from max element of the array of pages to the total sum of pages of all books.

for each iteration, we will pass the number of pages each student can have to a function to check if the number of students are 
equal to the given number of students. 
if it is equal, we will return the number of pages.

Edge case : if number of students is greater than the number of books, then it is impossible to allocate these books among students.
*/

//pseudo-code :

int findPages(vector<int>& arr, int n, int m){
    if(m>n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for(int pages=low; pages<high; pages++) {
    int studentCnt = countStudents(arr, pages, n);
    if(studentCnt == m) return pages;
  }
  return low;
}

//function to calculate the number of students for the pages
int countStudents(vector<int> &arr, int pages, int n){
  int students=1, pagesAlloted=0;
  for(int i=0; i<n; i++){
    if(pagesAlloted + arr[i] <= pages){
      pagesAlloted += arr[i];
    }
    else{
      students++;
      pagesAlloted =arr[i];
    }
  }
return students;
}

//time complexity : O(sum-max+1) + O(N)
//space complexity : O(1)

/*
Approach 2 : Optimal approach using binary search

Edge case : If m > n: In this case, book allocation is not possible and so, we will return -1.
set low= max(arr[]) and high = sum(arr[])
find mid = (low+high)/2
Eliminate the halves based on the number of students returned by countStudents():
1.If students > m: we will eliminate the left half and consider the right half(i.e. low = mid+1).
2.else mid is possible answer but we want minimum ans, so eliminate right half and consider the left half(i.e. high = mid-1).
finally return low as low will be pointing to answer.

*/

//code :

int countStudents(vector<int> &arr, int pages, int n){
  int students=1, pagesAlloted=0;
  for(int i=0; i<n; i++){
    if(pagesAlloted+arr[i] <= pages){
      pagesAlloted += arr[i];
    }
    else{
      students++;
      pagesAlloted = arr[i];
    }
  }
return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low<=high){
        int mid= low+(high-low)/2;
        int studentCnt = countStudents(arr, mid, n);

        if(studentCnt > m) low= mid+1;
        else high= mid-1;
    }
    return low;
}

//time complexity : O(log(sum-max+1)) * O(N)
//space comlexity : O(1)



