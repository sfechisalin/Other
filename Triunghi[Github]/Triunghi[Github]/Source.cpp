#include <fstream>
#include <cstring>

using namespace std;

const char infile[] = "triunghi.in";
const char outfile[] = "triunghi.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 20;

int N, S, dp[MAXN][MAXN], adding[MAXN];

inline void Back(int K, int Sum) {
	if (Sum == S) {
		for (int i = 2; i <= N; ++i)
			for (int j = 1; j <= N - i + 1; ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
			}
		for (int i = N; i >= 1; --i) {
			for (int j = 1; j <= N - i + 1; ++j)
				fout << dp[i][j] << ' ';
			fout << '\n';
		}
		exit(0);
		return;
	}
	if (K == N + 1)
		return;
	for (int i = 1; Sum + i * adding[K] <= S; ++i) {
		dp[1][K] = i;
		Back(K + 1, Sum + i * adding[K]);
	}
}

int main() {
	fin >> N >> S;
	for (int i = 1; i <= N; ++i) {
		dp[1][i] = 1;
		adding[i] = 1;
		for (int j = 2; j <= N; ++j)
			for (int k = 1; k <= N - j + 1; ++k) {
				dp[j][k] = dp[j - 1][k] + dp[j - 1][k + 1];
				adding[i] += dp[j][k];
			}
		memset(dp, 0, sizeof(dp));
	}
	Back(1, 0);
	fout << "imposibil\n";
	fin.close();
	fout.close();
	return 0;
}