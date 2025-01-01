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

void work(){
    ll n,m, L; cin >> n >> m >> L;
    vector<pair<ll,ll>> hurdles(n),powers(m);
    priority_queue<ll> prq;
    for (auto &hurd : hurdles) cin >> hurd.first >> hurd.second;
    for (auto &power : powers) {
        cin >> power.first >> power.second;
    }
    ll ans = 0, j = 0, init_power = 1;
    for (ll i=0; i<n;i++){
        ll need = hurdles[i].se - hurdles[i].fi + 1 +1;
        while (j < m && powers[j].fi < hurdles[i].fi) {
            prq.push(powers[j].se);
            j++;
        }
        while (!prq.empty() && init_power < need){
            init_power += prq.top();
            prq.pop();
            ans++;
        }
        if (init_power < need){
            cout << "-1" << ln;
            return;
        }
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
