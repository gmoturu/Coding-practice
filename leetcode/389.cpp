/*
	https://leetcode.com/problems/find-the-difference/
*/
#define SZ 256
class Solution{
public:
    char findTheDifference(string s, string t){
        int hmap[SZ]={0};
        for(int i=0;i<s.size();hmap[s[i]-'0']++,i++);
        for(int i=0;i<t.size();hmap[t[i]-'0']--,i++);
        char ret='\0';
        for(int i=0;i<SZ;i++)
            if(hmap[i]==-1)
                ret=i+'0';
        return ret;
    }
};
