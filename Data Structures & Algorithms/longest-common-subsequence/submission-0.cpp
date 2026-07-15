#include <cstring>
class Solution {
public:
    int dp[1001][1001];
    int n;
    int m;
    int solu(string& txt1, string &txt2, int i, int j){
        if(i>=n || j>=m)
        return 0;
        
        if(txt1[i]==txt2[j])
        return 1+solu(txt1, txt2,i+1,j+1);

        if(dp[i][j]!=-1)
        return dp[i][j];

        int take=solu(txt1, txt2, i+1,j);
        int skp=solu(txt1, txt2,i, j+1);

        return dp[i][j]=max(take,skp);
    }
    int longestCommonSubsequence(string txt1, string txt2) {
        n=txt1.size();
        m=txt2.size();
        memset(dp, -1,sizeof(dp));
        return solu(txt1, txt2,0,0);
    }
};