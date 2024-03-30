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
 
void solve(){
    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        vector<ll> a,b;
        for (ll i=1;i<=n;i++){
            ll x; cin >> x;
            a.pb(x);
        }
        for (ll i=1;i<=n;i++){
            ll x; cin >> x;
            b.pb(x);
        }
        sort(ALL(a));
        sort(ALL(b));
        bool fg = false;
        forsn(i,0,n-1){
            if (!(a[i]<=b[i])){
                cout << "No";
                fg = true;
                break;
            }
        }
        if (fg == false) cout << "Yes";
        cout << ln;
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}