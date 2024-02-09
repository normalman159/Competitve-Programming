#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const ll LimN = 2*1e6 + 5;
ll n;
ll a[LimN],b[LimN];
unordered_map<ll,ll> mp;
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        ll x; cin >> x;
        b[i] = x;
        a[i] = x - i; 
    } 
    for (ll i=1;i<=n;i++){
        // cout << a[i] << " ";
        mp[a[i]]++;
    }
    cout << ln;
    ll res = 0,res1=0;
    for (ll i=1;i<n;i++){
        // for (ll j=i+1;j<=n;j++){
        //     if (a[j]+a[i]==-2*i){
        //         cout << i << " " << j << ln;
        //         res1++;
        //     }
        // }
        res+=mp[-(2*i+a[i])];
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
