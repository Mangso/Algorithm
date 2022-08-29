#include <iostream>
using namespace std;

template <typename T>
class AutoPtr {
   public:
    T* m_ptr;

   public:
    AutoPtr(T* ptr = nullptr)
        : m_ptr(ptr) {
        cout << "AutoPtr default constructor" << endl;
    }
    ~AutoPtr() {
        cout << "AutoPtr destructor" << endl;

        if (m_ptr != nullptr) delete m_ptr;
    }
    AutoPtr(const AutoPtr& a)  // 💎복사 생성자💎
    {
        cout << "AutoPtr copy constructor" << endl;

        // deep copy
        m_ptr = new T;      // T가 Resource 타입으로 들어오면 m_ptr은 Resource 타입의 포인터
        *m_ptr = *a.m_ptr;  // ⭐Resource의 '대입 연산자 오버로딩 호출
    }
    AutoPtr& operator=(const AutoPtr& a)  // 💎대입 연산자 오버로딩💎
    {
        cout << "AutoPtr copy assignment" << endl;

        if (&a == this)
            return *this;

        if (m_ptr != nullptr) delete m_ptr;

        // deep copy
        m_ptr = new T;      // 새로운 빈 공간 할당 받기. T가 Resource 타입으로 들어오면 m_ptr은 Resource 타입의 포인터
        *m_ptr = *a.m_ptr;  // ⭐Resource의 '대입 연산자 오버로딩' 호출

        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool inNull() const { return m_ptr == nullptr; }
};