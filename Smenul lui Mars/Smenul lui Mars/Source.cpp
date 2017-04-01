#include <fstream>
#include <vector>

using namespace std;

const char in_file[] = "fisier.in";
const char out_file[] = "fisier.out";

ifstream fin(in_file);
ofstream fout(out_file);


//vector<vector<int>>G;
int G[15][15];

int main()
{


	int n;
	fin >> n;

	//G.resize(n + 3, vector<int>());
	for (int i = 1; i <= n; ++i)
	{
		//G[i].resize(n + 3);
		for (int j = 1; j <= n; ++j)
			fin >> G[i][j];
	}
	
	G[1][1] += 2;
	G[1][4] -= 2;
	G[4][1] -= 2;
	G[4][4] += 2;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			G[i][j] += (G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1]);

	for (int i = 1; i <= n; ++i, fout << "\n")
		for (int j = 1; j <= n; ++j)
			fout << G[i][j] << " ";


	system("pause");

	return 0;
}



/*
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
	int n, m;
	vector<int>G,B;
	
	cin >> n >> m;

	G.resize(n + 1);
	B.resize(n + 2);

	for (int i = 1; i <= n; ++i)
		cin >> G[i];

	for (int j = 1, x, y, cost; j <= m; ++j)
	{
		cin >> x >> y >> cost;
		
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);

		B[x] += cost;
		B[y + 1] -= cost;
	}

	int v = 0;
	for (int i = 1; i <= n; ++i)
	{
		v += B[i];
		G[i] += v;
	}

	for (int i = 1; i <= n; ++i)
		cout << G[i] << " ";

	system("pause");

	return 0;
}
*/