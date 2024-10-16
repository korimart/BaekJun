#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int LiquidCount;
    std::cin >> LiquidCount;

    std::vector<int64_t> Liquids(LiquidCount);
    for (int i = 0; i < LiquidCount; ++i)
    {
        std::cin >> Liquids[i];
    }

    std::sort(Liquids.begin(), Liquids.end());

    int64_t MinAbsSum = std::numeric_limits<int64_t>::max();
    long long NegativeIndex = 0;
    long long PositiveIndex = LiquidCount - 1;
    long long MinPositiveIndex = 0;
    long long MinNegativeIndex = 0;
    while (NegativeIndex < PositiveIndex)
    {
        const int64_t Sum = Liquids[NegativeIndex] + Liquids[PositiveIndex];
        if (std::abs(Sum) < MinAbsSum)
        {
            MinAbsSum = std::abs(Sum);
            MinPositiveIndex = PositiveIndex;
            MinNegativeIndex = NegativeIndex;
        }

        if (Sum > 0)
        {
            PositiveIndex--;
        }
        else if (Sum < 0)
        {
            NegativeIndex++;
        }
        else
        {
            break;
        }
    }

    std::cout << Liquids[MinNegativeIndex] << " " << Liquids[MinPositiveIndex];
}
