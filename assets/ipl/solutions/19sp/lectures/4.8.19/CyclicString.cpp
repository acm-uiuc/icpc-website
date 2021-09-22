#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
int fail[MAXN];
void FailureFunction(string pattern){
   fail[0]=0;
   for(int i=1;i<pattern.size();i++){
      fail[i]=fail[i-1];
      while(fail[i]>0&&pattern[fail[i]]!=pattern[i])
         fail[i]=fail[fail[i]-1];
      if(pattern[fail[i]]==pattern[i]) fail[i]++;
   }
}
string s;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   if(s.size()==1)
      return -1;
   FailureFunction(s);
   if(s.size()%(s.size()-fail[s.size()-1])||(s.size()/(s.size()-fail[s.size()-1]))==1)
      cout<<"Acyclic"<<endl;
   else
      cout<<"Cyclic"<<endl;
}
