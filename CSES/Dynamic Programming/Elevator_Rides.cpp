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

ll n,k,a[MXN];
pair<ll,ll> dp[MXN]; //{numsOfPeople, totalWeightOfLastRide}
void solve(){
    cin >> n >> k;
    for (ll i=0;i<n;i++){
        cin >> a[i];
    } 
    dp[0] = {1,0};
    for (ll t = 1;t < (1<<n);t++){
        dp[t] = {INT_MAX, INT_MAX};
        for (ll i=0;i<n;i++){
            if (((1<<i) & t) == 0) continue;
            auto res = dp[(1<<i) ^ t];
            if (res.se + a[i] > k){
                res.fi++;
                res.se = a[i];
            }
            else res.se+=a[i];
            dp[t] = min(res,dp[t]);            
        }
    }
    cout << dp[(1<<n)-1].first;
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}