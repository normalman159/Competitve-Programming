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
const ll LimN = 1e5+5;
ll n,m,a[LimN];

struct Node
{
    ll val, id;
}; Node t[LimN];

bool compare(Node a,Node b){
    return a.val < b.val;
}

void solve(){
    cin >> n >> m;
    for (ll i=1;i<=n;i++){
        cin >> t[i].val;
        t[i].id = i;
    }
    sort(t+1,t+1+n,compare);
    while (m--){
        ll i,j,k; cin >> i >> j >> k;
        for (ll u = 1; u<=n;u++){
            if (i <= t[u].id && t[u].id<=j){
                k--;
            }
            if (k==0){
                cout << t[u].val << ln;
                break;
            }
        }
    }
}
int main()
{
    freopen("KTHNUM.INP","r",stdin);
    freopen("KTHNUM.OUT","w",stdout);
    fast_cin();
    solve();
    return 0;
}