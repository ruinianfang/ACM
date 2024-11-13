#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll mod=1e15+7;
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1,0),b(n+1,0);
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) cin>>b[i];
    vector<ll> ran(n+1);
    mt19937_64 myrand(time(nullptr));
    for(ll i=1;i<=n;i++)
        ran[i]=myrand()%mod;
    for(ll i=1;i<=n;i++){
        a[i]=ran[a[i]];
        b[i]=ran[b[i]];
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    while(q--){
        ll l,r,L,R;
        cin>>l>>r>>L>>R;
        cout<<((a[r]-a[l-1]==b[R]-b[L-1])?"Yes\n":"No\n");
    }
    return 0;
}
