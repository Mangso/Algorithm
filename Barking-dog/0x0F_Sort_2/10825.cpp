// 국영수
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int k, e, m;
};

bool Compare(const Student& a, const Student& b) {
    if (a.k == b.k) {
        if (a.e == b.e) {
            if (a.m == b.m) return a.name < b.name;
            return a.m > b.m;
        }
        return a.e < b.e;
    }
    return a.k > b.k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<Student> students;
    for (int i = 0; i < N; i++) {
        Student student;
        cin >> student.name >> student.k >> student.e >> student.m;

        students.push_back(student);
    }
    sort(students.begin(), students.end(), Compare);

    for (const auto& s : students) {
        cout << s.name << '\n';
    }

    return 0;
}