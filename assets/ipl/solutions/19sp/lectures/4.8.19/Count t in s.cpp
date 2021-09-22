#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int fail[MAXN];

void FailureFunction(string& pattern){
   fail[0]=0;
   for(int i=1;i<pattern.size();i++){
      fail[i]=fail[i-1];
      while(fail[i]>0&&pattern[fail[i]]!=pattern[i])
         fail[i]=fail[fail[i]-1];
      if(pattern[fail[i]]==pattern[i]) fail[i]++;
   }
}
int cnt=0;
void KMP(string& text,string& pattern){
   FailureFunction(pattern);
   for(int match=0,i=0;i<text.size();i++){
      while(match>0&&pattern[match]!=text[i])
         match=fail[match-1];
      if(pattern[match]==text[i])   match++;
      if(match==pattern.size()){
         // cout<<i-match+1<<endl;
         cnt++;
         match=fail[match-1];
      }
   }
}
string s,t;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s>>t;
   KMP(s,t);
   cout<<cnt<<endl;
}
