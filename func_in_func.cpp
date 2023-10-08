#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    cin>>n;
    auto evenOdd = [&] (int n){
        if (n%2==0)
            return "Even";
        return "Odd";
    };
    cout<<evenOdd(4)<<"\n";
    return 0;
}