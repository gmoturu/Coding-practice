/*
	https://leetcode.com/problems/single-number/
*/
class Solution{
public:
    int singleNumber(vector<int>& nums){
        int res=0;
        for(int i=0;i<nums.size();res^=nums[i],i++);
        return res;
    }
};
