/*
		Reverse String
		https://leetcode.com/problems/reverse-string/
*/
class Solution{
public:
    string reverseString(string s){
				for(int i=0,j=s.length()-1;i<j;swap(s[i],s[j]),i++,j--);
        return s;
    }
};
