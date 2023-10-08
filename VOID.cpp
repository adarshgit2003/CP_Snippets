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
const ll N=200005;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(), order_of_key()
void solve(){
    ll n; cin>>n;
    ll a[n]; 
    for (ll i = 0; i < n; i++) cin>>a[i];
    ll gc[n];
    gc[0]=a[0];
    for (ll i = 1; i < n; i++) gc[i]=__gcd(gc[i-1],a[i]);
    for (ll i=0; i<n; i++){
        ll low=0, high=n-1, mid, ans=-1;
        while (low <= high){
            mid=low+(high-low)/2;
            if (gc[mid] % a[i] == 0){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        cout<<ans+1<<" ";
    }
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