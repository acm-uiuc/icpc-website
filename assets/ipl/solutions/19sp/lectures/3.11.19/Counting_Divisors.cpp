#include<bits/stdc++.h>
using namespace std;

int cnt[1000001];
map<long long int,int> m;
long long int num[5];
int main(){
   for(int i=0;i<5;i++)
      cin>>num[i];
   for(int i=0;i<5;i++){
      for(int j=2;j<=1000000;j++)
         while(num[i]%j==0){
            cnt[j]++;
            num[i]/=j;
         }
      if(num[i]!=1)
         m[num[i]]++;
   }
   long long int ans=1;
   for(int i=2;i<=1000000;i++)
      ans*=(cnt[i]+1);
   for(auto i=m.begin();i!=m.end();i++)
      ans*=(i->second+1);
   cout<<ans<<endl;
}
