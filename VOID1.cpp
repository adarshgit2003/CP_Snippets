/* Adarsh Kumar Shrivastav */

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define All(v) v.begin(), v.end()
#define ll long long
#define ull unsigned long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(), order_of_key()

/* Constants */
#define MOD 1000000007
#define inf 1e18
#define PI 3.141592653589793238462
#define mod 998244353
const ll N=200005;

/* Shorthands */
#define ff first
#define ss second
#define nl "\n"
#define ts to_string
#define pb push_back
#define set_bits __builtin_popcountll
#define sz(x) ((ll)(x).size())
#define prDouble(x) cout << fixed << setprecision(10) << x
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define minus cout<<"-1"<<nl
#define r(x) return void(x)
#define c(x) cout<<x<<nl

/* Debugging Only for Local Machine */
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<": "; show(x); cerr<<nl;
#else 
#define debug(x)
#endif

void show(ll t) {cerr << t;}
void show(int t) {cerr << t;}
void show(string t) {cerr << t;}
void show(char t) {cerr << t;}
void show(double t) {cerr << t;}
void show(ull t) {cerr << t;}

template <class T, class V> void show(pair <T, V> p);
template <class T> void show(vector <T> v);
template <class T> void show(set <T> v);
template <class T, class V> void show(map <T, V> v);
template <class T> void show(multiset <T> v);
template <class T, class V> void show(pair <T, V> p) {cerr << "{"; show(p.ff); cerr << ","; show(p.ss); cerr << "}";}
template <class T> void show(vector <T> v) {cerr << "[ "; for (T i : v) {show(i); cerr << " ";} cerr << "]";}
template <class T> void show(set <T> v) {cerr << "[ "; for (T i : v) {show(i); cerr << " ";} cerr << "]";}
template <class T> void show(multiset <T> v) {cerr << "[ "; for (T i : v) {show(i); cerr << " ";} cerr << "]";}
template <class T, class V> void show(map <T, V> v) {cerr << "[ "; for (auto i : v) {show(i); cerr << " ";} cerr << "]";}
void show(pbds v) {cerr << "[ "; for (auto i : v) {show(i); cerr << " ";} cerr << "]";}

/* Some useful functions */
bool isPrime(ll n){if (n<=1) return false; if (n<=3) return true; if (n%2==0 || n%3==0) return false; ll i; for (i=5; i*i<=n; i+=6) if (n%i==0 || n%(i+2)==0) return false; return true; }
ll modPower(ll a, ll b, ll m){ll ans=1; a = a%m; if (a==0) return 0; while (b>0){ if (b&1) ans = (ans*a)%m; b = b>>1; a = (a*a)%m;} return ans;}
ll modulo_inverse(ll n){return modPower(n,MOD-2, MOD);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, modulo_inverse(b), m) + m) % m;}  //only for prime m
ll gcd(ll a, ll b){if (b==0) return a; return (b, a%b);}
ll fact(ll n){ll ans=1; while (n){ans = (ans*n)%MOD; n--;} return ans;}
bool cmpSec(pair<ll, ll> a, pair<ll, ll> b){return a.ss < b.ss;}
vector<ll> sieve(ll n){vector<bool> isprime(n+1, true); vector <ll> ans; for (ll i=2; i<=n; i++){if (isprime[i]){ans.pb(i);for (ll j=i*i; j<=n; j+=i)isprime[j]=false;}} return ans;}
vector<ll> primeFactors(ll n){vector<ll> ans; while (n%2==0){ans.pb(2);n=n/2;} for (ll i=3; i<=sqrt(n); i+=2){while (n%i==0){ans.pb(i);n=n/i;}} if (n>2) ans.pb(n); return ans;}
vector<ll> uniquePrimeFactors(long long n) {vector<long long> factorization; for (int d : {2, 3, 5}) {if(n % d == 0) factorization.push_back(d); while (n % d == 0) {n /= d;}}
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;for (long long d = 7; d * d <= n; d += increments[i++]) {if(n % d == 0) factorization.push_back(d); while (n % d == 0) {n /= d;}if (i == 8) i = 0;}
    if (n > 1) factorization.push_back(n);return factorization;
}

/* Vector and Pair i/o */
template <typename T> istream &operator>>(istream &is, vector<T> &v){for (auto &i : v) is >> i; return is;}
template <typename T> ostream &operator<<(ostream &os, vector<T> v){for (auto &i : v) os << i << ' '; return os;}
template <typename T, typename U> istream &operator>>(istream &is, pair<T, U> &p){is >> p.first >> p.second; return is;}
template <typename T, typename U> ostream &operator<<(ostream &os, pair<T, U> p){os << p.first << ' ' << p.second<<nl;return os;}
/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void solve(){
    
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll t=1; cin>>t;
    while (t--) 
        solve();
    return 0;
}