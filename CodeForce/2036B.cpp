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
const ll LimN = 2e5 + 5;
ll st[LimN];
void work(){
    for (ll i=0;i<LimN;i++) st[i] = 0;
    ll n,k; cin >> n >> k;
    for (ll i=1;i<=k;i++){
        ll x,y; cin >> x >> y;
        st[x]+=y;
    }
    sort(st,st+k+1);
    ll ans=0;
    for (ll i=0;i<n;i++){
        if (k-i < 0) break;
        ans+=st[k-i];
    }
    cout << ans << ln;
}

void solve(){
    ll t; cin >> t;
    while(t--){
        work();
    }
}   
    
int main()
{
    fast_cin();
    solve();
    return 0;
}
