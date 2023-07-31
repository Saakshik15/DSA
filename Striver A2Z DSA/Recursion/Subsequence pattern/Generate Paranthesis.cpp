void backtrack(int open, int closed, int n, vector<string>& result, string str){
        if(open == n && closed == n){
            result.push_back(str);
            return;
        }
        if(open<n){
            backtrack(open+1, closed, n, result, str+"(");
        }
        if(closed < n && closed < open){
            backtrack(open, closed+1, n, result, str+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str;

        backtrack(0,0,n,result,str);
        return result;
    }
