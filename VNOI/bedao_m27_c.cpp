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

ll n, x;
ll a[100005];
ll dp0 = -INF, dp1 = -INF, dp2 = -INF, ans = -INF;

void solve()
{
    cin >> n >> x;
    for (ll i=1; i <= n; i++) cin >> a[i];
     
    for (ll i = 1; i <= n; i++){
        ll old0 = dp0;
        ll old1 = dp1;
        ll old2 = dp2;

        dp0 = max(old0, 0LL) + a[i];
        dp1 = max({old0, old1, 0LL}) + a[i] * x;
        dp2 = max(old1, old2) + a[i];

        ans = max({ans, dp0, dp1, dp2});
    }

    cout << ans;
}

int main()
{
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
