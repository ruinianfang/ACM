#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Node {
    Node *son[2];//俩子树
    ll val,prio;
    ll recnt;
    ll siz;

    Node(ll val):val(val),siz(1),recnt(1) {
        son[0]=son[1]=nullptr;
        prio=rand();
    }

    void upd_siz() {
        siz=recnt;
        if(son[0]!=nullptr) siz+=son[0]->siz;
        if(son[1]!=nullptr) siz+=son[1]->siz;
    }
};
ll tmp_pre,tmp_nex;
enum rot_type{LF=1,RT=0};//枚举类型，旋转的类型

void _rotate(Node *&cur,rot_type dir) {
    Node *tmp=cur->son[dir];//暂时的根
    cur->son[dir]=tmp->son[!dir];
    tmp->son[!dir]=cur;
    cur->upd_siz(),tmp->upd_siz();
    cur=tmp;//引用，根给回根变量
}

void _insert(Node *&cur,ll val) {
    if(cur==nullptr) {
        cur=new Node(val);
        return ;
    }
    if(val==cur->val) {
        cur->recnt++;
        cur->siz++;
    }
    else if(val<cur->val) {
        _insert(cur->son[0],val);
        if(cur->son[0]->prio<cur->prio)
            _rotate(cur,RT);
        cur->upd_siz();
    }
    else {
        _insert(cur->son[1],val);
        if(cur->son[1]->prio<cur->prio)
            _rotate(cur,LF);
        cur->upd_siz();
    }
}

void _del(Node *&cur,ll val) {
    if(val>cur->val) {
        _del(cur->son[1],val);
        cur->upd_siz();
    }
    else if(val<cur->val) {
        _del(cur->son[0],val);
        cur->upd_siz();
    }
    else {
        if(cur->recnt>1) {
            cur->recnt--;
            cur->siz--;
            return;
        }
        ll state=0;
        state|=(cur->son[0]!=nullptr);
        state|=((cur->son[1]!=nullptr)<<1);

        Node *tmp=cur;
        switch (state) {
            case 0: {
                delete cur;
                cur=nullptr;
                break;
            }
            case 1: {
                cur=tmp->son[0];
                delete tmp;
                break;
            }
            case 2: {
                cur=tmp->son[1];
                delete tmp;
                break;
            }
            case 3: {
                rot_type dir=cur->son[0]->prio<cur->son[1]->prio?RT:LF;
                _rotate(cur,dir);
                _del(cur->son[!dir],val);
                cur->upd_siz();
                break;
            }
        }
    }
}

ll _rank(Node *&cur,ll val) {
    ll less_siz=cur->son[0]==nullptr?0:cur->son[0]->siz;
    if(val==cur->val)
        return 1+less_siz;
    if(val<cur->val) {
        if(cur->son[0]!=nullptr)
            return _rank(cur->son[0],val);
        return 1;
    }
    if(cur->son[1]!=nullptr)
        return less_siz+cur->recnt+_rank(cur->son[1],val);
    return cur->siz+1;
}
ll _find(Node *cur,ll rank) {
    ll less_siz=cur->son[0]==nullptr?0:cur->son[0]->siz;
    if(rank<=less_siz)
        return _find(cur->son[0],rank);
    if(rank<=less_siz+cur->recnt)
        return cur->val;
    return _find(cur->son[1],rank-less_siz-cur->recnt);
}

ll _findpre(Node *cur,ll val) {
    if(val<=cur->val) {
        if(cur->son[0]!=nullptr)
            return _findpre(cur->son[0],val);
    }
    else {
        tmp_pre=cur->val;
        if(cur->son[1]!=nullptr)
            _findpre(cur->son[1],val);
        return tmp_pre;
    }
    return -1;
}

ll _findnex(Node *cur,ll val) {
    if(val>=cur->val) {
        if(cur->son[1]!=nullptr)
            return _findnex(cur->son[1],val);
    }
    else {
        tmp_nex=cur->val;
        if(cur->son[0]!=nullptr)
            _findnex(cur->son[0],val);
        return tmp_nex;
    }
    return -1;
}
int main() {
    srand(time(nullptr));
    ios::sync_with_stdio(false),cin.tie(nullptr);
    ll n;
    cin>>n;
    Node *root=nullptr;
    while(n--) {
        ll op,x;
        cin>>op>>x;
        switch (op) {
            case 1: {
                _insert(root,x);
                break;
            }
            case 2: {
                _del(root,x);
                break;
            }
            case 3: {
                ll ans=_rank(root,x);
                cout<<ans<<endl;
                break;
            }
            case 4: {
                ll ans=_find(root,x);
                cout<<ans<<endl;
                break;
            }
            case 5: {
                ll ans=_findpre(root,x);
                cout<<ans<<endl;
                break;
            }
            case 6: {
                ll ans=_findnex(root,x);
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
