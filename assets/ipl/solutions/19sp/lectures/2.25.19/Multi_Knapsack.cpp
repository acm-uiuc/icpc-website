#include<bits/stdc++.h>
using namespace std;
int n,W;
int w[101],v[101],c[101],now;
deque<pair<int,int> > dq;
int dp[101][10001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>W;
   for(int i=1;i<=n;i++)
      cin>>w[i]>>v[i]>>c[i];
   for(int i=1;i<=n;i++){
      for(int r=0;r<w[i];r++){
         dq.clear();
         for(int j=0;j*w[i]+r<=W;j++){
            while(!dq.empty()&&(j-dq.front().first)>c[i])
               dq.pop_front();
            while(!dq.empty()&&(dp[i-1][j*w[i]+r]-j*v[i])>=dq.back().second)
               dq.pop_back();
            dq.push_back({j,dp[i-1][j*w[i]+r]-j*v[i]});
            dp[i][j*w[i]+r]=dq.front().second+j*v[i];
         }
      }
   }
   cout<<dp[n][W]<<endl;
}
