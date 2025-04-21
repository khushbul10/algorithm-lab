// Longest Palindromic Subsequence
// Same as LCS but the second string is the reverse of the first string
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    string s1,s2; cin>>s1;
    s2=s1;
    reverse(s2.begin(), s2.end());
    int n,m;
    n=m=s1.size();
    int dp[n+1][m+1];
    char dir[n+1][m+1];

    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;
    for(int i=0; i<=n; i++) dir[i][0]='#'; 
    for(int i=0; i<=m; i++) dir[0][i]='#';


    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                dir[i][j]='D';
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j]=dp[i-1][j];
                dir[i][j]='U';
            }
            else{
                dp[i][j]=dp[i][j-1];
                dir[i][j]='L';
            }
        }
    }

    string ans="";
    int i=n, j=m;
    while(i>0 and j>0){
        if(dir[i][j]=='D'){
            ans+=s1[i-1];
            i--; j--;
        }
        else if(dir[i][j]=='U') i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<"LPS: "<<ans<<endl;
}