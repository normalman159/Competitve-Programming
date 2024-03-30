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
    vector<ll> cnt_nt;
    vector<bool> nt(1e6+5, true);
    nt[0] = nt[1] = false;
    for(ll i=2;i*i<=1e6;i++){
        if (nt[i]){
            cnt_nt.pb(i);
            for(ll j = i*i;j<=1e6;j+=i){
                nt[j] = false;
            }
        }
    }
    for(ll i =1;i<=n;i++){
        ll x; cin >> x;
        ll l = 0, r = cnt_nt.size()-1, res = -1;
        while (l<=r){
            ll mid = (l+r)/2;
            if (cnt_nt[mid] <= x){
                res = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        cout << cnt_nt[res] << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}