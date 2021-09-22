#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5;
int z[MAXN];
string stmp,ss;
void Manacher(string s){//@#.#.#.#
   int l=0,r=0;//M-box does not include r
   z[0]=1;
   for(int i=1;i<s.size();i++){
      z[i]=r>i?min(z[2*l-i],r-i):1;
      while(s[i+z[i]]==s[i-z[i]])   z[i]++;
      if(i+z[i]>r){l=i;r=i+z[i];}
   }
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>stmp;
   ss+="@#";
   for(int i=0;i<stmp.size();i++){
      ss+=stmp[i];ss+='#';
   }
   Manacher(ss);
   long long int ans=0;
   for(int i=0;i<ss.size();i++)
      ans+=z[i]/2;
   cout<<ans<<endl;
}
