#include<bits/stdc++.h>
using namespace std;
const long long int po = 1073741827;
#define ll long long int

ll exgcd(ll a,ll b,ll& x,ll& y){
   if(b==0){x=1;y=0;return a;}
   ll d=exgcd(b,a%b,y,x);
   y-=a/b*x;
   return d;
}
ll exp(ll a,ll b,ll mod){
   a%=mod;
   ll res=1;
   while(b){
      if(b&1)
         res=res*a%mod;
      a=a*a%mod;
      b/=2;
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   ll n,c,p,q;
   for(int T=1;T<=t;T++){
      cin>>n>>c;
      p=round(sqrt(n));
      for(;;p--){
         if(n%p==0){
            q=n/p;
            break;
         }
      }
      ll phi=(p-1)*(q-1);
      ll x,y;
      exgcd(po,phi,x,y);
      x=(x%phi+phi)%phi;
      ll u = exp(c,x,p);
      ll v = exp(c,x,q);
      ll ans =(v-u+q)%q;
      ans=ans*exp(p,q-2,q)%q;
      ans=(ans*p+u)%n;
      cout<<"Case "<<T<<": "<<ans<<endl;
   }
}
