#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (long long)x * y % MOD;
}

void solve(){
    ll n; cin >> n;
    vector<ll> v(n+1);
    ll keo = 0, cnt = 0;
    for (ll i = 1; i<=n;i++){
      cin >> v[i];
      if (v[i]%3==0 && v[i]!=0) keo += v[i], cnt++;
    }
    cout << cnt << ln;
    cout << (keo - cnt*3) / 3;
}


int main()
{
//    freopen("CANDIES.INP","r",stdin);
//    freopen("CANDIES.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}

