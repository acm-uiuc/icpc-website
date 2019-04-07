#include<bits/stdc++.h>
using namespace std;
const int mod = 1e8+7;
int z[1100000],S,P;
void Zvalue(int s[],int len){
   z[0]=len;
   int l=0,r=0,x;
   for(int i=1;i<len;i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<len&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;};
      }
      else
         z[i]=z[i-l];
   }
}
long long int power(long long int x,int y){
   long long int res=1;
   while(y){
      if(y&1)
         res=res*x%mod;
      y/=2;
      x=x*x%mod;
   }
   return res;
}
int pos[360000];
int dif[1100000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>S>>P;
   for(int i=0;i<P;i++)
      cin>>pos[i];
   sort(pos,pos+P);
   dif[P]=-1;
   for(int i=0;i<P;i++)
      dif[P+i+1]=dif[2*P+i+1]=dif[i]=(pos[(i+1)%P]-pos[i]+360000)%360000;
   Zvalue(dif,3*P+1);
   int k;
   for(k=P+2;;k++)
      if(z[k]==P){
         k-=(P+1);
         break;
      }
   long long int ans=0;
   for(int i=0;i<P/k;i++)
      ans=(ans+power(S,k*__gcd(i,P/k)))%mod;
   ans=ans*power(P/k,mod-2)%mod;
   cout<<ans<<endl;
}
