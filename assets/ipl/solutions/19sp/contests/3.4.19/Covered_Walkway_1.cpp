#include<bits/stdc++.h>
using namespace std;

long long int dp[1000001],pos[1000002];
deque<pair<long long int,long long int> > dq;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int n,c,slope,intercept;
   cin>>n>>c;
   for(int i=1;i<=n;i++)
      cin>>pos[i];
   dp[0]=0;
   dq.push_back({-2*pos[1],pos[1]*pos[1]+dp[0]});
   for(int i=1;i<=n;i++){
      while(dq.size()>=2&&dq[0].first*pos[i]+dq[0].second>=dq[1].first*pos[i]+dq[1].second)
         dq.pop_front();
      dp[i]=c+pos[i]*pos[i]+dq[0].first*pos[i]+dq[0].second;
      slope=-2*pos[i+1];
      intercept=pos[i+1]*pos[i+1]+dp[i];
      while(dq.size()>=2&&(dq[(int) dq.size()-2].first-dq[(int) dq.size()-1].first)*(intercept-dq[(int) dq.size()-1].second)<=(dq[(int) dq.size()-1].first-slope)*(dq[(int) dq.size()-1].second-dq[(int) dq.size()-2].second))
         dq.pop_back();
      dq.push_back({slope,intercept});
   }
   cout<<dp[n]<<endl;
}
