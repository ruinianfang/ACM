#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    vector<ll> Log(n+1);
    Log[1]=0;
    for(ll i=2;i<=n;i++)
        Log[i]=Log[i/2]+1;
    vector<vector<ll>> f(n+1,vector<ll>(Log[n]+1));
    for(ll i=1;i<=n;i++)
        cin>>f[i][0];
    for(ll i=1;i<=Log[n];i++){
        for(ll j=1;j+(1<<i)-1<=n;j++){
            f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
    for(ll i=1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        ll s=Log[r-l+1];
        cout<<max(f[l][s],f[r-(1<<s)+1][s])<<'\n';
    }
    return 0;
}
