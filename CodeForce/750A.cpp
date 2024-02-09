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

//My first fucking solved-CP problem in 2024  

ll n,k;
void solve(){
    cin >> n >> k;
    ll end = 4*60 - k;
    // cout << end << ln;
    ll cur = 0,res =0,i=1;
    while (cur + 5*i<= end && i <=n){
        cur+=i*5;
        // cout << cur << ln;
        i++;
        res++;
    }
    cout << res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}