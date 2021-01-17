// 에디터
// 시간제한 0.1초

#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> l;

int main()
{
    string str;
    cin >> str;

    int t;
    cin >> t;

    for (int i = 0; i < str.size(); i++)
    {
        l.push_back(str[i]);
    }

    list<char>::iterator cursur = l.end();

    while (t--)
    {
        char msg;
        cin >> msg;

        if (msg == 'P')
        {
            char alpha;
            cin >> alpha;

            l.insert(cursur, alpha);
        }
        else if (msg == 'L')
        {
            if (cursur != l.begin())
                cursur--;
        }

        else if (msg == 'D')
        {
            if (cursur != l.end())
                cursur++;
        }
        else
        {
            if (cursur != l.begin())
            {
                cursur--;
                cursur = l.erase(cursur);
            }
        }
    }

    for (auto &element : l)
        cout << element;

    return 0;
}

/* 
    처음에 벡터 사용했는데 틀림!

    중간에서의삽입, 수정 이런게 많음
    이럴 땐 --> linked list 쓰는게 되게 좋음
    STL list 활용하자!
    
    반복자 iterator 에 대해 숙지해놓으면 되게 좋음
*/