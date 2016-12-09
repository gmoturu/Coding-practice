/*
	https://leetcode.com/problems/valid-anagram/
*/
#define SZ 26
#define OF 97

class Solution{
public:
    bool isAnagram(string s, string t){
        int hmap[SZ]={0};
        for(int i=0;i<s.size();hmap[s[i]-OF]++,i++);
        for(int i=0;i<t.size();hmap[t[i]-OF]--,i++);
        for(int i=0;i<SZ;i++)
            if(hmap[i]!=0)
                return false;
        return true;
    }
};
