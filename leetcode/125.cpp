/*
	https://leetcode.com/problems/valid-palindrome/
*/
class Solution{
public:
    bool isPalindrome(string s){
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            for(;!isalnum(s[i]);i++);
            for(;!isalnum(s[j]);j--);
            if(i<j && tolower(s[i])!=tolower(s[j]))
                return 0;
        }
        return 1;
    }
};
