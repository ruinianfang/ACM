#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
template <typename T>
class Segtree{
    vector<T> tree,lazy1,lazy2;
    vector<T> *arr;
    ll n,root,n4,end;
    void maintain(ll cl,ll cr,ll p){
        ll cm=cl+((cr-cl)>>1);
        if(cl!=cr){
            lazy2[p*2]*=lazy2[p];
            lazy2[p*2+1]*=lazy2[p];
            lazy1[p*2]*=lazy2[p];
            lazy1[p*2+1]*=lazy2[p];
            tree[p*2]*=lazy2[p];
            tree[p*2+1]*=lazy2[p];
            lazy2[p]=1;
            lazy1[p*2]+=lazy1[p];
            lazy1[2*p+1]+=lazy1[p];
            tree[2*p]+=lazy1[p]*(cm-cl+1);
            tree[2*p+1]+=lazy1[p]*(cr-cm);
            lazy1[p]=0;
        }
    }
    T range_sum(ll l,ll r,ll cl,ll cr,ll p){
        if(l<=cl&&cr<=r)return tree[p];
        ll m=cl+((cr-cl)>>1);
        T sum=0;
        maintain(cl,cr,p);
        if(l<=m) sum+= range_sum(l,r,cl,m,p*2);
        if(r>m) sum+= range_sum(l,r,m+1,cr,p*2+1);
        return sum;
    }
    void range_mul(ll l,ll r,T val,ll cl,ll cr,ll p){
        if(l<=cl&&cr<=r){
            lazy2[p]*=val;
            lazy1[p]*=val;
            tree[p]*=val;
            return;
        }
        ll m=cl+((cr-cl)>>1);
        maintain(cl,cr,p);
        if(l<=m)range_mul(l,r,val,cl,m,p*2);
        if(r>m)range_mul(l,r,val,m+1,cr,p*2+1);
        tree[p]=tree[2*p]+tree[2*p+1];
    }
    void range_add(ll l,ll r,T val,ll cl,ll cr,ll p){
        if(l<=cl&&cr<=r){
            lazy1[p]+=val;
            tree[p]+=(cr-cl+1)*val;
            return;
        }
        ll m=cl+((cr-cl)>>1);
        maintain(cl,cr,p);
        if(l<=m)range_add(l,r,val,cl,m,p*2);
        if(r>m)range_add(l,r,val,m+1,cr,p*2+1);
        tree[p]=tree[2*p]+tree[2*p+1];
    }
    void build(ll s,ll t,ll p){
        if(s==t){
            tree[p]=(*arr)[s];
            return;
        }
        ll m=s+((t-s)>>1);
        build(s,m,p*2),build(m+1,t,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }
public:
    explicit Segtree<T>(vector<T> v){
        n=v.size();
        n4=4*n;
        tree=vector<T>(n4,0);
        lazy1=vector<T>(n4,0);
        lazy2=vector<T>(n4,1);
        arr=&v;
        end=n-1;
        root=1;
        build(0,end,1);
        arr= nullptr;
    }
    T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
    void range_mul(int l, int r, int val) { range_mul(l, r, val, 0, end, root); }
};
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    Segtree<ll> tr(a);
    for(ll i=0;i<q;i++){
        ll op;
        cin>>op;
        if(op==1){
            ll x,y,k;
            cin>>x>>y>>k;
            tr.range_mul(x,y,k);
        }
        else if(op==2){
            ll x,y,k;
            cin>>x>>y>>k;
            tr.range_add(x,y,k);
        }
        else{
            ll x,y;
            cin>>x>>y;
            ll ans=tr.range_sum(x,y);
            cout<<ans<<endl;
        }
    }
    return 0;
}
