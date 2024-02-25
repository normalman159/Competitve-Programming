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
const ll LimN = 1e5+5;
ll n,a[LimN];
ll ucln(ll a,ll b){
    if (a==0){
        return b;
    }
    return ucln(b%a,a);
}
void solve(){
    cin >> n;
    for (ll i=1;i<=n;i++){
        cin >> a[i];
    }
    ll res = INF;
    for (ll i=1;i<n;i++){
        res = min(res, ucln(a[i],a[i+1]));
    }
    if (res == 1) cout << -1;
    else{
        for (ll i=2;i<=res;i++){
            if (res%i==0){
                cout << i;
                return;
            }
        }
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}