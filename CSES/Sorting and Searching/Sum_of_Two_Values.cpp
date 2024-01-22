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
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll n, x;
vector<pair<ll,ll>> a;
void solve(){
    
    cin >> n >> x;
    
    for (ll i=1;i<=n;i++){
        ll tmp; cin >> tmp;
        a.push_back({tmp,i});
    }
    sort(a.begin(), a.end());
    ll l = 0, r = n-1;
    while(l < r){
        if (a[l].fi + a[r].fi == x){
            cout << a[l].se << " " << a[r].se << ln;
            return;
        }
        if (a[l].fi + a[r].fi > x){
            r--;
        }
        else{
            l++;
        }
        
    }
    cout << "IMPOSSIBLE";
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}