#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::ifstream file("17.txt");

    std::vector<std::size_t> nums;
    nums.reserve(10000001);

    using input_it = std::istream_iterator<std::size_t>;
    std::size_t res = std::accumulate(input_it(file), input_it(), 0, [&nums](std::size_t lhs, std::size_t rhs)
    {
        nums.push_back(rhs);
        return lhs ^ rhs;
    });

    std::size_t pos = std::distance(nums.cbegin(), std::find(nums.cbegin(), nums.cend(), res)) + 1;
    std::cout << res << ' ' << pos << '\n';

    return 0;
}
