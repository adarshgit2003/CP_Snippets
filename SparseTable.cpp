#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct SparseTable{
    vector<ll> arr;
    vector<vector<ll>> dp;
    ll n;
    SparseTable(ll _n, vector<ll>&v){
        n=_n;   
        arr=v;
        dp.resize(n, vector<ll>(32, 0));
        build();
    }
    void build(){
        for (ll i=n-1; i>=0; i--){
            for (ll j=0; j<32; j++){
                ll range=i+(1LL<<j)-1;
                if (range>=n) break;
                if (j==0) dp[i][j]=arr[i];
                else dp[i][j]=min(dp[i][j-1], dp[i+(1LL<<(j-1))][j-1]);
            }
        }
    }
    ll query(ll l, ll r){
        ll len=r-l+1;
        ll k=31-__builtin_clz(len);
        return min(dp[l][k], dp[r-(1LL<<k)+1][k]);
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
    SparseTable st(n, v);
    ll q; cin>>q;
    while(q--){
        ll l, r; cin>>l>>r;
        cout<<st.query(l, r)<<endl;
    }
    return 0;
}