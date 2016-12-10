/*
	https://leetcode.com/problems/add-strings/
*/
class Solution{
public:
    string addStrings(string num1, string num2){
        // reverse both strings
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret;
        int i=0;
        int carry=0;
        for(int n1,n2,sum;i<num1.size() && i<num2.size();i++){
            n1=num1[i]-'0';
            n2=num2[i]-'0';
            sum=n1+n2+carry;
            sum>=10?carry=1,sum-=10:carry=0;
            ret.push_back(char(sum+'0'));
        }
        for(int n1,sum;i<num1.size();i++){
            n1=num1[i]-'0';
            sum=n1+carry;
            sum>=10?carry=1,sum-=10:carry=0;
            ret.push_back(char(sum+'0'));
        }
        for(int n2,sum;i<num2.size();i++){
            n2=num2[i]-'0';
            sum=n2+carry;
            sum>=10?carry=1,sum-=10:carry=0;
            ret.push_back(char(sum+'0'));
        }
        if(carry)
            ret.push_back(char(carry+'0'));
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
