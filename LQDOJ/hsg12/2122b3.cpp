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

const ll LimN = 2*1e5+5;
ll n,a[LimN];
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll hi = 0;
    for (ll i=1;i<=n;i++){
        hi = max(hi,a[i]);
    }
    ll cnt[hi+5]={0};
    for (ll i=1;i<=n;i++){
        cnt[a[i]]++;
    }
    ll count = 0;
    for (ll i = hi;i>=1;i--){
        ll j = i;
        count = 0;
        while (j<=hi){
            if (cnt[j] >=2){
                cout << j;
                return;
            }
            else if (cnt[j] == 1){
                count++;
            }
            j+=i;
            if (count ==2){
                cout << i;
                return;
            }
        }
    }


    // ll cnt[hi+5] = {0};
    // for (ll i=1;i<=n;i++){
    //     for (ll j = 1;j*j<=a[i];j++){
    //         if (a[i]%j==0){
    //             cnt[j]++;
    //             if (j!=a[i]/j){
    //                 cnt[a[i]/j]++;
    //             }
    //         }
    //     }
    // }
    // for (ll i = hi;i>=1;i--){
    //     if (cnt[i] >=2){
    //         cout << i;
    //         return;
    //     }
    // }
}
int main()
{
    // freopen("DISCOUNT.INP","r",stdin);
    // freopen("DISCOUNT.OUT","w",stdout);
    fast_cin();
    solve();
    cerr << " Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}