#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define eb emplace_back
#define pb push_back
#define deb(a) cerr << #a << " = " << a << '\n'
#define deb2(a, b) cerr << #a << " = " << a << ", " << #b << " = " << b << '\n'
 
const ll INF = 1e9 + 7;
const int mN = 1e4 + 5;
const ld EPS = 1e-12;
const ld PI = 3.14159265358979323846;
 
ll n, k, a[mN], l, r, m;
 
bool check() {
    ll cnt = 0, last = -INF;
    for (int i = 0; i < n; i++) {
        if (a[i] - last >= m) {
            cnt++;
            last = a[i];
        }
    }
    return cnt >= k;
}
 
int main() {
    FIO;
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    r = a[n - 1];
    while (r - l > 1) {
        m = (l + r) / 2;
        if (check())
            l = m;
        else
            r = m;
    }
    cout << l;
    return 0;
}