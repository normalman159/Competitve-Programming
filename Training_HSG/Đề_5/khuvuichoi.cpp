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

ll st,ed;
void solve(){
    cin >> st >> ed;
    ll cnt = 0;
    if (ed<=12){
        if (ed- st >4) cnt = 4*6 + (ed-st)*6/2;
        else cnt = 6*(ed-st);
    }
    else if (st >=12){
        if (ed-st>4) cnt = 4*10 + (ed-st)*10/2;
        else cnt = 10 * (ed-st);
    }
    else{
        if (ed-st <=4) cnt = 6*(12-st) + 10*(ed-12);
        else{
            if (12 - st >4){
                cnt = 4*6 + (12-(st+4))*6/2 + (ed-12)*10/2;
            }
            else if (ed - 12 > 4){
                cnt = 6*(12-st) + (ed-12)*10/2;
            }
            else{
                ll x = 12 - st;
                cnt = 6*x + 10*(4-x) + (ed - (16-x))*10/2;
            }
        }
    }
    cout << cnt;
}
int main()
{
    fast_cin();
    solve();
    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}