#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int InstructionCount;
    std::cin >> InstructionCount;

    std::vector<int> Roots(1'000'001);
    std::iota(Roots.begin(), Roots.end(), 0);
    std::vector<int> ElementCounts(1'000'001, 1);

    const auto FindTopMostImpl = [&](auto& Self, int Element)
    {
        if (Element == Roots[Element])
        {
            return Element;
        }
        return Roots[Element] = Self(Self, Roots[Element]);
    };

    const auto FindTopMost = [&](int Element)
    {
        return FindTopMostImpl(FindTopMostImpl, Element);
    };

    for (int i = 0 ; i < InstructionCount; ++i)
    {
        char Instruction;
        std::cin >> Instruction;

        if (Instruction == 'I')
        {
            int SameSetElement0, SameSetElement1;
            std::cin >> SameSetElement0 >> SameSetElement1;

            const int Root0 = FindTopMost(SameSetElement0);
            const int Root1 = FindTopMost(SameSetElement1);
            if (Root0 != Root1)
            {
                Roots[Root1] = Root0;
                ElementCounts[Root0] += ElementCounts[Root1];
            }
        }
        else
        {
            int Element;
            std::cin >> Element;
            std::cout << ElementCounts[FindTopMost(Element)] << '\n';
        }
    }
}