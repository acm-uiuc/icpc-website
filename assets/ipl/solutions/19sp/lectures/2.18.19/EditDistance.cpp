#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string s,t;
int main(){
   cin>>s>>t;
   int ls=s.length();
   int lt=t.length();
   s.insert(0," ");
   t.insert(0," ");
   for(int i=0;i<=ls;i++)
      dp[i][0]=i;
   for(int i=0;i<=lt;i++)
      dp[0][i]=i;
   for(int i=1;i<=ls;i++)
      for(int j=1;j<=lt;j++)
         dp[i][j]= s[i]==t[j] ? dp[i-1][j-1] : 1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
   cout<<dp[ls][lt]<<endl;

}
