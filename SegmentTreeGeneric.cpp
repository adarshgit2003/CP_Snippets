#include <bits/stdc++.h>
#define ll long long
#define All(v) v.begin(), v.end()
using namespace std;

template <typename Node, typename Update>
struct SegTree{
    vector<Node> tree; 
    vector<ll> arr; // type may change
    ll n, s;
    SegTree(ll _n, vector<ll> &v){ // Change if type is updated
        arr=v;
        n=_n;
        s=1;
        while (s<2*n) s=s<<1;
        tree.resize(s);
        fill(All(tree), Node());
        build(0, n-1, 0);
    }
    void build(ll start, ll end, ll index) {  // Never change this
        if (start==end){
            tree[index]=Node(arr[start]);
            return;
        }
        ll mid=(start+end)/2;
        build(start, mid, 2*index+1);
        build(mid+1, end, 2*index+2);
        tree[index].merge(tree[2*index+1], tree[2*index+2]);
    }
    void update(ll start, ll end, ll index, ll query_index, Update &u){ // Never change this
        if (start==end){
            u.apply(tree[index]);
            return;
        }
        ll mid=(start+end)/2;
        if (mid >= query_index)
            update(start, mid, 2*index+1, query_index, u);
        else 
            update(mid+1, end, 2*index+2, query_index, u);
        tree[index].merge(tree[2*index+1], tree[2*index+2]);
    }
    Node query(ll start, ll end, ll index, ll l, ll r){ // Never change this
        if (start > r or end < l)
            return Node();
        if (start >= l and end<=r)
            return tree[index];
        ll mid=(start+end)/2;
        Node left, right, ans;
        left = query(start, mid, 2*index+1, l, r);
        right = query(mid+1, end, 2*index+2, l, r);
        ans.merge(left, right);
        return ans;
    }
    void make_update(ll index, ll val){
        Update new_update = Update(val);
        update(0, n-1, 0, index, new_update);
    }
    Node make_query(ll l, ll r){
        return query(0, n-1, 0, l, r);
    }
};
struct Node1{
    ll val; // may change 
    Node1(){ 
        val=0;  // may change
    }
    Node1(ll p1){  // Actual node
        val=p1;  // may change
    }
    void merge(Node1& l, Node1& r){  // Merge two child nodes
        val=l.val+r.val;  // may change
    }
};
struct Update1{
    ll val; // may change
    Update1(ll p1){  // Actual update
        val=p1; // may change
    }
    void apply(Node1 &a){  // Apply update to given node
        a.val += val; // may change
    }
};
int main(){
#ifndef ONLINE_JUDGE                                                                                                                                
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif  
    ll n; cin>>n;
    vector<ll> v(n);
    for (ll i=0; i<n; i++) cin>>v[i];
    SegTree<Node1, Update1> seg = SegTree<Node1, Update1>(n, v);
    cout<<seg.make_query(0, n-1).val<<endl;
    seg.make_update(0, 1);
    cout<<seg.make_query(0, n-1).val<<endl;
    return 0;
}