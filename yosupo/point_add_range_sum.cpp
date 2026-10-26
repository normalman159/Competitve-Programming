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
ll a[SIZE], st[4*SIZE];


void update(ll id, ll l, ll r, ll i, ll x){
    if (l > i || r < i)
        return;

    if (l == r) {
        st[id] += x;
        return;
    }
    ll mid = (l + r) >> 1;
    update(2*id, l, mid, i, x);
    update(2*id+1, mid + 1, r, i, x);
    st[id] = st[2*id] + st[2*id + 1];

    return;
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v)
        return st[id];

    ll mid = (l + r) >> 1;
    ll get1 = get(2 * id, l, mid, u, v);
    ll get2 = get(2 * id + 1, mid + 1, r, u, v);

    return get1 + get2; 
}

void solve()
{
    cin >> n >> q;

    for (ll i = 1; i <= n; i++){
        ll z; cin >> z;
        update(1, 1, n, i, z);
    }
    

    while (q--){
        ll f, p, x; cin >> f >> p >> x;
        if (f == 0){
            update(1, 1, n, p+1, x);
        }
        else{
            cout << get(1,1,n, p+1, x) << ln;
        }
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
