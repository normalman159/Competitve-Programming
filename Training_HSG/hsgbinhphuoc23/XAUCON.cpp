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
    ll n = s.size();
    ll res = -INF,curr=0;
    for (ll i=0;i<n;i++){
        if (s[i] == '0'){
            curr++;
        }
        else{
            res = max(res, curr);
            curr = 0;
        }
    }
    if (curr >0){
        res = max(res,curr);
    }
    cout << max(res,0LL);
}
int main()
{
    // freopen("XAUCON.INP","r",stdin);
    // freopen("XAUCON.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}