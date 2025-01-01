//Link: https://oj.vnoi.info/problem/nkrez

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

const ll LimN = 3e4;

ll n, arr[30005];
vector<ll> f[30005];
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        ll x,y; cin >> x >> y;
        f[y].push_back(x);
    }
    for (ll i=1;i<=LimN;i++){
        arr[i] = arr[i-1];
        for (ll j = 0; j<f[i].size(); j++){
            arr[i] = max(arr[i], i - f[i][j] + arr[f[i][j]]);
        }
    }
    cout << arr[LimN];
}


int main()
{
    fast_cin();
    solve();
    return 0;
}
