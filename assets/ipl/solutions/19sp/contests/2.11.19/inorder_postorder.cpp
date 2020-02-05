#include<bits/stdc++.h>
using namespace std;

int inorder[10000],postorder[10000],pos[10000];
bool recur(int in_start,int post_start,int length){
   if(length==0)
      return true;
   int rootpos=pos[postorder[post_start+length-1]];
   if(rootpos>=in_start&&rootpos<in_start+length){
      int leftlength=rootpos-in_start;
      return recur(in_start,post_start,leftlength)
             &&recur(in_start+leftlength+1,
                     post_start+leftlength,
                     length-leftlength-1);
   }
   else return false;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>inorder[i];
      pos[inorder[i]]=i;
   }
   for(int i=0;i<n;i++)
      cin>>postorder[i];
   if(recur(0,0,n)) cout<<"Valid"<<endl;
   else  cout<<"Invalid"<<endl;
}
