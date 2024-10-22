#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

int main()
{
    int LastNumber, DigitCount;
    std::cin >> LastNumber >> DigitCount;

    std::vector<int> Digits(DigitCount);
    std::iota(Digits.rbegin(), Digits.rend(), 1);

    const auto PrintDigits = [&]()
    {
        std::copy(Digits.rbegin(), Digits.rend(), std::ostream_iterator<int>{std::cout, " "});
        std::cout << '\n';
    };

    std::vector<bool> bNumberBeingUsed(LastNumber + 1);
    for (int Each : Digits)
    {
        bNumberBeingUsed[Each] = true;
    }

    const auto FindFirstUnusedNumber = [&](int StartNumber)
    {
        const auto Found = std::find(bNumberBeingUsed.begin() + StartNumber, bNumberBeingUsed.end(), false);
        return Found == bNumberBeingUsed.end() ? 0 : static_cast<int>(Found - bNumberBeingUsed.begin());
    };

    const auto AddOneToDigitAt = [&](auto& Self, int Index)
    {
        if (Index >= DigitCount)
        {
            return false;
        }

        bNumberBeingUsed[Digits[Index]] = false;

        int Next = FindFirstUnusedNumber(Digits[Index] + 1);
        if (!Next)
        {
            if (!Self(Self, Index + 1))
            {
                return false;
            }

            Next = FindFirstUnusedNumber(1);
            if (!Next)
            {
                return false;
            }
        }

        Digits[Index] = Next;
        bNumberBeingUsed[Next] = true;

        return true;
    };

    do
    {
        PrintDigits();
    }
    while (AddOneToDigitAt(AddOneToDigitAt, 0));
}
