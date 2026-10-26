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
    ll a,b;
};

ll n, q;
Node a[SIZE];
Node st[4*SIZE];

Node merge(Node l, Node r){
    Node ans;
    ans.a = (l.a * r.a) % MOD;
    ans.b = (r.a * l.b + r.b) % MOD;
    return ans;
}

void build(ll id, ll l, ll r){
    if (l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(2*id, l, mid);
    build(2*id+1, mid + 1, r);

    st[id] = merge(st[2*id], st[2*id + 1]);
}

void update(ll id, ll l, ll r, ll p, ll c, ll d){
    if (p > r || p < l) return;
    if (l == r) {
        st[id] = {c , d};
        return;
    }
    ll mid = (l + r) >> 1;
    update(2 * id, l, mid, p, c ,d);
    update(2 * id + 1, mid + 1, r, p, c ,d);
    
    st[id] = merge(st[2*id], st[2*id + 1]);
} 

Node get(ll id, ll l, ll r, ll u, ll v){
    if (l > v || r < u)
        return {1, 0};

    if (l >= u && r <= v)
        return st[id];

    ll mid = (l + r) >> 1;
    Node get1 = get(2 * id, l, mid, u, v);
    Node get2 = get(2 * id + 1, mid + 1, r, u, v);

    return merge(get1, get2); 
}

void solve()
{
    cin >> n >> q;

    for (ll i = 1; i <= n; i++){
        cin >> a[i].a >> a[i].b;
    }
    build(1, 1, n);

    while (q--){
        ll f, p, l, r; cin >> f >> p >> l >> r;
        if (f == 0){
            update(1, 1, n, p + 1,l , r);
        }
        else{
            Node ans = get(1,1,n, p+1, l);
            cout << (ans.a * r + ans.b) % MOD << ln;
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
