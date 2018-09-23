#include "default_includes.hpp"


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


void solve_Day01(std::istream& ins, std::ostream& outs)
{
    if (!ins.good())
    {
        outs << "Failed to open input file!" << std::endl;
        return;
    }

    std::string input;
    ins >> input;
    std::cout << input << std::endl;
    outs << "(Part 1) Sum = " << calc_sum(input, 1) << std::endl
         << "(Part 2) Sum = " << calc_sum(input, (input.size() / 2))
         << std::endl;
}


int main (int argc, const char* argv[]){
        
    //auto day = std::atoi(argv[i]) - 1;
    std::ifstream ins {"../inputs/Day01.txt"};    
    solve_Day01(ins, std::cout);
    //std::cout << outs << std::endl;
}
