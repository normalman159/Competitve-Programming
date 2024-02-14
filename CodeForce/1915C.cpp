#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll t;
void solve(){
    cin >> t;
    while (t--){
        ll n; cin >> n;
        ll sum =0;
        for (ll i=1;i<=n;i++){
            ll x; cin >>x;
            sum+=x;
        }
        ll k = sqrt(sum);
        if (k*k == sum){
            cout << "YES" <<ln;
        }
        else cout << "NO" <<ln;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}