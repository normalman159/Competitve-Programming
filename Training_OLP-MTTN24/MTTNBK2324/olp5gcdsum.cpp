#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 998244353;
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
 
//Modulo Calculation
ll add(ll x, ll y){
    return (x + y) % MOD;
}

ll sub(ll x, ll y){
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y){
    return (x%MOD * y%MOD) % MOD;
}
 
long long power_mod(long long a, long long b, long long M) // Tính a^b % M.
{
      if (b == 0)
           return 1;
      if (b == 1)
           return a;

      long long half = power_mod(a, b / 2, M) % M;

      if (b % 2 == 0)
           return (half * half) % M;
      else 
           return (((half * half) % M) * a) % M;
}

long long modulo_inverse(int a, int M)
{
      return power_mod(a, M - 2, M);
}

long long modulo_divide(long long a, long long b, long long c)
{
      long long inverse = modulo_inverse(b, c);
      return (a % c * inverse) % c;
}


void solve(){
    ll a,b; cin >> a >> b;
    if (a<b) swap(a,b);
    ll res = 0;
    while (b){
        ll k = (a-b)/b;
        res = add(res,mul(a,(k+1)%MOD));
        ll z = mul(b%MOD, modulo_divide(mul(k%MOD, (k+1)%MOD), 2,MOD));
        res = add(res, -z);
        a-= (k+1)*b;
        swap(a,b);
    }
    cout << res;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}