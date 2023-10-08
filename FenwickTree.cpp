#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FenwickTree{
    vector<ll> bit;
    ll n;
    FenwickTree(ll _n){
        n=_n;
        bit.assign(n+1, 0);
    }
    ll query(ll idx){
        ll ans=0;
        while (idx>0){
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
    ll query(ll l, ll r){
        return query(r)-query(l-1);
    }
    void update(ll idx, ll val){
        while (idx<=n){
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }
};
