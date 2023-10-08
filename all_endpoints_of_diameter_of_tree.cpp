#include <bits/stdc++.h>
using namespace std;

int dfs1(int node, int par, vector<int>&sub, vector<int> g[]){
    sub[node]=1;
    for (auto child: g[node]){
        if (child!=par){
            sub[node]+=dfs1(child, node, sub, g);
        }
    }
    return sub[node];
}
int dfs2(int node, int par, int want, vector<int>&sub, vector<bool> &vis, vector<int> g[]){
    for (int child: g[node]){
        if (child==par or vis[child]) continue;
        if (sub[child] > want)
            return dfs2(child, node, want, sub, vis, g);
    }
    return node;
}
vector<int> v;
void dfs3(int node, int par, int len, vector<int> g[]){
    if (len==0){
        if (g[node].size()==1){
            v.push_back(node);
        }
        return;
    }
    for (int child: g[node]){
        if (child==par) continue;
        dfs3(child, node, len-1, g);
    }
}
int longestDist=0, leaf=0;
void dfs4(int node, int par, int dist, vector<int> g[]){
    if (dist>longestDist){
        longestDist=dist;
        leaf=node;
    }
    for (auto child: g[node]){
        if (child==par) continue;
        dfs4(child, node, dist+1, g);
    }
}
vector<int> isSpecial(int n, vector<int> tree_from, vector<int> tree_to){
    vector<int> g[n+1];
    for (int i = 0; i < tree_from.size(); i++){
        g[tree_from[i]].push_back(tree_to[i]);
        g[tree_to[i]].push_back(tree_from[i]);
    }
    vector<int> sub(n+1, 0);
    int sz=dfs1(1, 0, sub, g);
    vector<bool> vis(n+1, false);
    int cent = dfs2(1, 0, sz/2, sub, vis, g);
    dfs4(cent, 0, 0, g);
    longestDist=0;
    dfs4(leaf, 0, 0, g);
    vector<int> ans(n+1, 0);
    dfs3(cent, 0, longestDist/2, g);
    for (int i: v){
        ans[i]=1;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<int> tree_from(n-1), tree_to(n-1);
    for (int i = 0; i < n-1; i++){
        cin >> tree_from[i] >> tree_to[i];
    }
    vector<int> ans=isSpecial(n, tree_from, tree_to);
    for (int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t=1; //cin>>t; 
    while (t--){
        solve();
        // cout<<"sd";
    }
    return 0;
}