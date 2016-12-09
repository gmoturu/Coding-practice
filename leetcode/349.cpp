/*
	https://leetcode.com/problems/intersection-of-two-arrays/
*/
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        map<int,int> hmap;
        vector<int> ret;
        for(int i=0;i<nums1.size();hmap[nums1[i]]=1,i++);
        for(int i=0;i<nums2.size();i++)
            if(hmap[nums2[i]]!=0)
                hmap[nums2[i]]++;
        for (map<int,int>::iterator it=hmap.begin();it!=hmap.end();it++)
            if(it->second>1)
                ret.push_back(it->first);
        return ret;
    }
};
