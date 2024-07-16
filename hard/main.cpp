#include <iostream>
#include <fstream>
#include <numeric>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<std::size_t> fibo;
    {
        std::size_t i = 1;
        std::size_t j = 2;

        while (j <= 10000)
        {
            fibo.push_back(j);

            std::size_t k = j;
            j += i;
            i = k;
        }
    }

    std::ifstream file("17.txt");

    constexpr std::size_t size = 333;

    std::vector<std::size_t> nums;
    nums.reserve(size);

    using input_it = std::istream_iterator<std::size_t>;
    std::copy(input_it(file), input_it(), std::back_inserter(nums));

    std::size_t count = 0;
    std::size_t max = 0;

    for (std::size_t i = 0; i < size; ++i)
    {
        for (std::size_t j = i + 1; j < size; ++j)
        {
            for (std::size_t k = j + 1; k < size; ++k)
            {
                for (std::size_t l = k + 1; l < size; ++l)
                {
                    std::set<std::size_t> vals = {nums[i], nums[j], nums[k], nums[l]};

                    if (std::search(fibo.cbegin(), fibo.cend(), vals.cbegin(), vals.cend()) != fibo.cend())
                    {
                        ++count;
                        max = std::max(max, std::accumulate(vals.cbegin(), vals.cend(), std::size_t(0)));
                    }
                }
            }
        }
    }

    std::cout << count << ' ' << max << '\n';

    return 0;
}
