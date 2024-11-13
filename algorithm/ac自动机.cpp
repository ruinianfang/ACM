#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string s;
const ll mxle=8e6+1;
ll cnt,vis[mxle],ans,rev[mxle],rud[mxle];
struct trie_node{
    ll son[27];
    ll fail;
    ll flag;
    ll ans;
    void init(){
        memset(son,0,sizeof son);
        fail=flag=0;
    }
}trie[mxle];

void init(){
    for(ll i=0;i<=cnt;i++)trie[i].init();
    for(ll i=1;i<=n;i++)vis[i]=0;
    cnt=1;
    ans=0;
}

void insert(string &S,ll num){//trie的插入
    ll u=1,len=S.size();
    for(ll i=0;i<len;i++){//trie从1开始,1是空串
        ll v=S[i]-'a';
        if(!trie[u].son[v])trie[u].son[v]=++cnt;//cnt是trie节点数量
        u=trie[u].son[v];
    }
    if(!trie[u].flag)trie[u].flag=num;//结束标记
    rev[num]=trie[u].flag;//反向索引，第num个s的结束节点
    return;
}
queue<ll> q;
void getfail(){
    for(ll i=0;i<26;i++)trie[0].son[i]=1;
    q.emplace(1);
    trie[1].fail=0;//1（空）的fail是0
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        ll F=trie[u].fail;
        for(ll i=0;i<26;i++){
            ll v=trie[u].son[i];
            if(!v){//u没有i的子节点
                trie[u].son[i]=trie[F].son[i];//u的i子节点变成u失配的i
                continue;
            }//失配节点保证了返回到当前节点的最长后缀的相等前缀处
            trie[v].fail=trie[F].son[i];//u的i子节点的失配变成u失配的i
            rud[trie[F].son[i]]++;//F的i子节点入度在u有i子节点时增加
            q.emplace(v);
        }
    }
}

void query(string &S){
    ll u=1,len=S.size();
    for(ll i=0;i<len;i++){
        u=trie[u].son[S[i]-'a'];
        trie[u].ans++;
    }
}

void topu(){
    for(ll i=1;i<=cnt;i++)
        if(!rud[i])q.emplace(i);
    while(!q.empty()){
        ll f=q.front();
        q.pop();
        vis[trie[f].flag]=trie[f].ans;
        ll u=trie[f].fail;
        trie[u].ans+=trie[f].ans;
        if(!(--rud[u]))q.emplace(u);
    }
}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    init();
    for(ll i=1;i<=n;i++){//trie的构建
        cin>>s;
        insert(s,i);
    }
    getfail();
    cin>>s;
    query(s);
    topu();//拓扑排序优化
    for(ll i=1;i<=n;i++)
        cout<<vis[rev[i]]<<'\n';
    return 0;
}
