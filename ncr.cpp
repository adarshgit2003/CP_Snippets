ll modPower(ll a, ll b, ll m){ll ans=1; a = a%m; if (a==0) return 0; while (b>0){ if (b&1) ans = (ans*a)%m; b = b>>1; a = (a*a)%m;} return ans;}
ll modulo_inverse(ll n){return modPower(n,MOD-2, MOD);}
ll fact[N], invfact[N];
void calc(){
    fact[0]=1;
    for (ll i=1; i<N; i++) fact[i]=(fact[i-1]*i)%MOD;
    invfact[N-1]=modulo_inverse(fact[N-1]);
    for (ll i=N-2; i>=0; i--) invfact[i]=(invfact[i+1]*(i+1))%MOD;
}
ll ncr(ll n, ll r){
    if (r>n) return 0;
    ll ans=(fact[n]*invfact[r])%MOD;
    ans=(ans*invfact[n-r])%MOD;
    return ans;
}