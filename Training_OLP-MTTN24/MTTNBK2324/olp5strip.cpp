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

const ll LimN = 5e5+5;
pair<ll,ll> point[LimN];
ll f[LimN];

void solve(){
    ll n,k; cin >> n >> k;
    vector<ll> prefix(n+5,0);
    forsn(i,1,k){
        ll x,y; cin >> x >> y;
        prefix[x]++; prefix[y+1]--;
    }
    vector<ll> left(n+5,0), right(n+5,0);
    ll pos = 1, cnt = 0;
    forsn(i,1,n){
        prefix[i] += prefix[i-1];
        if (prefix[i]==0) pos=i+1;
        else if (pos == i) {
            cnt++;
            left[cnt] = right[cnt] = i;
        } 
        else right[cnt] = i;
    }

    f[1] = 1;
    forsn(i,2,n){
        f[i] = f[i-1];
        forsn(j,1,cnt){
            if (i - left[j]>=0) f[i] = add(f[i], f[i-left[j]]);
            if (i - right[j]-1>=0) f[i] = sub(f[i], f[i - right[j]-1]);
        }
    }
    cout << sub(f[n], f[n-1]);
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}