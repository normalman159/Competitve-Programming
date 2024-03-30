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

const ll LimN = 2e7+1;

void solve(){
    ll t; cin >> t;
    vector<bool> prime(LimN, true), ch(LimN, false);
    vector<ll> p;
    prime[0] = prime[1] = false;
    for(ll i = 2;i*i<= LimN;i++){
        if (prime[i]){
            for (ll j = i*i;j<=LimN;j+=i) prime[j] = false;
        }
    }
    forsn(i,2,LimN){
        if (prime[i]==true) p.push_back(i);
    }
    for(ll i= 1;i< p.size()-1;i++){
        if (2*p[i] == p[i+1] + p[i-1]) ch[p[i]] = true;
    }
    while(t--){
        ll n; cin >> n;
        if (ch[n]) cout << "YES" <<ln;
        else cout << "NO" << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}