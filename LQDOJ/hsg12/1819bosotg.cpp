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
const ll LimN = 5*10e3 + 5;
ll n, a[LimN];
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    } 
    sort(a+1,a+1+n);
    ll ans1=0;
    //ans1 vuong
    //ans2 tu
    //ans3 nhon
    for (ll l=1;l<=n-2;l++){
        for (ll r=l+1,k=l+2;k<=n;k++){
            while (r<k && a[l] + a[r] <= a[k]) r++;
            ans1+=k-r;            
        }
    }
    cout << ans1;
}   
int main()
{
    // freopen("CAU5.INP","r",stdin);
    // freopen("CAU5.OUT", "w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}