#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const ll Lim = 1e6+5;
ll n;

bool checknt(ll x) {
    for (ll i=2;i*i<=x;i++){
        if (x%i==0) return false;
    }
    return true;
}

void solve(){
    cin >> n;
    ll k = sqrt(n);
    bool ch = checknt(k);
    if (ch == true){
        cout << n*n;
        return;
    }
    k++;
    while (true)
    {
        if (checknt(k)){
            break;
        }
        k++;
    }
    cout << k*k;    
}
int main()
{
    fast_cin();
    solve();
    return 0;
}