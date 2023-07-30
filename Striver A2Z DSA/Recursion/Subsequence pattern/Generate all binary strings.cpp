/*
Given an integer N, your task is to generate and return all binary strings of length N such that there are no consecutive 1s in the strings.
A binary string is that string which contains only 0 and 1.
*/

/*
Approach : Recursive

Since we need to generate all substrings which does not have consecutive 1s we can simply start adding new characters to the string 
until the length of the string is ‘K’ taking care that if the last character of the current string is ‘1’ we cannot add another ‘1’ as 
it will result in consecutive ‘1s.’ Otherwise, if the last character is ‘0’ we have 2 options either to add ‘1’ or ‘0’. 
We explore both the options recursively until we have a string of desired length i.e ‘K’ .
We start with a string of length 1. Now we have 2 options, the first character can be a ‘1’  or a ‘0’.
We take both possibilities and use our recursive function to find the answer.
 
Our recursive function works as follows:
Check the last character of the string. If the last character is ‘0’ we can add a ‘0’ or ‘1’ at the end of the string.
If the last character is ‘1’ we can add only ‘0’ and not ‘1’ because if we add ‘1’ and the last character is also ‘1’ we will 
violate the condition that there must be no consecutive ‘1’ in the string.
Once the length of the string is equal to ‘K’ we add it to our answer array.
Lastly, we sort the array and return all possible strings of length ‘K’ with no consecutive ‘1’.
*/

//code : 

void Helper(int N, string &str, int ind, vector<string> &ans) {
    if (ind == N) {
        // Terminate binary string and push it to the answer vector.
        ans.push_back(str);
        return;
    }
    // If the previous character is '1', then we put only '0' at the end of the string.
    // For example, if str = "01", then the new string would be "010".
    if (str[ind - 1] == '1') {
        str[ind] = '0';
        Helper(N, str, ind + 1, ans);
    }
    // If the previous character is '0', then we put both '1' and '0' at the end of the string.
    // For example, if str = "00", then the new string would be "001" and "000".
    if (str[ind - 1] == '0') {
        str[ind] = '0';
        Helper(N, str, ind + 1, ans);
        str[ind] = '1';
        Helper(N, str, ind + 1, ans);
    }
}

vector<string> generateString(int N) {
    vector<string> ans;
    if (N == 0) return ans;
    
    // Create a string with N elements.
    string str(N, '0');
    // First character is '0'.
    str[0] = '0';
    Helper(N, str, 1, ans);
    // First character is '1'.
    str[0] = '1';
    Helper(N, str, 1, ans);
    sort(ans.begin(), ans.end());

    return ans;
}

//Time Complexity : O(2 ^ N), ‘N’ is the length of the string.
//Space Complexity : O(N), ‘N’ is the length of the string

