#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 1; i <= e; i++)
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforn(i,s) for(ll i = s; i >= 1; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())
ll m,n;

void solve(){
    cin >> m >> n;
    vector<vector<ll>> v(m+5,vector<ll>(n+5));
    for (ll i=1;i<=m;i++){
        for (ll j = 1;j<=n;j++){
            cin >> v[i][j];
        }
    }
    ll q; cin >> q;
    while (q--){
        string s; cin >> s;
        ll z = s.size();
        s = ' ' + s;
        string tmp,tmp1,tmp2 ;
        //sub1
        if (z == 10){
            for (ll i=1;i<=z;i++){
                if (i <=3){
                    tmp +=s[i];
                }    
                if (5 <=i && i<=6){
                    tmp1+=s[i];
                }
                if (8 <= i && i<=9){
                    tmp2+=s[i];
                }
            }
            if (tmp == "SUM"){
                cout << v[tmp1[1] - '0'][tmp1[0] - 'A' + 1] + v[tmp2[1] - '0'][tmp2[0] - 'A' + 1];
            }
            else{
                cout << max(v[tmp1[1] - '0'][tmp1[0] - 'A' + 1], v[tmp2[1] - '0'][tmp2[0] - 'A' + 1]);
            }
            cout << ln;
        }
        //sub2
    }
}
 
 
int main()
{
    fast_cin();
    solve();
    return 0;
}