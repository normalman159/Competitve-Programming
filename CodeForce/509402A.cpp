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

void solve(){
    ll n; cin >> n;
    vector<ll> v(n+1);
    forsn(i,1,n) cin >> v[i];
    if (n==1){
        cout << "YES" << ln; return;
    }
    if (v[1]  < v[n]){
        cout << "NO" << ln; return;
    }
    ll sum =0;
    forsn(i,1,n) sum+=v[i];
    // DEBUG(sum);
    ll z = sum/n;
    // DEBUG(z);
    if (sum != z*n){
        cout << "NO" << ln; return;
    }
    if (v[n] <= z && z <= v[1]) {
        ll k = 0;
        forsn(i,1,n){
            if (k  + v[i] - z < 0){
                cout << "NO" << ln; return;
            }
            k += v[i] - z;
        }
        cout << "YES" << ln; return;
    }
    cout << "NO" << ln;
}
 
 
int main()
{
    fast_cin();
    ll t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}