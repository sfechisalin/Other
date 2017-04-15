#include <bits/stdc++.h>

using namespace std;

void radix(vector<int> &v, int exp)
{
    vector<int>Count(10,0);
    for (auto it: v)
        ++Count[(it/exp)%10];

    for (int i = 1; i < 10; ++i)
        Count[i] += Count[i-1];

    vector<int>output(v.size(),0);
    for (int i = v.size() - 1; i >= 0; --i)
    {
     output[Count[(v[i]/exp) % 10] - 1] = v[i]; //  output[--Count[(v[i]/exp) % 10]] = v[i];
     --Count[(v[i]/exp) %10 ];  //
    }
    for (int i = 0; i < v.size(); ++i)
        v[i] = output[i];
}

int main()
{
    vector<int>v{15,2,3,1,2,6,7,8,9};

    int M = *max_element(v.begin(),v.end());
    for(int exp = 1; M / exp; exp*=10)
        radix(v,exp);

   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
    return 0;
}
