#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll n,x,m;
const ll LimN = 1e6+5;

ll powmod(ll a, ll b, ll m){
    ll res = 1;
    while (b){
        if (b%2) res = (res*a)%m;
        a= (a*a)%m;
        b/=2;
    }
    return res;
}

ll modInverse(ll A, ll M)
{
    ll g = __gcd(A, M);
    if (g==1){
        return powmod(A, M-2,M)%M;
    }
    return 0;
}

void solve(){
    cin >> n >> x >> m;
    ll x0 = (2*x+1)%m;
    ll a = 2, b = 1;
    ll z = powmod(a,n-1,m)%m;
    // cout << (x0%m * powmod(a,n,m) + powmod(a,n-1,m) + (m-1))%m;
    cout << ((x0%m * z%m)%m + ((z-1)%m * modInverse(a-1,m)%m * b %m)%m)%m;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}