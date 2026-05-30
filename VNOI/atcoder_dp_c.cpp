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

const ll SIZE = 1e5 + 5;

ll n, dp[SIZE][3] = {0};

void solve()
{
    cin >> n;

    for (ll i = 1; i <= n; i++){
        ll a, b, c; cin >> a >> b >> c;
        dp[i][0] = max(dp[i-1][1] + a, dp[i-1][2] + a);
        dp[i][1] = max(dp[i-1][0] + b, dp[i-1][2] + b);
        dp[i][2] = max(dp[i-1][0] + c, dp[i-1][1] + c);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}

int main()
{
    
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);
    fast_cin();
    solve();
    return 0;
}
