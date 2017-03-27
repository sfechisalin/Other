#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <math.h>

using namespace std;

const char in_file[] = "apm.in";
const char out_file[] = "apm.out";

ifstream fin(in_file);
ofstream fout(out_file);

class Edge
{
	friend class APM;
public:
	int source, dest, cost;
	Edge(int _source, int _dest, int _cost) :source(_source), dest(_dest), cost(_cost) { ; }
};

inline bool operator<(const Edge& lhs, const Edge& rhs){
	return lhs.source < rhs.source || (lhs.source == rhs.source && lhs.dest < rhs.dest) || (lhs.source == rhs.source && lhs.dest == rhs.dest && lhs.cost < rhs.cost);
}


/*
class Graph
{
	friend class APM;
private:
	map<int, set<Edge>> in_bound, out_bound;
public:
	void addVertex(Edge c);
	int exist(Edge c);
	void write(int nod);
};

void Graph::addVertex(Edge c)
{
	in_bound[c.source].insert(c);
	out_bound[c.dest].insert(c);

}

int Graph::exist(Edge c)
{
	if (in_bound[c.source].find(c) == in_bound[c.dest].end() || out_bound[c.dest].find(c) == out_bound[c.dest].end())
		return 0;
	return 1;
}

void Graph::write(int nod)
{
	//typedef set<int>::iterator it ;
	for (auto it = in_bound[nod].begin(); it != in_bound[nod].end(); ++it)
		fout << (*it).source << " " << (*it).dest << " " << (*it).cost << "\n";
}*/

class Heap
{
//private:
	//friend class APM;
public:
	vector<Edge>Elems;
	Heap() { Elems.push_back({ rand()%10,rand()%10,rand()%10 }); } // add a random edge,size -> 1
	Edge get_front() { return Elems[1]; }
	void add_elem(Edge);
	int best_ind(int);
	void del_elem();
};


void Heap::add_elem(Edge c)
{
	Elems.push_back(c);
	int ind = Elems.size() - 1;
	while (ind >> 1 && Elems[ind].cost < Elems[ind >> 1].cost)
	{
		swap(Elems[ind], Elems[ind >> 1]);
		ind >>= 1;
		
	}
}

int Heap::best_ind(int ind)
{
	if ((ind << 1) + 1 < Elems.size())
	{
		if (Elems[ind << 1].cost < Elems[(ind << 1) + 1].cost)
			return ind << 1;
		else
			return (ind << 1) + 1;
	}
	return ind << 1;
}

void Heap::del_elem()
{
	swap(Elems[1], Elems[Elems.size() - 1]);
	Elems.pop_back();
	
	int ind = 1;
	while (ind << 1 < Elems.size())
	{
		int inD = best_ind(ind);
		if (Elems[ind].cost > Elems[inD].cost)
		{
			swap(Elems[ind], Elems[inD]);
			ind = inD;
		}
		else
			break;
	}
}

class APM
{
private:
	vector<Edge>apm;
	vector<int>TT;
	vector<int>RG;
	int COST;
public:
	APM(int);
	int find(int);
	void unite(int, int);
	void solve(Heap,int);
	inline int get_cost() { return this->COST; }
	void write_sol();
};

APM::APM(int nr)
{
	COST = 0;
	TT.resize(nr + 1);
	RG.resize(nr + 1);
	for (int i = 1; i <= nr; ++i)
		TT[i] = i, RG[i] = 1;
}

int APM::find(int nod)
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

void APM::unite(int x, int y)
{
	if (RG[x] < RG[y])
		TT[x] = y;
	else TT[y] = x;

	if (RG[x] == RG[y])
		RG[x]++;
}


void APM::solve(Heap H, int m)
{
	for (int i = 1; i <= m; ++i)
	{
		Edge g = H.get_front();
		if (find(g.source) != find(g.dest))
		{
			apm.push_back(g);
			COST += g.cost;
			unite(find(g.source), find(g.dest));
		}
		H.del_elem();
	}
}

void APM::write_sol()
{
	fout << apm.size() << "\n";
	for (auto it : apm)
		fout << it.dest << " " << it.source << "\n";
}

int main()
{
	int N, M;
	//Graph G;
	Heap H;

	fin >> N >> M;

	APM A(N);

	int i = 1;
	for (int source, dest, cost; i <= M; ++i)
	{
		fin >> source >> dest >> cost;
		Edge c(source, dest, cost);
		H.add_elem(c);
		//G.addVertex(c);
	
	}
	
	A.solve(H, M);
	
	fout << A.get_cost() << "\n";
	A.write_sol();
	/*for (int i = 1; i <= M; ++i)
	{
		Edge e = H.get_front();
		H.del_elem();
		fout << e.dest << " " << e.source << " " << e.cost << "\n";
		fout << endl;
	}*/
	fin.close();
	fout.close();
	return 0;
}