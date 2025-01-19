#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9 + 7;
const double eps = 1e-12;
#define forn(i, e) for (ll i = 1; i <= e; i++)
#define forsn(i, s, e) for (ll i = s; i <= e; i++)
#define rforn(i, s) for (ll i = s; i >= 1; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout << #x << " = " << x << ln
#define pb push_back
#define fi first
#define se second
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

// Modulo Calculation
ll add(ll x, ll y)
{
    return (x % MOD + y % MOD) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)(x % MOD) *  (y % MOD) % MOD;
}


void solve(){
    ll n, l, r, x; cin >> n >> l >> r >> x;
    vector<ll> c(n);
    for (ll i=0; i<n;i++) cin >> c[i];
    ll ans = 0;
    for (ll i=0; i< (1<<n); i++){
        ll high = -INF,low = INF, total = 0;
        for (ll j = 0; j < n; j++){
            if (i & (1 << j)){
                total+=c[j]; high = max(high, c[j]); low = min(low, c[j]);
            }
        }
        if (l <= total && total <= r && (high - low) >= x) ans++;
    }
    cout << ans;
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
