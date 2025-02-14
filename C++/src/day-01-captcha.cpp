#include "default_includes.hpp"
#include "solution.hpp"

static unsigned int calc_sum(const std::string& input, size_t offset)
{
    auto sum {0u};
    for (auto i {0u}; i < input.size(); ++i)
    {
        if (input[i] == input[(i + offset) % input.size()])
        {
            sum += static_cast<unsigned int>(input[i] - '0');
        }
    }

    return sum;
}

template<>
void solve<Day01>(std::istream& ins, std::ostream& outs)
{
    if (!ins.good())
    {
        outs << "Failed to open input file!" << std::endl;
        return;
    }

    std::string input;
    ins >> input;

    outs << "(Part 1) Sum = " << calc_sum(input, 1) << std::endl
         << "(Part 2) Sum = " << calc_sum(input, (input.size() / 2))
         << std::endl;
}
