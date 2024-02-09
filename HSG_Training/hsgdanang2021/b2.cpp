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
ll a,b;
ll uocso(ll x){
    ll res =0;
    for (ll i=1;i*i<=x;i++){
        if (x%i==0){
            res+=i;
            if (i != x/i){
                res+=x/i;
            }
        }
    }
    return res;
}
ll ucln(ll a, ll b){
    if (a==0){
        return b;
    }
    return ucln(b%a,a);
}
void solve(){
    cin >> a >> b;
    ll sum_a =0, sum_b=0;
    sum_a = uocso(a), sum_b = uocso(b);
    if (b * sum_a != a * sum_b){
        cout << -1;
        return;
    }   

    ll k = ucln(sum_a,a);
    ll k1 = ucln(sum_b,b);
    if (k > k1) swap(k,k1);
    cout << sum_a/k << ln;
    cout << a/k;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}