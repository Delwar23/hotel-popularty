#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int a[n], b[m];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	int ans = 1e9;
	sort (a, a + n);
	sort (b, b + m);
	// reverse(b, b + m);
	int t_a[n];
	for (int i = 0; i < n; ++i)
		t_a[i] = a[i];

	for (int i = 0; i < (1 << m); ++i) {
		int temp = 0;
		for (int j = 0; j < m; ++j) {
			if ((i & (1 << j))) {
				bool f = false;
				for (int k = 0; k < n; ++k) {
					if (a[k] >= b[j]) {
						f = true;
						a[k] = 0;
						// cout << "here " << j << endl;
						break;
					}
				}
				if (!f) {
					int sum = 0;
					int k = n - 1;
					int cnt = 0;
					while (sum < b[j] and k >= 0) {
						sum += a[k];
						if (a[k] > 0)
							++cnt;
						a[k] = 0;
						--k;
					}
					if (sum >= b[j]) {
						// cout << "here " << cnt << endl;
						temp += (cnt - 1) * y;
					}
					else
						temp += b[j] * x;
				}
			}
			else
				temp += b[j] * x;
		}
		// cout << i << " * * " << temp << endl;
		ans = min(ans, temp);
		for (int i = 0; i < n; ++i)
			a[i] = t_a[i];
	}
	cout << ans << endl;

}
