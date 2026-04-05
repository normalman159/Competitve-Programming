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

ll n; string s;
ll f[35];
ll ans = 0;
vector<string> v;

void backtrack(ll id, ll c){
    if (id < 0){
        return;
    }
    if (f[id] == c){
        backtrack(id-1,c);
    }
    else {
        backtrack(id-1,3-f[id] - c);
        ans++;
        string tmp;
        tmp += (char)(f[id] + 'A');
        tmp += (char)(c + 'A');
        v.pb(tmp);
        f[id] = c;
        backtrack(id-1,c);
    }
}

void solve(){
    cin >> n;
    cin >> s;
    ll id  = 0;
    for (auto x : s){
        f[id++] = x - 'A';
    }
    backtrack(n-1,2);
    cout << ans << ln;
    for (auto x : v){
        cout << x << ln;
    }
}

int main()
{
    fast_cin();
    solve();
    return 0;
}
