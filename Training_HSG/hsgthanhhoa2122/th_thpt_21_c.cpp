#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 1e5+5;
ll n,k,a[LimN];
vector<ll> v;
void solve(){
    cin >> n >> k;
    for (ll i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    ll res = 0;
    for (ll i = n;i>=1;i--){
        ll z = v.size();
        bool flag = true;
        for (ll j =0;j<z;j++){
            if (v[j] - a[i]>=k){
                flag = false;
                v[j]=a[i];
                break;
            }
        }
        if (flag == true){
            v.push_back(a[i]);
            res+=a[i];
        }
    }
    cout << res;
}
int main()
{
    // freopen("BAI3.INP", "r",stdin );
    // freopen("BAI3.OUT", "w",stdout);
    fast_cin();
    solve();
    return 0;
}