#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> str(5, static_cast<std::string>("Hello world!!!"));
    if (str[0][0])
        std::cout << str[0] << std::endl;

    std::vector<std::string>::iterator it;
    it = str.begin();
    std::cout << &(*it) << std::endl;

    std::cout << str.data() << std::endl;

    return 0;
}

namespace ft {
class iterator {
    public:
    private:
};

}; // namespace ft