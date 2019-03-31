#include <bits/stdc++.h>
#define ll long long 
using namespace std; 
ll product(ll x) 
{ 
    ll prod = 1; 
    while (x) { 
        prod *= (x % 10); 
        x /= 10; 
    } 
    return prod; 
} 
ll findNumber(ll l, ll r) 
{ 
    string a = to_string(l); 
    string b = to_string(r); 
    ll ans = r; 
    for (ll i = 0; i < b.size(); i++) { 
        if (b[i] == '0') 
            continue;  
        string curr = b; 
        curr[i] = ((curr[i] - '0') - 1) + '0'; 
        for (ll j = i + 1; j < curr.size(); j++) 
            curr[j] = '9'; 
        ll num = 0; 
        for (auto c : curr) 
            num = num * 10 + (c - '0'); 
        if (num >= l && product(ans) < product(num)) 
            ans = num; 
    } 
  
    return product(ans); 
} 
  
// Driver Code 
int main() 
{ 
    ll n;
    cin>>n;
    cout << findNumber(1, n) << endl; 
  
    return 0; 
} 
