#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll a,b;

ll dem(ll x){
    ll res = 0;
    for (ll i=1;i*i<=x;i++){
        if (x%i==0){
            res++;
            if (i!=x/i) res++;
        }
    }
    return res;
}

void solve(){
    cin >> a >> b;
    ll k = __gcd(a,b);
    cout << dem(k);
}
int main()
{
    fast_cin();
    solve();
    return 0;
}