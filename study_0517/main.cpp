#include <iostream>
#include <initializer_list>
#include <string>

class AirlineTicket {
    public:
        // 构造函数初始化器使用：
        AirlineTicket() : passengerName {"Unknown"} {
            std::cout << "hello, 0517.\n";
        };
        ~AirlineTicket();
        double calculatePriceInDollars();
        // 类中的 const 方法阻止修改成员变量
        std::string getPassengerName() const;
        // const 保护函数参数不被无意识修改
        void setPassengerName(const std::string name);
    private:
        std::string passengerName;
};

int makeSum(std::initializer_list<int> values) {
    int total {};
    for (int v: values) total += v;
    return total;
}

constexpr int get_n() {
    return 32;
}

int main(int argc, char const *argv[]) {
    
    // 通过结构化绑定可以同时声明多个变量，并使用数组、结构体、pair 或元组进行初始化
    struct Struct0517 {double sx, sy; int sz;};
    Struct0517 test_struct_bind {3.14, 1.5926, -1000};
    auto [x, y, z] {test_struct_bind};
    std::cout << x << " " << y << " " << z << ".\n";

    // 循环中少用 continue，无规则跳转会影响程序性能

    // 利用初始化列表，可以实现能接收可变数量参数的函数
    // 域解析运算符 :: 如果单独使用，会同时索引全局作用域和未命名作用域
    std::cout << ::makeSum({1, 2, 3, 4, 5, 6}) << ".\n";

    // 统一初始化能阻止窄化转换
    // 使用 new 在自由存储区申请内存，之后必须使用 delete 删除
    // NULL 等价于整数 0
    int* test1 {new int};
    std::cout << test1 << ".\n";
    delete test1;
    test1 = nullptr; 

    // const 直接作用于左侧
    int const* test2 {new int[10] {}}; // 将指向的值指定为常量
    int* const test3 {new int[10] {}}; // 将 test3 指定未常量
    // constexpt 构造常量表达式
}


