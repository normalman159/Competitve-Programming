#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll n;
bool checkcb(ll x){
    string s = to_string(x);
    ll k = s.size();
    s = ' ' +s;
    ll sum = 0,sum1 = 0;
    for (ll i=1;i<=k/2;i++){
        sum+=s[i] - '0';
    }
    if (k%2!=0){
        for (ll i = k/2 + 2; i<=k;i++){
            sum1+=s[i] - '0';
        }
    }
    else{
        for (ll i = k/2 + 1; i<=k;i++){
            sum1+=s[i] - '0';
        }
    }
    return (sum == sum1);
}
void solve(){
    cin >> n;
    ll k = n+1;
    while (checkcb(k)!=1){
        k++;
    }
    cout << k << ln;
    // if (checkcb(12403)) cout << 1 << ln;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}