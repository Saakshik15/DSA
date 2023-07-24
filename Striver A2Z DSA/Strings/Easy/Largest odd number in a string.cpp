/*
Given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a
non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
  
Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
  
Example 2:
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".
  
Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.
*/

/*
Solution :

approach : Initialize an integer i with the value of the length of the string str minus 1.(or last char of str)
Start a while loop that continues as long as i is greater than or equal to 0.(so that we traverse the whole string)
Inside the loop, check if the character at index i in str is either '3', '1', '5', '7', or '9'. If true, 
it means the character is an odd digit, so the function returns the original str as the largest odd number.
If the character at index i is not an odd digit, remove the last character from str using the pop_back() function.
Decrement the value of i by 1 to move to the previous character in the string.
Once the loop ends, return the modified str string, which will be the largest odd number present in the original str.
If no odd digit is found in str, the loop will exit, and the function will return the empty string str as the largest odd number.
*/

//code :

string largestOddNumber(string str) {
    int i= str.length()-1;

    while(i>=0){
        if(str[i]%2==1) return str;
        else str.pop_back();
            i--;
    }
    return str;
}

//time complexity : O(n)
//space complexity : O(1)






