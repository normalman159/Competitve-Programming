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
const ll LimN = 5*1e3 + 5;
ll n, a[LimN];

void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    ll res = 0;
    for (ll i=1;i<=n-2;i++){
        for (ll j = i+1,k = i+2;k<=n;k++){
            while (j < k && a[j] + a[i] <= a[k]) j++;
            res += k - j;
        }
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}