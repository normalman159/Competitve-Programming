#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 998244353;
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

struct Node{
    ll sum, lz_b, lz_c;
};

ll n, q;
ll a[SIZE];
Node st[4*SIZE];


void build(ll id, ll l, ll r){
    st[id].lz_b = 1;
    st[id].lz_c = 0;
    if (l == r) {
        st[id].sum = a[l] % MOD;
        return;
    }
    ll mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id+1, mid + 1, r);

    st[id].sum = (st[2*id].sum + st[2*id + 1].sum) % MOD;
}

void apply(ll id, ll len, ll b, ll c){
    st[id].sum = (st[id].sum * b + c * len) % MOD;
    st[id].lz_b = (st[id].lz_b * b) % MOD;
    st[id].lz_c = (st[id].lz_c * b + c) % MOD;
}

void fix(int id, int l, int r) {
    if (st[id].lz_b == 1 && st[id].lz_c == 0) return;
    
    ll mid = (l + r) >> 1;
    apply(id * 2, mid - l + 1, st[id].lz_b, st[id].lz_c);
    apply(2*id + 1, r - mid, st[id].lz_b, st[id].lz_c);

    st[id].lz_b = 1;
    st[id].lz_c = 0;
}

void update(ll id, ll l, ll r, ll u, ll v, ll b, ll c){
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        apply(id, r - l + 1, b, c);
        return;
    }
    fix(id, l ,r);
    ll mid = (l + r) >> 1;
    update(2 * id, l, mid, u, v, b, c);
    update(2 * id + 1, mid + 1, r, u, v, b, c);
    
    st[id].sum = (st[2 * id].sum + st[2*id + 1].sum) % MOD;
} 

ll get(ll id, ll l, ll r, ll u, ll v){
    if (l > v || r < u)
        return 0;

    if (l >= u && r <= v)
        return st[id].sum;
    fix(id, l , r);
    ll mid = (l + r) >> 1;
    ll get1 = get(2 * id, l, mid, u, v);
    ll get2 = get(2 * id + 1, mid + 1, r, u, v);

    return (get1 + get2) % MOD; 
}

void solve()
{
    cin >> n >> q;

    for (ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    while (q--){
        ll f, l, r; cin >> f >> l >> r;
        if (f == 0){
            ll b, c; cin >> b >> c;
            update(1, 1, n, l+1, r, b, c);
        }
        else{
            cout << get(1,1,n, l+1, r) << ln;
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
