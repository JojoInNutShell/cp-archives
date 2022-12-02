#include <bits/stdc++.h>

using namespace std;

array<array<long long, 107>, 107> cum;

bool consider(long long barea, long long bpay, long long aarea, long long apay) {
	if(barea > aarea) {
		return false;
	} else if (aarea > barea) {
		return true;
	} else {
		if(apay < bpay) {
			return true;
		} else {
			return false;
		}
	}
	return true;
}

void initcum() {
	for(auto a : cum) {
		a.fill(0);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int T, count;
	count = 1;
	cin >> T;
	while(T--) {
		long long n, m, kk, t;
		cin >> n >> m >> kk;
		initcum();
		for(int i = 0; i < n; ++i) { //Making 2d cumulative sum
			for(int j = 0; j < m; ++j) {
				cin >> t;
				if(i == 0 && j == 0) {
					cum[i][j] = t;
				} else if(i == 0) {
					cum[i][j] = cum[i][j - 1] + t;
				} else if(j == 0) {
					cum[i][j] = cum[i - 1][j] + t;
				} else {
					cum[i][j] = t + cum[i - 1][j] + cum[i][j - 1] - cum[i - 1][j - 1];
				}
			}
		}
		long long area = 0, pay = 0, tarea, tpay;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				for(int k = i; k < n; ++k) {
					for(int l = j; l < m; ++l) {
						tarea = (k - i + 1) * (l - j + 1);
						if(i == 0 && j == 0) {
							tpay = cum[k][l];
						} else if(i == 0) {
							tpay = cum[k][l] - cum[k][j - 1];
						} else if(j == 0) {
							tpay = cum[k][l] - cum[i - 1][l];
						} else {
							tpay = cum[k][l] - cum[i - 1][l] - cum[k][j - 1] + cum[i - 1][j - 1];
						}
						
						if(tpay > kk) {
							continue;
						} else {
							if(consider(area, pay, tarea, tpay)) {
								area = tarea;
								pay = tpay;
							}
						}
					}
				}
			}
		}
		cout << "Case #" << count << ": " << area << " " << pay << endl;
		++count;
	}
	return 0;
}