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
 
const ll LimN = 1e6+5;
ll n, a[LimN];

ll ucln(ll a, ll b){
    if (a==0){
        return b;
    }
    return ucln(b%a,a);
}

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll res = INF;

    for (ll i=2;i<=n;i++){
        ll k = ucln(a[i-1],a[i]);
        res = min(res,k);        
    }
    if (res == 1){
        cout << "-1";
        return;
    }
    for (ll i=2;i<=res;i++){
        if (res%i==0){
            cout << i;
            return;
        }
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}