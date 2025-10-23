class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n=str1.length();
        int m = str2.length();
        string res="";
        if((str1+str2)!=(str2+str1))
        return res;

        int max=gcd(n,m);
        for (int i=0; i<max; i++){
            res+=str1[i];

        }
        return res;
        
    }
};