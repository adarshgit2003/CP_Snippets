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
#define prDouble(x) cout << fixed << setprecision(10) << x
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define minus cout<<"-1"<<nl
#define r(x) return void(x)
#define c(x) cout<<x<<nl
using namespace std;
using namespace __gnu_pbds;
const ll N=200005;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(), order_of_key()
string solve(){
    ll n, m; cin>>n>>m;
    vector<ll> v(m);
    for (ll i=0; i<m; i++) cin>>v[i];
    if (m==1) return ts(v[0]);
    sort(All(v));
    ll low=0, high=n, mid, ans;
    ll mn=*min_element(All(v));
    while (low <= high){
        mid=low+(high-low)/2;
        if (mid>mn){
            low=mid+1;
            continue;
        }
        ll mx=max((v[0]-mid+v[1]-mid), v[m-1]-mid);
        if (mx<=n-mid){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    } 
    return ts(ans);
}
int main(){
#ifndef ONLINE_JUDGE                                                                                                                                                       
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif  
    fastio();
    ll t=1; cin>>t;
    while (t--)
        cout<<solve()<<nl;
    return 0;
}