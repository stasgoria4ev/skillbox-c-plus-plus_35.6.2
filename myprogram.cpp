#include <iostream>
#include <vector>
#include <initializer_list>
#include <unordered_set>
#include <memory>
#include <algorithm>

template <typename T>
class Tool {
    std::vector<T> parts;
public:
    Tool(const std::initializer_list<T>& inPart) {
        parts = inPart;
    }

    std::vector<T> GetArray() {
        return parts;
    }
};

int main() {
    Tool<int> t = {1,2,1,2,5,7,7,8};
    for (auto i: t.GetArray())
        std::cout << i << ' ';
    std::cout << '\n';

    auto arr = [](const std::vector<int>& array) {
        std::unordered_set<int> arUnSet;
        for (auto i: array)
            arUnSet.insert(i);

        auto arrayU = std::make_unique<std::vector<int>>();
        for (auto i: arUnSet)
            arrayU->push_back(i);

        return arrayU;
    }(t.GetArray());

    for (auto i: *arr)
        std::cout << i << ' ';
}