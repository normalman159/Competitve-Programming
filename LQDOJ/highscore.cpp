#include <bits/stdc++.h>

using namespace std;

//typedef long long int64_t;
const long long INF = 1e15;
const int64_t MOD = 1e9+7;
const double eps = 1e-12;
#define forn(i,e) for(int64_t i = 1; i <= e; i++)
#define forsn(i,s,e) for(int64_t i = s; i <= e; i++)
#define rforn(i,s) for(int64_t i = s; i >= 1; i--)
#define rforsn(i,s,e) for(int64_t i = s; i >= e; i--)
#define ln "\n"
#define DEBUG(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int64_t)(x).size())

//Modulo Calculation
int64_t add(int64_t x, int64_t y){
    return (x + y) % MOD;
}

int64_t sub(int64_t x, int64_t y){
    return ((x - y) % MOD + MOD) % MOD;
}

int64_t mul(int64_t x, int64_t y){
    return (long long)x * y % MOD;
}

const int64_t LimN = 1e5 + 5;
pair<int64_t,int64_t> arr[LimN];
int64_t stor[LimN];
int64_t n,h;
int64_t MAX_FI = -INF;
int64_t SUM_SE =0, cnt=0, SUM_X = 0;

bool check_assistant(int64_t x) {
    vector<int64_t> self_destruct;
    self_destruct.clear();

    for (int64_t i = 1; i <= n; i++) {
        if (arr[i].second > arr[i].first) {
            self_destruct.push_back(arr[i].second);
        }
    }

    sort(self_destruct.rbegin(), self_destruct.rend());
    int64_t sum_damage = 0;
    int64_t num_self_destruct_used = 0;

    for (int64_t i = 0; i < min((int64_t)self_destruct.size(), x); i++) {
        sum_damage += self_destruct[i];
        num_self_destruct_used++;
    }

    if (num_self_destruct_used < x) {
        sum_damage += (x - num_self_destruct_used) * MAX_FI;
    }

    return sum_damage >= h;
}

void sub3(){
    int64_t left = 0, right = 1e15;

    for (int64_t i=1;i<=n;i++){
        MAX_FI = max(MAX_FI, arr[i].fi);
    }

    auto check  = [](int64_t x){
        int64_t tmp = h;
        int64_t SUM_SE =0, cnt=0;
        if (tmp <= x*MAX_FI) return true;
        for (int64_t i=1;i<=n;i++){
            if (arr[i].se > MAX_FI){
                cnt++, SUM_SE+=arr[i].se;
            }
        }
        if (tmp - (x-cnt) * MAX_FI <= SUM_SE) return true;
        return false;
    };

    int64_t res = -1;
    while (left <= right){
        int64_t mid = left + ((right - left)/2);
        bool flag1 = check(mid), flag2 = check_assistant(mid);
        if (flag2 || flag1){
            res = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << res;
}

void solve(){
    cin >> n >> h;
    for (int64_t i=1;i<=n;i++) cin >> arr[i].fi >> arr[i].se;
    sub3();
}


int main()
{
    fast_cin();
    solve();
    return 0;
}

