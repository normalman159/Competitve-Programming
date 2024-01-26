#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
const ll MXN = 2e6 + 5;
const long long INF = 1e15;
const ll MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

ll t,a[MXN], b[MXN];
/* 
Có 2 loại cột: loại a và loại b 
                                                 __
Cột loại 'a' là cột có 2 phần thuộc về 1 block: |  |
                                         _ _
Cột loại 'b' là cột có 2 phần riêng lẻ: | | |

Luôn có a[1] = b[1] =1;
Xét đến cột có chiều cao n thì:
                               _ _    _ _    _ _ 
                   _ _        |   |  |_|_|  |_ _|
Loại a =>         |   |  =>   |   |, |   |, |   |

                           _  _    _  _    _  _    _  _     _ _
               _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
Loại b =>     | || | =>   | || |, | || |, | || |, | || |,  | | |

*/
void solve(){
    cin >> t;
    a[1] = 1;
    b[1] = 1;
    for (ll i=2;i<=1e6;i++){
        a[i] = 2*a[i-1]%MOD + b[i-1]%MOD;
        b[i] = 4*b[i-1]%MOD + a[i-1]%MOD;
        a[i]%=MOD;
        b[i]%=MOD;
    }
    while (t--){
        ll n; cin >> n;
        cout << (a[n] + b[n])%MOD << ln;
    }
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}