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

struct car{
    ll a,b,id; double pr;
};

bool cmp(car a, car b){
    return a.pr > b.pr;
}

void solve(){
    ll n; cin >> n;
    vector<car> a(n);
    for (ll i=0; i < n;i++){
        cin >> a[i].a;
        a[i].id = i+1;
    }
    for (ll i=0 ; i < n; i++){
        cin >> a[i].b;
        a[i].pr = (double)a[i].a/a[i].b;
    }
    sort(ALL(a), cmp);
    ll ans1= 0, cnt= 0;
    for (ll i=0; i < n; i++){
        cnt += a[i].b;
        ans1 += cnt * a[i].a;       
    }
    cout << ans1 << ln;
    for (auto x : a){
        cout << x.id << " ";
    }
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
