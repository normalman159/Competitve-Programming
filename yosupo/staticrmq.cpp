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

const ll SIZE = 5e5 +5;
const ll LG = 20;

ll n, q;
ll st[LG][SIZE];

void solve()
{
    cin >> n >> q;

    for (ll i = 0; i < n; i++){
        ll z; cin >> z;
        st[0][i] = z;
    }
    for (ll j = 1; j < LG; j++){
        for (ll i = 0; i + (1 << j) - 1 < n; i++){
            st[j][i] = min(st[j-1][i], st[j-1][i + (1 << (j-1))]);
        }
    }

    while (q--){
        ll l, r; cin >> l >> r;
        r--;
        ll k = __lg(r - l +1);
        cout << min(st[k][l], st[k][r - (1 << k) + 1]) << ln;
    }

}

int main()
{
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
