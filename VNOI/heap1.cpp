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
    return (x % MOD + y % MOD) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)(x % MOD) *  (y % MOD) % MOD;
}

void work(){
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x; 
    priority_queue<ll, vector<ll> , greater<ll>> q;
    for (auto x : a) q.push(x);
    ll ans = 0;
    while (q.size() >= 2){
        ll tmp1 = q.top(); q.pop();
        ll tmp2 = q.top(); q.pop();
        ans += tmp1 + tmp2;
        q.push(tmp1 + tmp2);
    }
    cout << ans << ln;
}

void solve(){
    ll t; cin >> t;
    while (t--){
        work();
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
