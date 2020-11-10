Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]


---------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    
    void go(string s,int open,int close,vector<string> &v){
        if(open == 0 and close == 0){
            v.push_back(s);
            return ;
        }
        if(open != 0){
            string s1 = s;
            s1.push_back('(');
            go(s1,open -1 ,close,v);
        }
        if(close > open){
            string s1 = s;
            s1.push_back(')');
            go(s1,open,close - 1,v);
            return;
        }
    }
    
    
    vector<string> generateParenthesis(int n) {
        int open = n, close = n;
        vector<string> v;
        string s = "";
        go("",open,close,v);
        return v;
    }
};
