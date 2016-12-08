/*
	https://leetcode.com/problems/first-unique-character-in-a-string/
*/
#define SZ 26
#define OF 97
class Solution{
public:
    int firstUniqChar(string s){
        int hmap[SZ]={0};
        for(int i=0;i<s.size();hmap[s[i]-OF]++,i++);
        for(int i=0;i<s.size();i++)
            if(hmap[s[i]-OF]==1)
                return i;
        return -1;
    }
};
