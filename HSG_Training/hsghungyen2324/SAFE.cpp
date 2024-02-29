#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MOD = 1e9+7;
#define ln "\n"
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
string s;
const ll Lim = 3e5+5;
ll so[Lim], inhoa[Lim],inthuong[Lim],n;
void solve(){
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for (ll i=1;i<=n;i++){
        char t = s[i];
        so[i] = so[i-1];
        inhoa[i] = inhoa[i-1];
        inthuong[i] = inthuong[i-1];
        if (t >='A' && t<='Z'){
            inhoa[i]++;
        }
        if (t >='a' && t<='z') inthuong[i]++;
        if (t>='0' && t<='9') so[i]++;
    }
    // for (ll i=1;i<=n;i++){
    //     cout << i << " " << so[i] << " " << inhoa[i] << " " << inthuong[i] << ln;
    // }
    ll res= 0;
    for (ll R=1;R<=n;R++){
        ll z1 = upper_bound(so,so+1+R,so[R] -1) - so;
        ll z2 = upper_bound(inhoa,inhoa+1+R,inhoa[R] - 1) - inhoa;
        ll z3 = upper_bound(inthuong, inthuong+1+R,inthuong[R]-1) - inthuong;
        // z1--;z2--;z3--;
        // cout << z1 << " " << z2 << " " << z3 <<" "  << R << ln;
        ll z = min({z1,z2,z3});
        ll L = min(R-5,z);
        if (L <=0) continue;
        if (R-L +1>=6){
            res+=L-1+1;
            // cout << L << " " << R << " " << res << ln; 
        }
        
    }
    cout<< res;
}
int main()
{
    fast_cin();
    solve();
    return 0;
}