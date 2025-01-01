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
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((ll)(x).size())

//Modulo Calculation
ll add(ll x, ll y)
{
    return (x + y) % MOD;
}

ll sub(ll x, ll y)
{
    return ((x - y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return (long long)x * y % MOD;
}

void solve()
{
    ll x,y; cin >> x >> y;
    if (x==y) {cout << 0; return;}
    ll a =x, b= x, c = x;
    auto valid = [](ll a,ll b, ll c){
        return (a + b > c) && (a + c > b) && (b + c > a);
    };
    ll res = 0;
    while (a > y || b > y || c > y){
        if (a == max({a,b,c}) && a > y) {
            // Cắt cạnh a xuống vừa đủ để tam giác còn hợp lệ
            if (c-b+1 >0 && b-c+1 >0 && a - 1>0) a = min({a - 1,  c - b +1, b-c+1});  // Cắt sao cho a + b > c và a + c > b
            else if (c-b+1 >0 && b-c+1 < 0) a = min(a-1,c-b+1);
            else if (c-b+1 < 0 && b-c+1 >0) a = min(a-1,b-c+1);
            else a--;
            if (!(a > 0) || a < y) {
                if (valid(y,b,c)) a = y;
            }
        }
        else if (b == max({a,b,c})&& b > y) {
            if (a - c + 1 > 0 && c - a + 1 >0 && b-1>0) b = min({b -1, c - a +1, a - c+1});  // Cắt sao cho b + a > c và b + c > a
            else if (a - c  +1 < 0 && c -a + 1 >0) b = min(b-1,c-a+1);
            else if (a -c + 1 >0 && c -a+1 < 0) b = min(b-1,a-c+1);
            else b--;
            if (!(b > 0) || b < y){
                if (valid(a,y,c)) b =y;
            }
        }
        else if (c == max({a,b,c}) && c > y) {
            if (a-b+1 >0 && b-a+1>0 && c-1 > 0)    c = min({c - 1, a-b + 1, b-a+1});  // Cắt sao cho c + a > b và c + b > a
            else if (a-b+1 >0 && b-a+1<0) c = min(c-1,a-b+1);
            else if (a-b+1 <0 && b-a+1>0) c= min(c-1,b-a+1);
            else c--;
            if (!(c >0) || c < y) {
                if (valid(a,b,y)) c = y;
            }
        }
        res++;
//        DEBUG(a),DEBUG(b), DEBUG(c);
//        if (valid(a,b,c)== 0) {res = -1; break;}
    }
    cout << res;
}

int main()
{
    fast_cin();
    solve();
    return 0;
}

