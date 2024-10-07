#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <limits>

class FSolver
{
public:
    FSolver()
        : MemoizationCache(1'000'000, 0)
    {
    }

    int CountRequiredOperations(int Number)
    {
        if (Number < 1)
        {
            return std::numeric_limits<int>::max();
        }

        if (Number == 1)
        {
            return 0;
        }
        
        if (const int Cached = MemoizationCache[Number])
        {
            return Cached;
        }

        int Count0 = CountRequiredOperations(Number - 1);
        int Count1 = Number % 3 == 0 ? CountRequiredOperations(Number / 3) : std::numeric_limits<int>::max();
        int Count2 = Number % 2 == 0 ? CountRequiredOperations(Number / 2) : std::numeric_limits<int>::max();
        return MemoizationCache[Number] = std::min({Count0, Count1, Count2}) + 1;
    }

private:
    std::vector<int> MemoizationCache;
};

int main()
{
    FSolver Solver;
    std::cout << Solver.CountRequiredOperations(*std::istream_iterator<int>{std::cin});
}
