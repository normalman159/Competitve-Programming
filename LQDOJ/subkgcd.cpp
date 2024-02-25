#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll LimN = 3e5+5;
const ll LimK = 1e6+5;
ll n,a[LimN],k;

void solve(){
    cin >> n >> k;
    ll mi = INF;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
        if (a[i] <= k){
            a[i] = 0;
        }
        else mi = min(mi,a[i]);
    } 
    bool flag = false;
    ll ans = -INF;
    for (ll i = mi;i>=1;i--){
        // for (ll j = 1;j<=n;j++){
        //     flag = false;
        //     ll z = a[j] - k;
        //     for (ll tmp = a[j]; tmp>=z;tmp--){
        //         if (tmp % i==0){
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if (flag == false){
        //         break;
        //     }
        // }
        // if (flag == true){
        //     ans = max(ans,i);
        // }
        bool flag = true;
        for (ll j=1;j<=n;j++){
            ll f = a[j]/i;
            ll z = a[j] - f*i;
            if (z>k){
                flag = false;
                break;
            }
        }
        if (flag == true){
            ans = max(ans,i);
            break;
        }
    }
    cout << ans;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}