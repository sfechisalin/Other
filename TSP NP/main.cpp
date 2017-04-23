#include <bits/stdc++.h>

using namespace std;
struct edge{
    int x, y, z;
};

int n, m;
vector<int>discovered;
vector<edge>G, Answ;

bool fCompare(const edge& a, const edge& b){
    return a.z < b.z;
}

void read()
{
    ifstream fin("edges.in");
    fin >> n;
    discovered.resize(n + 1);
    m = (n*(n - 1))>>1;
    G.resize(m + 1);
    for(int i = 1; i <= m; ++i)
        fin >> G[i].x >> G[i].y >> G[i].z;
}

void solve(int start)
{
    int k = 0;
    Answ.push_back(G[start]);
    discovered[Answ[0].x]++;
    discovered[Answ[0].y]++;
    k++;

    int j = 2;
    while(k < n)
    {
        if ( (discovered[G[j].x] + discovered[G[j].y] == 1) || (k == n - 1 && discovered[G[j].x] == 1 && discovered[G[j].y] == 1) )
        {
            Answ.push_back(G[j]);
            ++k;
            ++discovered[G[j].x];
            ++discovered[G[j].y];
        }
        ++j;
    }
}

int main()
{
    read();
    sort(G.begin(), G.end(), fCompare);
    solve(1);

    for (const edge &e:Answ)
        cout << "(" << e.x << "," << e.y << ")";
    return 0;
}
