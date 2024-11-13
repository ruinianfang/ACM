#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
struct node{
    ll w,h;
    node(){w=0,h=0;}
    node(ll w,ll h):w(w),h(h){}
    bool operator <(const node &a)const{return a.w==w?h>a.h:w>a.w;}
};
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    priority_queue<node> q;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        q.emplace(node(a[i],1));
    }
    while((q.size()-1)%(k-1)!=0)q.emplace(node(0,1));
    ll ans=0;
    while (q.size()>=k){
        ll h=-1,w=0;
        for(ll i=1;i<=k;i++){
            node t=q.top();
            q.pop();
            h=max(h,t.h);
            w+=t.w;
        }
        ans+=w;
        q.emplace(node(w,h+1));
    }
    cout<<ans<<endl;
    cout<<q.top().h-1<<endl;
    return 0;
}
