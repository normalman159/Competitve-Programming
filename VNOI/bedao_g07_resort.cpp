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

bool ch(ll x){
    if (x <= 1) return false;
    for (ll i = 2; i*i <= x;i++){
        if (x % i == 0) return false; 
    }
    return true;
}

void solve(){ 
    ll n; cin >> n;
    vector<ll> b(n);
    ll x, cnt_1 = 0, cnt_2 = 0;
    while (cin >> x){
        if (x == 1) cnt_1++;
        if (x==2) cnt_2++;
    }
    if (cnt_2 >= 1){
        b[0] = 2;
        cnt_2--;
    }
    else {
        b[0] = 1;
        cnt_1--;
    }
    ll curr = b[0], ans = 0;
    for (ll i=0; i < n; i++){
        if (ch(curr)) ans++;
        if (cnt_1 == 0){
            b[i] = 2;
            cnt_2--;
        }
        else if (cnt_2 == 0){
            b[i] = 1; cnt_1--;
        }
        else if (curr & 1){
            b[i] = 2;
            cnt_2--;
        }
        else {
            b[i] =1;
            cnt_1--;
        }
        curr += b[i];
    }
    cout << ans;
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
