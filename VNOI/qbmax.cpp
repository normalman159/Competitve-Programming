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

const ll SIZE = 1e2 + 5;

ll m, n, dp[SIZE][SIZE], a[SIZE][SIZE];

void solve()
{
    cin >> m >> n;
    for (ll i = 1; i <= m; i++){
        for (ll j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            dp[i][j] = -INF;
        }
    }
    for (ll i = 1; i <= m; i++) dp[i][1] = a[i][1];

    for (ll j = 2; j <= n; j++){
        for (ll i = 1; i <= m; i++){
            dp[i][j] = a[i][j] + max({dp[i][j-1], dp[i-1][j-1], dp[i+1][j-1]});
        }
    }

    ll ans = -INF;
    for (ll i = 1; i <= m; i++){
        ans = max(ans, dp[i][n]);
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
