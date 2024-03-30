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
    ll n,k; cin >> n >> k;
    map<ll,ll> m;
    forsn(i,1,n){
        ll x; cin >> x;
        m[x]++;
    }
    vector<ll> b(k+1);
    forsn(i,1,k) cin >> b[i];
    auto check = [&](ll x){
        string s = to_string(x);
        for(auto z : s){
            if (!(z=='6' || z=='8')) return false;
        }
        return true;
    };
    forsn(i,1,k){
        ll z = m[b[i]];
        if (check(z) == true) {
            cout << b[i] <<" " <<  m[b[i]] << ln;
        }
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}