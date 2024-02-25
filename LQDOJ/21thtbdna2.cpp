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
ll n;

ll sum(ll x){
    ll res = 1;
    for (ll i=2;i*i<=x;i++){
        if (x%i==0){
            ll cnt =0;
            cnt++;
            x/=i;
            while (x%i==0){
                cnt++;
                x/=i;
            }
            ll sum = 0, pow = 1;
            while (cnt >= 0){
                sum+= pow;
                pow*=i;
                cnt--;
            }
            res *= sum;
        }
        
    }
    if (x > 1){
        res*=(x+1);
    }
    return res;
}

void solve(){
    cin >> n;
    ll res = -INF;
    ll ans=INF;
    for (ll i=1;i<=n;i++){
        ll k = sum(i);
        if (res < k){
            ans = i;
            res = k;
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