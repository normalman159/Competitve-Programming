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
 
double powMod(ll a, ll b){
    ll res = 1;
    while (b){
        if (b%2) res = (res*a);
        a= (a*a);
        b/=2;
    }
    return res;
}

ll modulo_inverse(int a, int M)
{
      return powMod(a, M - 2);
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
    ll n,q; cin >> n >> q;
    vector<ll> v(n+1);
    vector<double> prefix_v(n+1), prefix_log_v(n+1);
    forsn(i,1,n) cin >> v[i];
    prefix_v[0] = 1.0;
    forsn(i,1,n){
        prefix_log_v[i] = log2(v[i]);
        prefix_v[i] = prefix_v[i-1] + prefix_log_v[i];
    }
    while (q--){
        ll L, R; cin >> L >> R; 
        ll left = L, right = R;
        double res = prefix_v[R] - prefix_v[L-1];
        while (left <= right){
            ll mid = (left + right) / 2;
            double a = prefix_v[mid] - prefix_v[L-1], b = prefix_v[R] - prefix_v[mid];
            if (a < b){
                res = min(res, b-a);
                left = mid+1;
            }
            else{
                res = min(res, a-b);
                right = mid-1;
            } 
        }
        cout << fixed << setprecision(12) << pow(2,res ) << ln;
    }
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