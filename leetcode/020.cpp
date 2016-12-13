/*
	https://leetcode.com/problems/valid-parentheses/
*/
class Solution{
public:
    bool isValid(string s){
        if(s.size()%2)
            return 0;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }
            switch(stk.top()){
                case '[':
                    s[i]==']'?stk.pop():stk.push(s[i]);
                    break;
                case '{':
                    s[i]=='}'?stk.pop():stk.push(s[i]);
                    break;
                case '(':
                    s[i]==')'?stk.pop():stk.push(s[i]);
                    break;
                default:
                    return 0;
            }
        }
        return stk.empty();
    }
};
