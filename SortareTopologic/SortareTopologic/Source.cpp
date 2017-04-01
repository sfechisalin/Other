#include <fstream>
#include <vector>
#include <bitset>
#include <stack>
#define NN 50005

using namespace std;



const char in_file[] = "sortaret.in";
const char out_file[] = "sortaret.out";

ifstream fin(in_file);
ofstream fout(out_file);

vector<vector<int>>G;

stack<int>s;
bitset<NN>viz;

void dfs(int nod)
{
	viz[nod] = 1;
	for(auto x:G[nod])
		if (!viz[x])
		{
			dfs(x);
			s.push(x);
		}
}
int main()
{
	int N, M;
	fin >> N >> M;
	G.resize(N + 1);
	int i = 0;
	for (int x,y; i <= M; ++i)
	{
		fin >> x >> y;
		G[x].push_back(y);
	}

	for (int i = 1; i <= N; ++i)
		if (!viz[i])
			dfs(i),s.push(i);

	for (; !s.empty(); fout << s.top() << " ", s.pop());
	return 0;
}