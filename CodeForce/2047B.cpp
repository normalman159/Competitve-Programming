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
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> ocurr(26,0);
    for (auto x : s) ocurr[x - 'a']++;
    tuple<ll,char,ll> low,high;
    low = high = {ocurr[s[0] - 'a'], s[0], 0};
    for (ll i = 1; i<n;i++){
        low = min(low , {ocurr[s[i] - 'a'], s[i], i});
        high = max(high, {ocurr[s[i] - 'a'], s[i], i });
    }
    s[get<2>(low)] = get<1>(high);
    cout << s << ln;        
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
