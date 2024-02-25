#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll n;
const ll Lim = 5e6+5;
vector<ll> cp;
bool checkcp[Lim];
ll tohop(ll k){
    return (k*(k-1)*(k-2))/6;
}

void solve(){
    cin >> n;
    memset(checkcp,false,sizeof(checkcp));
    for (ll i=1;i*i<=n;i++){
        cp.pb(i*i);
        checkcp[i*i] = true;
    }
    ll z = cp.size();
    ll res = tohop(z);
    for (ll i=1;i<=n;i++){
        if (checkcp[i]== true) continue;
        auto it = cp.begin();
        while (*it * i <=n){
            checkcp[*it*i]= true;
            ++it;
        }  
        ll z = it - cp.begin();
        res+=tohop(z);
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}