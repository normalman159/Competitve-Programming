#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


//O(log(a)+log(b) + log(a1)+log(a2))
ll a,b;
ll tinhuoc(ll x){
    ll res = 0;
    for (ll i=1;i*i<=x;i++){
        if (x%i==0){
            res+=i;
            if (i!=x/i){
                res+=x/i;
            }
        }
    }
    return res;
}

ll ulcn(ll a, ll b){
    if (a==0){
        return b;
    }
    return ulcn(b%a,a);
}

void check(ll a, ll b){
    ll a1 = tinhuoc(a);
    ll b1 = tinhuoc(b);
    if ((a1 * b) == (b1*a)){
        ll k = ulcn(a1,a);
        ll k1=ulcn(b1,b);
        if (k > k1) swap(k,k1);
        cout << a1/k << ln;
        cout << a/k;
    }
    else cout << -1;
}

void solve(){
    cin >> a >> b;
    check(a,b);
}
int main()
{
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}