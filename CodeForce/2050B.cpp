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
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

bool work(){
    ll n; cin >> n;
    ll sumOd = 0, sumEv = 0, cntOd =0 , cntEv = 0;
    vector<ll> v(n);
    for (auto &x : v) cin >> x;
    for (int i = 1; i<=n;i++){
        if (i & 1) sumOd += v[i-1], cntOd++;
        else sumEv += v[i-1], cntEv++;
    }
    ll k1 = sumOd / cntOd, k2 = sumEv/cntEv;
    if (k1 * cntOd != sumOd || k2 * cntEv != sumEv) return false;
    if (k1 == k2) return true;
    return false;
}

void solve(){
    ll t; cin >> t;
    while (t--){
        if (work()) cout << "YES";
        else cout << "NO";
        cout << ln;
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
