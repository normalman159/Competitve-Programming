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

const ll Lim = 1e5;

vector<ll> col[Lim + 5], prefix[Lim + 5], minu(Lim + 5, 0);

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= 1e5; i++)
        col[i].pb(0);
    for (ll i = 1; i <= n; i++)
    {
        ll colum, val;
        cin >> val >> colum;
        col[colum].pb(val);
    }
    ll q;
    cin >> q;
    for (ll i = 1; i <= 1e5; i++)
    {
        prefix[i].resize(col[i].size(), 0);
        for (ll j = 1; j < col[i].size(); j++)
        {
            prefix[i][j] = prefix[i][j - 1] + col[i][j];
        }
    }
    ll sum = 0;
    while (q--)
    {
        ll ch, colum, x;
        cin >> ch >> colum >> x;
        if (ch == 1)
        {
            sum += x;
            minu[colum] += x;
        }
        else
        {
            ll l = 1, r = col[colum].size() - 1;
            ll ans = 0;
            while (l <= r)
            {
                ll mid = (l + r) >> 1;
                if (prefix[colum][mid] + mid * (sum - minu[colum]) <= x)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cout << ans << ln;
        }
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
