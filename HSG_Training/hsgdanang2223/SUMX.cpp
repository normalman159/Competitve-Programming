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

const ll LimN = 1e5+5, MaxN = 2*1e5+5;
ll n,x,a[LimN], cnt[MaxN];
void solve(){
    cin >> n;
    for (ll i=0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    cin >> x;
    ll res = 0;
    //a[i] + a[j] = x
    //a[j] = x-a[i]
    for (ll i=0;i<n;i++){
        ll j = find(a + 1 + i, a + n, x-a[i]) - a;
        if (j !=n){
            if (a[i] == x - a[i]){
                res+=cnt[a[i]]-1;
            }
            else{
                res+=cnt[x-a[i]];
                cnt[a[i]]--;
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