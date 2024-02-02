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

ll t,a[103],b[103];
void solve(){
    cin >> t;
    while (t--){
        ll n,m; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        cin >> m;
        for (int j=1;j<=m;j++) cin >> b[j];
        ll maxA = a[1], maxB = b[1];
        for (ll i=1;i<=n;i++){
            ll temp = a[i];
            if (i==1) continue;
            a[i] = temp + a[i-1];
            maxA = max(maxA,a[i]);
        }
        for (ll j = 1;j<=m;j++){
            ll temp = b[j];
            if (j==1) continue;
            b[j] = temp + b[j-1];
            maxB = max(maxB, b[j]);
        }
        cout << max(0LL, maxA) + + max(0LL, maxB) << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}