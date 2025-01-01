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

/*0 1 -2 10 3 0 1 -2 10 3
j = 1 => 0 1 -2 10 3
j = 2 => 1 -2 10 3 0
j = 3 => -2 10 3 0 1 =>
*/
const ll LimN = 2e5 + 5;
ll seg[4 * LimN];
vector<ll> prefix;
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        seg[id] = prefix[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (u > r || v < l)
        return INF;
    if (u <= l && r <= v)
        return seg[id];
    ll mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(2 * n + 1);
    prefix.resize(2 * n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
        a[i + n] = a[i];
    prefix[0] = 0;
    for (ll i = 1; i <= 2 * n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
        seg[i] = INF;
    }
    ll ans = 0;
    build(1, 1, 2 * n);

    for (ll i = 1; i <= n; i++)
    {
        ll MI = get(1, 1, 2 * n, i, i + n);
        if (MI - prefix[i - 1] > 0)
            ans++;
    }
    cout << ans;
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
