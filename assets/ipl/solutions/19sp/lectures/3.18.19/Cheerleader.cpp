
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e6+7;
int c[501][501];

int main(){
   int t;
   c[0][0]=1;
   for(int i=1;i<=500;i++){
      c[i][0]=1;
      for(int j=1;j<=i;j++)
         c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
   }
   cin>>t;
   for(int T=1;T<=t;T++){
      int n,m,k;
      cin>>n>>m>>k;
      long long int ans=0;
      ans=c[n*m][k]-2*c[(n-1)*m][k]-2*c[n*(m-1)][k]+4*c[(n-1)*(m-1)][k]+c[(n-2)*m][k]+c[n*(m-2)][k]-2*c[(n-2)*(m-1)][k]-2*c[(n-1)*(m-2)][k]+c[(n-2)*(m-2)][k];
      ans=(ans%mod+mod)%mod;
      cout<<"Case "<<T<<": "<<ans<<endl;
   }
}
