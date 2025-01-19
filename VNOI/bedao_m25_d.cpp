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
ll n, m;
vector<ll> a, b;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a.resize(n + m + 2);
        b.resize(n + m + 2);
        for (ll i = 1; i <= n + m + 1; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n + m + 1; i++)
            cin >> b[i];
        vector<ll> id(n + m + 2, 0);
        for (ll i = 1; i <= n + m + 1; i++)
        {
            id[i] = id[i-1] + 1;
        }
        sort(id.begin() + 1, id.end(), [](ll x, ll y)
             { return a[x] - b[x] > a[y] - b[y]; });
        ll suma = 0, sumb = 0;
        for (ll i = n + m + 1; i >= n + 1; i--)
        {
            sumb += b[id[i]];
        }
        for (ll i = n + 1; i >= 1; i--)
        {
            suma += a[id[i]];
        }
        vector<ll> ans(5e5 + 5, 0);
        for (ll i = 1; i <= n + m + 1; i++)
        {
            if (i <= n + 1)
            {
                ans[id[i]] = suma - a[id[i]] + sumb - b[id[n + 1]];
            }
            else
            {
                ans[id[i]] = suma - a[id[n + 1]] + sumb - b[id[i]];
            }
        }
        for (ll i = 1; i <= n + m + 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ln;
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
