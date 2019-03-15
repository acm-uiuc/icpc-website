#include<bits/stdc++.h>
using namespace std;
int cnt[10001];
int main(){
   int n,fac,x,y;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>fac;
      cnt[fac]++;
   }
   for(x=10000;;x--)
      if(cnt[x])
         break;
   for(int i=1;i<=x;i++)
      if(x%i==0)
         cnt[i]--;
   for(y=x;;y--)
      if(cnt[y])
         break;
   cout<<x<<' '<<y<<endl;
}
