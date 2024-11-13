#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=105,mod=1e9+7;
ll n,K;
vector<vector<ll>> mul(vector<vector<ll>> &a,vector<vector<ll>> &b){
    vector<vector<ll>> c(N,vector<ll>(N,0));
    for(ll i=1;i<=n;i++){
        for(ll k=1;k<=n;k++){
            if(a[i][k]==0)continue;
            for(ll j=1;j<=n;j++){
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=mod;
            }
        }
    }
    return c;
}
vector<vector<ll>> kpow(vector<vector<ll>> &a,ll y){
    vector<vector<ll>> ans,x=a;
    while((y&1)!=1){
        x=mul(x,x);
        y>>=1;
    }
    ans=x;
    x=mul(x,x);
    y>>=1;
    while(y){
        if(y&1)ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>K;
    if(K==0){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(i==j)cout<<1<<' ';
                else
                    cout<<0<<' ';
            }
            cout<<endl;
        }
    }
    else{
        vector<vector<ll>> mat(N,vector<ll>(N));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                cin>>mat[i][j];
            }
        }
        vector<vector<ll>> ans(N,vector<ll>(N));
        ans= kpow(mat,K);
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++)
                cout<<ans[i][j]<<' ';
            cout<<endl;
        }
    }
    return 0;
}
