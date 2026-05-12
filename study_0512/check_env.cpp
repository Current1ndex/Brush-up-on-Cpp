// 建议改用前缀 c 引入C 中的标准库头文件，这样头文件内容会被包含在 std 命名空间
#include <iostream>
#include <cmath>
#include <compare>
#include <array>
#include <vector>
#include <utility>
#include <optional>

// optional 可以选择保留特定类型的值，或者不包含任何值
std::optional<int> getData(int id) { if (id == 0) return 100; return std::nullopt;}

// argv[0] 不应该使用，它可能是函数名称，也可能是空字符串
int main(int argc, char const *argv[])
{  
    // 建议使用 \n，endl 大量使用会影响程序的性能，虽然同样插入一行，但是会直接刷新缓存区
    // 建议为嵌套的名称空间取个别名，如 namespace np = np1::np2::np3;
    // 建议数字字面量使用分隔符 ' 分割增强可读性
    std::cout << "hello " << 2026'05'12 << "\n";

    // 建议用 byte 处理单个字节而不是 char
    // 建议使用统一初始化
    std::byte {};

    /** 浮点数
     * 两个数量级不同的浮点数计算可能会错误
     * 两个几乎相同的浮点数计算差时会导致精度丢失
     * 很多十进制数无法精确表示为浮点数
     * numeric_limits 可以获取一些特殊的数字
     */
    std::numeric_limits<double>::infinity;

    // 强枚举类型的基本类型是整型值（不会自动转换为整数），默认从 0 开始，如果赋值，之后的成员值递增 1
    enum class PieceType: unsigned long long {King, Queen, Rook=10, Pawn};

    // 建议在利用 fallthrough 时使用特性阻止编译器发出警告
    switch (PieceType piece { PieceType::King }; piece) {
    case PieceType::King:
        std::cout << "this pirce is a king, ";
        [[fallthrough]];
    default:
        std::cout << "this price is useful.\n";
        break;
    }

    // 建议日志模块通过 __func__ 获取当前函数的名称
    std::cout << __func__ << "\n";

    /** 属性：将可选或特定于编译器厂商的信息使用 [[]] 添加到源代码
     * [[nodiscard]] 如果函数被调用，但是对返回值没有任何处理，编译器警告
     * [[maybe_unused]] 禁止编译器在未使用某些内容时发出警告
     * [[noreturn]] 避免编译器因函数不返回控制权给调用点而警告
     * [[deprecated]] 将某些内容标记为不鼓励使用
     * [[likely]]、[[unlikely]] 协助编译器预测分支
     */

    std::array<int, 3> arr {};
    std::vector<int> vtr {};
    std::cout << vtr.size();
    // pair 将两个可能不同类型的值组合在一起
    std::pair<int, float> p {9, 3.22f};
    std::cout << "first: " << p.first << ", sencond: " << p.second << ".\n";

    // optional 可以选择保留特定类型的值，或者不包含任何值
    std::optional<int> output0 = getData(2);
    if (!output0.has_value()) {
        std::cout << "!output0.has_value() == true.\n";
    }
        
}
