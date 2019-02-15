#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long int a[100000];

template<int maxn>
struct Matrix{
   long long int entry[maxn][maxn];
   Matrix(){memset(entry,0,sizeof entry);}
   Matrix<maxn> operator*(const Matrix<maxn> &rhs) const{
      Matrix<maxn> res;
      for(int i=0;i<maxn;i++)
         for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
               res.entry[i][k]=(res.entry[i][k]+entry[i][j]*rhs.entry[j][k])%mod;
      return res;
   }
};
Matrix<2> Fib(Matrix<2> T,long long int x){
   if(x==1) return T;
   Matrix<2> ans=Fib(T,x/2);
   ans=ans*ans;
   if(x%2)  ans=ans*T;
   return ans;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>a[i];
      a[0]=__gcd(a[0],a[i]);
   }
   Matrix<2> trans;
   trans.entry[0][0]=1;
   trans.entry[0][1]=1;
   trans.entry[1][0]=1;
   trans.entry[1][1]=0;
   cout<<Fib(trans,a[0]).entry[1][0]<<endl;
}
