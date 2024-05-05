#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define sig(x) (x<0?-1:1)
template <typename T> T cdiv(T a, T b) {return a/b+(a/b>=0 && a%b!=0);}
template <typename T> T fdiv(T a, T b) {return a/b-(a/b<0 && a%b!=0);}
template <typename T> T mod(T a, T b) {return ((a%b)+b)%b;}
template <typename T> void vprint(T st, T nd) {auto it=st;while (next(it)!=nd){cout<<*it<<' ';it=next(it);}cout<<*it<<'\n';}
const ll MOD=1e9+7;
struct mi {int n;mi(){n=0;}mi(ll n):n(mod(n,MOD)){}explicit operator int() const {return n;}mi operator+(mi a){return mi((ll)n+a.n);}mi operator-(mi a){return mi((ll)n-a.n);}mi operator*(mi a){return mi((ll)n*a.n);}mi operator/(int a){return mi(n/a);}bool operator==(int a){return n==a;}};
template <typename T> T ncr(T n, T r) {if (r==0) return 1;return (n*ncr(n-1,r-1))/(int)r;}

void solve() {
}

int main() {
}
