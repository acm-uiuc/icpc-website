#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[15];
long long int ans;
void dfs(int pos,long long int now,int cnt){
   if(pos==m){
      if(cnt&1)
         ans-=n/now;
      else
         ans+=n/now;
      return;
   }
   dfs(pos+1,now,cnt);
   now=now/__gcd(now,a[pos])*a[pos];
   if(now<=n)
      dfs(pos+1,now,cnt+1);
}
int main(){
   while(cin>>n>>m){
      ans=0;
      for(int i=0;i<m;i++)
         cin>>a[i];
      dfs(0,1,0);
      cout<<ans<<endl;
   }
}
