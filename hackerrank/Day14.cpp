// Day 14: Scope
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;

    // 그냥 할당 가능하구나..
    Difference(vector<int> v)
    {
        elements = v;
    }

    // Add your code here
    // sort 하고 size 얻어서 maximumDifference에 넣기.
    void computeDifference()
    {
        sort(elements.begin(), elements.end());

        int _size = elements.size();
        this->maximumDifference = abs(elements[0] - elements[_size - 1]);
    }

}; // End of Difference class

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}