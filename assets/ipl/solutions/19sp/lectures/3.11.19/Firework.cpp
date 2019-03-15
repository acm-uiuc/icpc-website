#include<bits/stdc++.h>
using namespace std;

long long int p[20];
int a[20],cnt=0;
long long int ans=0;
void dfs(long long int now,long long int nphidoverd,int pos){
   if(pos==cnt){
      ans+=nphidoverd;
      return;
   }
   dfs(now,nphidoverd,pos+1);
   nphidoverd=nphidoverd/p[pos]*(p[pos]-1);
   for(int i=0;i<a[pos];i++){
      now*=p[pos];
      dfs(now,nphidoverd,pos+1);
   }
}
int main(){
   long long int n,x;
   cin>>n;
   x=n;
   for(int i=2;i<=1000000;i++)
      if(x%i==0){
         p[cnt]=i;
         while(x%i==0){
            x/=i;
            a[cnt]++;
         }
         cnt++;
      }
   if(x!=1){
      p[cnt]=x;
      a[cnt]=1;
      cnt++;
   }
   dfs(1,n,0);
   cout<<ans*8+1<<endl;
}
