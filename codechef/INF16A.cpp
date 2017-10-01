#include "bits/stdc++.h"
using namespace std;
typedef long long int LL;
#define fi first
#define se second
#define pb push_back
#define fo(i, n) for (int i = 0; i < (int)(n); ++i)
#define fr(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ret return 0
const int maxn = 5e3 + 5;
LL q, inv[maxn], fact[maxn], ifact[maxn];

LL modE(LL n, LL x) {
	LL res = 1;
	while (x) {
		if (x & 1)
			res = res * n % q;
		n = (n * n) % q;
		x >>= 1;
	}
	return res;
}

LL solve(LL n, LL p1, LL p2) {
	LL exp = n / q - (p1 / q) * p2 - p2 / q;
	if (exp)return 0;
	
	LL num = modE(fact[q - 1], n / q);
	if(n % q)	num = (num * fact[n % q]) % q;
	
	LL den = modE(fact[q - 1], p1 / q);
	if(p1 % q)	den = (den * fact[p1 % q]) % q;
	den = modE(den, p2);

	LL den2 = modE(fact[q - 1], p2 / q);
	if(p2 % q)	den2 = (den2 * fact[p2 % q]) % q;

	return num * ifact[den * den2 % q] % q; 
}

int main() {
	// ios::sync_with_stdio(false), cin.tie(0);
	fact[0] = fact[1] = ifact[1] = 1;
	int t, T = 1; cin >> t;
	while (T <= t) {
		cout << "Case " << (T++) << ":\n";
		int L;
		cin >> L >> q;
		for (int i = 2; i < q; i++)fact[i] = fact[i - 1] * i % q, ifact[i] = (q - (q / i) * ifact[q % i] % q) % q;
		while (L--) {
			LL n, p1, p2, sq, ans = 2; 
			cin >> n;
			sq = (LL)sqrt(n);
			if (sq * sq == n) {
				ans = (ans + solve(n, sq, sq)) % q;
				cout << ans << endl;
				continue;
			}
			while (sq) {
				if (n % sq == 0) {
					p1 = sq, p2 = n / sq;
					break;
				}
				sq--;
			}
			// cout << p1 << ' ' << p2 << endl;
			if(p1 != 1)ans = (ans + solve(n, p1, p2)) % q;
			if(p1 != 1)ans = (ans + solve(n, p2, p1)) % q;
			cout << ans << endl;
		}

	}

}


