#include <bits/stdc++.h>
#define ll long long
#define All(v) v.begin(), v.end()
using namespace std;

template <typename Node, typename Update>
struct LazySGT{
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr;
    ll n, s; 
    LazySGT(ll _n, vector<ll>&v){
        n=_n;
        arr=v;
        s=1;
        while (s < 2*n) s=s<<1;
        tree.resize(s); fill(All(tree), Node());
        lazy.resize(s); fill(All(lazy), false);
        updates.resize(s); fill(All(updates), Update());
        build(0, n-1, 0);
    }
    void build(ll start, ll end, ll index){
        if (start==end){
            tree[index]=Node(arr[start]);
            return;
        }
        ll mid=(start+end)/2;
        build(start, mid, 2*index+1);
        build(mid+1, end, 2*index+2);
        tree[index].merge(tree[2*index+1], tree[2*index+2]);
    }
    void pushdown(ll index, ll start, ll end){
        if (lazy[index]){
            ll mid=(start+end)/2;
            apply(2*index+1, start, mid, updates[index]);
            apply(2*index+2, mid+1, end, updates[index]);
            updates[index]=Update();
            lazy[index]=false;
        }
    }
    void apply(ll index, ll start, ll end, Update &u){
        if (start!=end){
            lazy[index]=true;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(ll start, ll end, ll index, ll l, ll r, Update &u){
        if (start>r or end<l) return;
        if (start>=l and end<=r){
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        ll mid=(start+end)/2;
        update(start, mid, 2*index+1, l, r, u);
        update(mid+1, end, 2*index+2, l, r, u);
        tree[index].merge(tree[2*index+1], tree[2*index+2]);
    }
    Node query(ll start, ll end, ll index, ll l, ll r){
        if (start>r or end<l) return Node();
        if (start>=l and end<=r){
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        ll mid=(start+end)/2;
        Node left, right, ans;
        left=query(start, mid, 2*index+1, l, r);
        right=query(mid+1, end, 2*index+2, l, r);
        ans.merge(left, right);
        return ans;
    }
    void make_update(ll l, ll r, ll val){
        Update new_update = Update(val);
        update(0, n-1, 0, l, r, new_update);
    }
    Node make_query(ll left, ll right){
        return query(0, n-1, 0, left, right);
    }
};

struct Node1{
    ll val;
    Node1(){
        val=0;
    }
    Node1(ll p1){
        val=p1;
    }
    void merge(Node1 &l, Node1 &r){
        val=l.val+r.val;
    }
};

struct Update1{
    ll val;
    Update1(){
        val=0;
    }
    Update1(ll val1){
        val=val1;
    }
    void apply(Node1 &a, ll start, ll end){
        a.val = (end-start+1)*val;
    }
    void combine(Update1& new_update, ll start, ll end){
        val += new_update.val;
    }
};
int main(){
#ifndef ONLINE_JUDGE                                                                                                                                
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif  

    return 0;
}