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
#define All(v) v.begin(), v.end()
#define set_bits __builtin_popcountll
#define prDouble(x) cout << fixed << setprecision(10) << x
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order(), order_of_key()

// Using less<ll> as the comparator orders the set in ascending order
// Using greater<ll> as the comparator orders the set in descending order
// Using less_equal<ll> as the comparator orders the set in ascending order and allows duplicates
// Using greater_equal<ll> as the comparator orders the set in descending order and allows duplicates


void solve(){
    pbds s; // Declaring an ordered set
    // Inserting elements
    s.insert(1);
    s.insert(10);
    s.insert(5);
    s.insert(7);
    s.insert(5); // This will be ignored as it is a duplicate

    // Printing the set
    for(auto x: s) cout<<x<<" "; // 1 5 7 10
    cout<<nl<<nl;
    // Finding the k-th element
    // Returns an iterator to the k-th largest element (counting from zero)
    cout << "0th element: " << *s.find_by_order(0) << nl; // 1
    cout << "1st element: " << *s.find_by_order(1) << nl; // 5
    cout << "2nd element: " << *s.find_by_order(2) << nl; // 7
    cout << "3rd element: " << *s.find_by_order(3) << nl; // 10
    cout<<nl;

    // Finding the number of elements less than k
    // Returns the number of items in a set that are strictly smaller than our item
    cout << "Number of elements less than 5: " << s.order_of_key(5) << nl; // 1
    cout << "Number of elements less than 6: " << s.order_of_key(6) << nl; // 2
    cout << "Number of elements less than 11: " << s.order_of_key(11) << nl; // 4
    cout<<nl;

    // lower_bound() -> Lower Bound of x = first element in the set which is >= x
    cout<<"Lower Bound of 5: "<<*s.lower_bound(5)<<nl; // 5
    cout<<"Lower Bound of 6: "<<*s.lower_bound(6)<<nl; // 7
    cout<<nl;

    // upper_bound() -> Upper Bound of x = first element in the set which is > x
    cout<<"Upper Bound of 5: "<<*s.upper_bound(5)<<nl; // 7
    cout<<"Upper Bound of 6: "<<*s.upper_bound(6)<<nl; // 7
    cout<<nl;

    // Erasing elements
    s.erase(5); // Erases the element 5
    s.erase(s.find_by_order(1)); // Erases the 2nd element in the set

    for (auto x: s) cout<<x<<" "; // 1 10

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
        solve();
    return 0;
} 
