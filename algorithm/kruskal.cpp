const int MAXN = 5000 + 5;
const int MAXM = 200000 + 5;
const int INF = 0x3fffffff;
struct edge {
    int u;
    int v;
    int w;
} e[MAXM];
int f[MAXN],cnt,m,n,ans;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int find(int x){
    if(f[x]==x) {
        return x;
    } else {
        f[x]=find(f[x]);//路径压缩
        return f[x];
    }
}

void Kruskal()
{
    sort(e+1,e+m+1,cmp);
    for(int i=1; i<=m; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u==v)continue;//判断两个点是否在同一颗树,同一棵树则成环跳过
        ans+=e[i].w;//权重
        f[v]=u;//v点的父亲为u，意思为(u,v)这条边加入
        cnt++;
        if(cnt==n-1)break;//所有的点构成构成一棵树
    }
}
