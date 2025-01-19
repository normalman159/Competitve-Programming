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

void solve(){
    string s; cin >> s;
    ll n = SZ(s);
    vector<ll> cnt(26);
    for (auto x : s){
        cnt[x- 'a']++;
    }
    ll i =0 , j = 25;
    while (i < j){
        while (i < j && cnt[i] % 2==0) i++;
        while (i < j && cnt[j] % 2 == 0) j--;
        cnt[i]++, cnt[j]--;
    }
    for (ll i = 0, id = 0; i <= n/2; i++){
        while (cnt[id] <= 0 && id < 25) id++;
        if (cnt[id] >= 2){
            s[i] = (char)('a' + id);
            s[n-i-1] = s[i];
            cnt[id]-=2;
        }
        if (cnt[id] == 1){
            s[n/2] = char('a' + id);
            cnt[id]--;
        }
    }
    cout << s;
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
