#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> son(320);
vector<ll> score(320);
ll n,m;
ll dp[305][305];
ll dfs(ll root) {
    dp[root][1]=score[root];
    ll p=1;
    for(auto i:son[root]) {
        ll siz=dfs(i);
        for(ll j=min(p,m+1);j>=1;j--) {
            for(ll k=0;k<=siz&&k+j<=m+1;k++)
                dp[root][j+k]=max(dp[root][j+k],dp[root][j]+dp[i][k]);
        }
        p+=siz;
    }
    return p;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(ll i=0;i<n;i++) {
        ll x;
        cin>>x>>score[i+1];
        son[x].emplace_back(i+1);
    }
    dfs(0);
    cout<<dp[0][m+1];
    return 0;
}