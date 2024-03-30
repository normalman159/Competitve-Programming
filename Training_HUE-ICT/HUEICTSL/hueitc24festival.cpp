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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 
ll powMod(ll a, ll b, ll m){
    ll res = 1;
    while (b){
        if (b%2) res = (res*a)%m;
        a= (a*a)%m;
        b/=2;
    }
    return res;
}

ll modulo_inverse(int a, int M)
{
      return powMod(a, M - 2, M);
}

//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (ll)x * y % MOD;
}
 
ll div(ll a, ll b, ll c)
{
      ll inverse = modulo_inverse(b, c);
      return (a % c * inverse) % c;
}

const ll LimN = 2e3+5;
ll f[LimN][LimN];


void solve(){
    ll t;cin >> t;
    while (t--){
        ll n; cin >> n;
        vector<ll> p(n+3,0);
        forsn(i,1,n) cin >> p[i];
        ll k = n/2;
        for (ll i=0;i<=LimN-2;i++){
            for (ll j = 0;j<=LimN-2;j++) f[i][j] = -INF;
        }
        for (ll i=1;i<=n;i++){
            f[i][1] = max(f[i-1][1], p[i]);
        }
        
        f[0][0] = 0;
        for (ll i=2;i<=k;i++){
            for (ll j = 1;j<=n;j++){
                if (j - 1 >= 1 && j - 2 >=1){
                    f[j][i] = max(f[j-1][i], f[j-2][i-1] + p[j]);
                }
            }
        }
        ll res  = -INF;
        for (ll i=1;i<=n+1;i++){
            res = max(res,f[i][k]);
        }
        cout << res << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}