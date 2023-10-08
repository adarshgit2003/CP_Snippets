#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ts to_string
#define ff first
#define ss second
#define pb push_back
#define nl "\n"
#define MOD 1000000007
#define mod 998244353
#define inf 1e18
#define All(v) v.begin(), v.end()
#define set_bits __builtin_popcountll
#define prDouble(x) cout << fixed << setprecision(10) << x <<nl
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define minus cout<<"-1"<<nl
#define r(x) return void(x)
#define c(x) cout<<x<<nl
using namespace std;
using namespace __gnu_pbds;
const ll N=1000005;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(), order_of_key()
ll seg[4*N],lazy[4*N];
ll arr[N];
void build(ll start, ll end, ll index){
    if (start==end){
        seg[index]=arr[start];
        return;
    }
    ll mid=(start+end)/2;
    build(start,mid,2*index+1);
    build(mid+1,end,2*index+2);
    seg[index]=seg[2*index+1]+seg[2*index+2];
}
void lazyUpdate(ll start, ll end, ll index){
    if (lazy[index] != 0){
        seg[index] += (end - start + 1) * lazy[index];
        if (start != end) { // push down to children
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
    }
}
void update(ll start, ll end, ll index, ll l, ll r, ll val){
    lazyUpdate(start, end, index); // pending updates
    if (start > r or end < l) return; // no overlap
    if (start >= l and end <= r) {  // complete overlap
        lazy[index] = val; // current update
        lazyUpdate(start, end, index);
        return;
    }
    ll mid=(start+end)/2; // partial overlap
    update(start,mid,2*index+1,l,r,val);
    update(mid+1,end,2*index+2,l,r,val);
    seg[index]=seg[2*index+1]+seg[2*index+2]; // update current node
}
ll query(ll start, ll end, ll index, ll l, ll r){
    lazyUpdate(start, end, index); // pending updates
    if (start > r or end < l) return 0; // no overlap
    if (start >= l and end <= r) return seg[index]; // complete overlap
    ll mid=(start+end)/2; // partial overlap
    ll left=query(start,mid,2*index+1,l,r);
    ll right=query(mid+1,end,2*index+2,l,r);
    return left+right;
}
void solve(){

}   
int main(){
#ifndef ONLINE_JUDGE                                                                                                                                
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif  
    fastio(); 
    ll t=1; cin>>t;
    while(t--)
        solve();
    return 0;
} 