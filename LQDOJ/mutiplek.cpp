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
ll n,a[LimN],k;
bool flag;

pair<ll,bool> cnt(ll x){
    ll res = 0;
    flag = false;
    for (ll i=1;i<=n-1;i++){
        ll d = x/a[i];
        if (d <= a[i]) break;
        ll z = upper_bound(a+1+i,a+1+n,d) - a - 1;
        if (a[z] * a[i] == x){
            flag = true;
        }
        res+=z-i;
    }
    return {res,flag};
}

void solve(){
    cin >> n >> k;
    for (ll i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    ll res = INF;
    ll l =1, r = 10000000000;
    while (l <=r){
        ll mid = (l+r)/2;
        pair<ll,bool> z1 = cnt(mid-1);
        pair<ll,bool> z2 = cnt(mid);        
        if (z1.first < k && z2.first == k && z1.second && z2.second){
            cout << mid;
            return;
        }
        if (z2.first>=k){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}