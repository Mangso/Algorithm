// 시험 성적

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    if (num >= 90 && num <= 100)
        cout << "A" << endl;
    else if (num >= 80 && num <= 89)
        cout << "B" << endl;
    else if (num >= 70 && num <= 79)
        cout << "C" << endl;
    else if (num >= 60 && num <= 69)
        cout << "D" << endl;
    else
        cout << "F" << endl;

    return 0;
}