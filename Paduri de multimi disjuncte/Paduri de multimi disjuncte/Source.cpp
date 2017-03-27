#include <fstream>
#include <vector>

using namespace std;

const char in_file[] = "disjoint.in";
const char out_file[] = "disjoint.out";

vector<int>TT, RR;

int find(int nod)
{
	int root;
	for (root = nod; TT[root] != root; root = TT[root]);

	int y;
	for (; TT[nod] != nod; )
	{
		y = TT[nod];
		TT[nod] = root;
		nod = y;
	}

	return root;
}

void unite(int x, int y)
{
	if (RR[x] < RR[y])
		TT[x] = y;
	else TT[y] = x;
	
	if (RR[x] == RR[y])
		RR[x]++;
}

int main()
{
	int N, M, i;
	
	ifstream fin(in_file);
	ofstream fout(out_file);

	fin >> N >> M;
	TT.resize(N + 1);
	RR.resize(N + 1);
		
	for (int j = 1; j <= N; ++j)
	{
		TT[j] = j;
		RR[j] = 1;
	}

	i = 1;
	for (int cod, x, y; i <= M; ++i)
	{
		fin >> cod >> x >> y;
		if (cod == 1)
			unite(find(x), find(y));
		else
		{
			if (find(x) == find(y))
				fout << "DA\n";
			else fout << "NU\n";
		}
	}
}