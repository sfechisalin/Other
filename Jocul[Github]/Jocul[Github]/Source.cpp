#include <bitset>
#include <fstream>
#include<vector>

using namespace std;

const int INF = 0X3f3f3f3;
const int S_MAX = 1e5 + 4;

int last, sum, n;
vector <int> v;
bitset <S_MAX> dp;

inline int max(const int &a, const int &b)
{
	return (a > b ? a : b);
}

void read() {
	ifstream fin("jocul.in");

	fin >> n;
	v.resize(n);
	for (auto &it : v) {
		fin >> it;
		last = max(last, it);
		sum += it;
	}

	fin.close();
}

void solve() {
	dp.set(0);
	int maxim = last;
	for (auto &x : v) {
		for (int j = 0; j <= last; ++j) {
			if (dp[j] == true) {
				int part_sum = x + j;
				dp.set(part_sum);
				maxim = max(maxim, part_sum);
			}
		}
		last = maxim;
	}
}

void write() {
	ofstream fout("jocul.out");

	int left = sum >> 1;
	while (!dp[left]) {
		--left;
	}
	fout << left << " " << sum - left;
	fout.close();
}

int main() {
	read();
	solve();
	write();
	return 0;
}

/*
Problema jocul + afisarea lungimii betisoarelor fiecarui grup
#include <fstream>
#include <vector>
#include <bitset>
#define MaxN 105

#define ff first
#define ss second
using namespace std;

const char in_file[] = "jocul.in";
const char out_file[] = "jocul.out";

ifstream fin(in_file);
ofstream fout(out_file);

int n, s, D[MaxN][MaxN];
bitset<MaxN>T[MaxN];
vector<int>lg;


pair<int, int>sol1, sol2;
inline int max(const int &a, const int &b)
{
	return (a > b ? a : b);
}

int main()
{
	fin >> n;
	lg.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		fin >> lg[i], s += lg[i];

	for (int i = 1; i <= n; ++i)
		for (int cw = 0; cw <= s; ++cw)
		{
			D[i][cw] = D[i - 1][cw];
			T[i][cw] = 0;
			if (lg[i] <= cw && D[i][cw] <= D[i - 1][cw - lg[i]] + lg[i])
				D[i][cw] = D[i - 1][cw - lg[i]] + lg[i], T[i][cw] = 1;
		}
	
	int ok = 0;
	for (int j = (s >> 1); j >= 1 && !ok; --j)
		if (D[n][j])
			sol1.ff = n, sol1.ss = j, sol2.ff = n, sol2.ss = s - j, ok = 1;

	fout << sol1.ss << "\n";
	while (sol1.ff && sol1.ss)
	{
		if (T[sol1.ff][sol1.ss])
		{
			sol1.ss -= lg[sol1.ff];
			fout << lg[sol1.ff] << " ";
		}
		--sol1.ff;
	}

	fout << "\n";
	fout << sol2.ss << "\n";
	while (sol2.ff && sol2.ss)
	{
		if (T[sol2.ff][sol2.ss])
		{
			sol2.ss -= lg[sol2.ff];
			fout << lg[sol2.ff] << " ";
		}
		--sol2.ff;
	}
	return 0;
}
*/