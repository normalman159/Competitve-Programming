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
ll t;
void solve(){
    cin >> t;
    while (t--)
    {
        /* code */
        ll n; cin >> n;
        string s; cin >> s;
        s = "0" + s + "0";
        ll a[n+5];
        for (ll i=1;i<=n;i++) cin >> a[i];
        a[n+1] = a[0] = 0;
        ll ans = 0, curr_im=0,pos = 0;
        vector<ll> impr;
        for (ll i=0;i<=n+1;i++){
            if (s[i] == '0'){
                pos = i;
                impr.pb(curr_im);
                curr_im = 0;
            }
            else {
                ans+=a[i];
                curr_im = max(curr_im, a[pos] - a[i]);
            }
        }
        for (auto x : impr){
            ans+=x;
        }
        cout << ans << ln;
    }
    
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}