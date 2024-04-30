#include <vector>
#include <cassert>
#include <iostream>

std::vector<int>::const_iterator FindSmallestIndexRange(
    std::vector<int> const & data, int begin_pos, int end_pos) {
    std::vector<int>::const_iterator iter = data.cbegin() + begin_pos;
    std::vector<int>::const_iterator iter_smallest = iter;
    while (iter < data.cend() && iter <=  data.cbegin() + end_pos) {
        if (*iter < *iter_smallest) {
            iter_smallest = iter;
        }
        ++iter;
    }
    return iter_smallest;
}


using c_iter = std::vector<int>::const_iterator;
int main() {
    std::vector<int> data = {6, 1, 5, 4, 3, 2, 1};
    c_iter iter_smallest = FindSmallestIndexRange(data, 2, 5);
    std::cout << *iter_smallest << std::endl;
    assert(*iter_smallest == 2);
    data.at(5) = 7;
    std::cout << *iter_smallest << std::endl;
    assert(*iter_smallest == 2);
}
