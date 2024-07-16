#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::ifstream file("17.txt");

    std::vector<int> nums;
    nums.reserve(100000);

    using input_it = std::istream_iterator<int>;
    std::copy(input_it(file), input_it(), std::back_inserter(nums));

    std::size_t count = 0;
    int max = -100000;

    for (std::size_t i = 0; i < nums.size() - 2; ++i)
    {
        if (nums[i] + nums[i + 1] == nums[i + 2])
        {
            ++count;
            max = std::max(max, nums[i + 2]);
        }
        else if (nums[i + 1] + nums[i + 2] == nums[i])
        {
            ++count;
            max = std::max(max, nums[i]);
        }
        else if (nums[i] + nums[i + 2] == nums[i + 1])
        {
            ++count;
            max = std::max(max, nums[i + 1]);
        }
    }

    std::cout << count << ' ' << max << '\n';

    return 0;
}
