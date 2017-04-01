#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NN = 1 << 10 + 1;
int d[NN][NN], A[NN], B[NN], sir[NN];
int main()
{
    int n, m;
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> A[i];

    for (int i = 1; i <= m; ++i)
        fin >> B[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(A[i] ==  B[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j],d[i][j - 1]);

    fout << d[n][m] << "\n";

    for(int i = n, j = m;i;)
        if (A[i] ==  B[j])
            sir[++sir[0]] = A[i], i--,j--;
        else
            if(d[i - 1][j] < d[i][j - 1])
                j--;
            else
                i--;
    for(int i = sir[0]; i; --i)
        fout << sir[i] << " ";
    return 0;
}


/*
 Lungime

#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


// optimizari : -memoizare
//              -retine doar 2 linii (sau o linie de n + m elemente), nu toata matricea
int cmlsc(int *a, int *b, int n, int m)
{
    if (n == -1 || m == -1)
        return 0;

    if(a[n] == b[m])
        return 1 + cmlsc(a, b, n - 1, m - 1);
    else
        return max(cmlsc(a, b, n - 1, m),cmlsc(a, b, n , m - 1));

}

int main()
{
    int n, m, *A, *B;
    fin >> n >> m;

    A = (int*)malloc(n * sizeof(int));
    B = (int*)malloc(m * sizeof(int));


    for (int i = 0; i < n; ++i)
        fin >> A[i];

    for (int i = 0; i < m; ++i)
        fin >> B[i];

    fout << cmlsc(A, B, n - 1, m - 1) << "\n";

    return 0;
}
*/


