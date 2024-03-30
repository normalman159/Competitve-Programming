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
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
 
const ll LimN = 1e5+5;
pair<ll,ll> p[LimN];
ll n,s;
void solve(){
    cin >> n >> s;
    for (ll i=1;i<=n;i++){
        cin >> p[i].fi >> p[i].se;
    }
    sort(p+1,p+1+n);
    ll res = 0;
    ll curr_s = s;
    for (ll i=1;i<=n;i++){
        if (p[i].fi < curr_s){
            res++;
            curr_s +=p[i].se;
        }
        else{
            break;
        }
    }
    cout << res;
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}