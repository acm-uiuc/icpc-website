#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > frog[100001];//w,l,h
int dp[100000001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,d;
   cin>>n>>d;
   for(int i=0;i<n;i++)
      cin>>frog[i].second.first>>frog[i].first>>frog[i].second.second;
   sort(frog,frog+n);
   for(int i=n-1;i>=0;i--)
      for(int j=0;j<frog[i].first;j++){
         if(j+frog[i].first>100000000)
            break;
         dp[j]=max(dp[j],dp[j+frog[i].first]+frog[i].second.second);
      }
   int ans=0;
   for(int i=0;i<n;i++)
      if(dp[frog[i].first]+frog[i].second.first>d)   ans++;
   cout<<ans<<endl;

}
