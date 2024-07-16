#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::ifstream file("17.txt");

    constexpr std::size_t size = 10000;

    std::vector<std::size_t> nums;
    nums.reserve(size);

    using input_it = std::istream_iterator<std::size_t>;
    std::copy(input_it(file), input_it(), std::back_inserter(nums));

    std::size_t count = 0;
    std::size_t min = size;

    for (std::size_t i = 0; i < size; ++i)
    {
        for (std::size_t j = i + 1; j < size; ++j)
        {
            if ((nums[i] + nums[j]) % 10 == 9)
            {
                ++count;
                min = std::min(min, nums[i] + nums[j]);
            }
        }
    }

    std::cout << count << ' ' << min << '\n';

    return 0;
}
