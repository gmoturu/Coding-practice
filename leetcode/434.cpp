/*
	https://leetcode.com/problems/number-of-segments-in-a-string/
*/
class Solution{
public:
    int countSegments(string s){
        int segments=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                count?segments+=1:segments;
                count=0;
                continue;
            }
            count++;
        }
        count?segments+=1:segments;
        return segments;
    }
};
