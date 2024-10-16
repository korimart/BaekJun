#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ElementCount, InstructionCount;
    std::cin >> ElementCount >> InstructionCount;
    ElementCount++;

    std::vector<int> Roots(ElementCount);
    std::iota(Roots.begin(), Roots.end(), 0);

    const auto FindTopMost = [&](const auto& Self, int Element)
    {
        if (Roots[Element] == Element)
        {
            return Element;
        }

        return Roots[Element] = Self(Self, Roots[Element]);
    };

    for (int i = 0; i < InstructionCount; ++i)
    {
        int Instruction, Operand0, Operand1;
        std::cin >> Instruction >> Operand0 >> Operand1;

        const int Root0 = FindTopMost(FindTopMost, Operand0);
        const int Root1 = FindTopMost(FindTopMost, Operand1);
        
        if (Instruction == 0)
        {
            if (Root0 != Root1)
            {
                Roots[Root1] = Root0;
            }
        }
        else
        {
            std::cout << (Root0 == Root1 ? "YES" : "NO") << '\n';
        }
    }
}
