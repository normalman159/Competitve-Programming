#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll l,r;
const ll Lim =1e6+5;
ll p[Lim];

bool checknt(ll x){
    for (ll i=2;i*i<=x;i++){
        if (x%i==0) return 0;
    }
    return 1;
}

void solve(){
    cin >> l >> r;
    ll res =0;
    for (ll i=3;i<=100;i++){
        p[i] = checknt(i);
        p[i] +=p[i-1];
    }
    for (ll i=2;i*i<=r;i++){
        if (checknt(i)==0) continue;
        ll cntl = 1, cntr = 1;
        ll l1 = i, r1 = i;
        while (l1 < l){
            l1 *=i;
            cntl++;
        }
        while (r1 <= r){
            r1 *=i;
            cntr++;
        }
        res+=p[cntr] - p[cntl];
    }
    cout << res;
}
int main()
{
    // freopen("BAI4.INP","r",stdin);
    // freopen("BAI4.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}