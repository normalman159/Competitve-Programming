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
string s;
void solve(){
    cin >> s;
    ll res = 0;
    ll n = s.size();
    s = ' ' +s;
    for (ll i=1;i<=n;i++){
        for (ll j = i;j<=n;j++){
            if (s[j] != s[i]){
                res = max(res, j-i);
                break;
            }
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