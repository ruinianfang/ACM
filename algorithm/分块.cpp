#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N=1e6+5,M=1e4+5;
vector<ll> st(M,0),ed(M,0),belong(N,0),siz(M,0),a(N,0),t(N,0),de(M,0);
void Sort(ll k){
    for(ll i=st[k];i<=ed[k];i++)
        t[i]=a[i];
    sort(t.begin()+st[k],t.begin()+ed[k]+1);
}
void Modify(ll l,ll r,ll c){
    ll x=belong[l],y=belong[r];
    if(x==y){
        for(ll i=l;i<=r;i++)
            a[i]+=c;
        Sort(x);
        return;
    }
    for(ll i=l;i<=ed[x];i++)
        a[i]+=c;
    for(ll i=st[y];i<=r;i++)
        a[i]+=c;
    for(ll i=x+1;i<y;i++){
        de[i]+=c;
    }
    Sort(x);
    Sort(y);
}
ll getans(ll l,ll r,ll c){
    ll ans=0,x=belong[l],y=belong[r];
    if(x==y){
        for(ll i=l;i<=r;i++){
            if(a[i]+de[x]>=c)
                ans++;
        }
        return ans;
    }
    for(ll i=l;i<=ed[x];i++){
        if(a[i]+de[x]>=c)
            ans++;
    }
    for(ll i=st[y];i<=r;i++){
        if(a[i]+de[y]>=c)
            ans++;
    }
    for(ll i=x+1;i<y;i++){
        ll index= lower_bound(t.begin()+st[i],t.begin()+ed[i]+1,c-de[i])-t.begin();
        ans+=1+ed[i]-index;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,q;
    cin>>n>>q;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll num=sqrt(n);
    for(ll i=1;i<=num;i++){
        st[i]=n/num*(i-1)+1;
        ed[i]=n/num*i;
    }
    ed[num]=n;
    for(ll i=1;i<=num;i++){
        for(ll j=st[i];j<=ed[i];j++){
            belong[j]=i;
        }
        Sort(i);
        siz[i]=ed[i]-st[i]+1;
    }
    for(ll i=0;i<q;i++){
        char op;
        cin>>op;
        if(op=='M'){
            ll l,r,w;
            cin>>l>>r>>w;
            Modify(l,r,w);
        }
        else{
            ll l,r,c;
            cin>>l>>r>>c;
            cout<<getans(l,r,c)<<endl;
        }
    }
    return 0;
}