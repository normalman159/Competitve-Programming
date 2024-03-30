#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 2*1e6+5;
ll n, a[LimN],cnt[LimN];

unordered_map<ll,ll> mp;


void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    //j-i = a[i] + a[j];
    //j - a[j] = i + a[i] -> j - a[j] = i - a[i] + 2*a[i]
    for (ll i=1;i<=n;i++){
        mp[i-a[i]]++;
    }
    ll res = 0;
    for (ll i=1;i<n;i++){
        res+=mp[i-a[i]+2*a[i]];
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}