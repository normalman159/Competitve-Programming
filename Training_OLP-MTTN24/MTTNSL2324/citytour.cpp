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
const ll LimN = 4e5 +5;
ll n,k;
ll v[LimN];

void sub1(){
    vector<ll> f(n+5, 0);
    f[1] = v[1];
    for (ll i=1;i<=n;i++){
        for (ll j = 1;j<=i-1;j++){
            if (j - i == v[j] - v[i]){
                f[i] = max(f[i], f[j] + v[i]);
            }
        }
    }
    cout << f[n];
}

void sub2(){
    vector<ll> f(n+5,0);
    f[1] = v[1];
    ll res = f[1];
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<=i-1;j++){
            if (j - i == v[j] - v[i]){
                f[i] = max(f[i], f[j] + v[i]);
                res = max(res,f[i]);
            }
            else if (k==1){
                k--;
                f[i] = max(f[i],res+v[i]);
            }
        }
    }
    cout << f[n];
}

void sub3(){
    vector<ll> f(n+5,0);
    f[1] = v[1];
    ll res = f[1];
    for (ll i=1;i<=n;i++){
        for (ll j= 1; j<=i-1;j++){
            if (j - i == v[j] - v[i]){
                f[i] = max(f[i], f[j] + v[i]);
                res = max(res,f[i]);
            }
            else if (k!=0){
                k--;
                f[i] = max(f[i],res+v[i]);
            }
        }
    }
    cout << f[n];
}

void solve(){
    cin >> n >>k;
    forsn(i,1,n){
        cin >> v[i];
    }
    if (n<=1e3 && k ==0){
        sub1();
    }
    else if (n<=1e3 && k==1){
        sub2();
    }
    else if (n<=1e3){
        sub3();
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}