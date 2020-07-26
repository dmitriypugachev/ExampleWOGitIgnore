#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define eb emplace_back
#define pb push_back
#define deb(a) cerr << #a << " = " << a << '\n';
#define deb2(a, b) cerr << #a << " = " << a << ", " << #b << " = " << b << '\n';
 
const ll INF = 1e9 + 7;
const int mN = 1e5 + 5;
const ld EPS = 1 / 1e18;
const ld PI = 3.14159265358979323846;
 
ll n, ans[mN], sum = 0;
bool can[mN];
ld a[mN];
 
int main()
{
    FIO
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(abs(a[i] - ll(a[i])) > EPS)
            can[i] = 1;
        sum += floor(a[i]);
    }
    ll need = abs(sum);
    deb(a[1]);
    for(int i = 0; i < n; i++) {
        if(need and can[i]) {
            if(abs(ceil(a[i])) > EPS)
                cout << ceil(a[i]);
            else
                cout << 0;
            need--;
        }
        else if(abs(a[i]) > EPS)
            cout << floor(a[i]);
        else
            cout << 0;
        cout << '\n';
    }
    return 0;
}