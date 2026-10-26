#include <iostream>
#include <string_view>

int main() {
    constexpr std::string_view message = "C++17 environment is ready!";
    std::cout << message << '\n';
    return 0;
}
