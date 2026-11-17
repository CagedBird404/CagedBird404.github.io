#include <iostream>
using namespace std;
struct Person {
    int age = 10;
    Person() = default;
    Person(int value) : age(value) {}
    Person(const Person& p) : age(p.age) {}
};
int main() {
    Person a;
    Person b(18);
    Person c(b);
    Person d = Person(20); // C++17 可能直接构造，不应依赖拷贝次数。
    Person e = 22; // 构造函数未标 explicit 时可隐式转换。
    cout << a.age << ' ' << b.age << ' ' << c.age << ' ' << d.age << ' ' << e.age << '\n';
}
