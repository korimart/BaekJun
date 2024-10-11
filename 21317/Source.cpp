#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    int StoneCount;
    std::cin >> StoneCount;

    std::array<int, 20> SmallJumpCosts;
    std::array<int, 20> BigJumpCosts;
    for (int i = 0; i < StoneCount - 1; ++i)
    {
        int SmallJumpCost, BigJumpCost;
        std::cin >> SmallJumpCost >> BigJumpCost;
        SmallJumpCosts[i] = SmallJumpCost;
        BigJumpCosts[i] = BigJumpCost;
    }

    int HugeJumpCost;
    std::cin >> HugeJumpCost;

    std::array<int, 20> LeastCosts_DidHugeJump;
    std::array<int, 20> LeastCosts_DidNotHugeJump;

    LeastCosts_DidHugeJump[0] = 0;
    LeastCosts_DidNotHugeJump[0] = 0;

    if (StoneCount >= 2)
    {
        LeastCosts_DidHugeJump[1] = SmallJumpCosts[0];
        LeastCosts_DidNotHugeJump[1] = SmallJumpCosts[0];
    }

    if (StoneCount >= 3)
    {
        const int SmallJumpCost = LeastCosts_DidHugeJump[1] + SmallJumpCosts[1];
        const int BigJumpCost = LeastCosts_DidHugeJump[0] + BigJumpCosts[0];
        const int OptimalJumpCost = std::min(SmallJumpCost, BigJumpCost);
        LeastCosts_DidHugeJump[2] = OptimalJumpCost;
        LeastCosts_DidNotHugeJump[2] = OptimalJumpCost;
    }

    for (int i = 3; i < StoneCount; ++i)
    {
        const int SmallJumpCost_DidNotHugeJump = LeastCosts_DidNotHugeJump[i - 1] + SmallJumpCosts[i - 1];
        const int BigJumpCost_DidNotHugeJump = LeastCosts_DidNotHugeJump[i - 2] + BigJumpCosts[i - 2];
        LeastCosts_DidNotHugeJump[i] = std::min(SmallJumpCost_DidNotHugeJump, BigJumpCost_DidNotHugeJump);

        const int SmallJumpCost_DidHugeJump = LeastCosts_DidHugeJump[i - 1] + SmallJumpCosts[i - 1];
        const int BigJumpCost_DidHugeJump = LeastCosts_DidHugeJump[i - 2] + BigJumpCosts[i - 2];
        const int ThisHugeJumpCost = HugeJumpCost + LeastCosts_DidNotHugeJump[i - 3];
        LeastCosts_DidHugeJump[i] = std::min(SmallJumpCost_DidHugeJump, BigJumpCost_DidHugeJump);
        LeastCosts_DidHugeJump[i] = std::min(LeastCosts_DidHugeJump[i], ThisHugeJumpCost);
    }

    std::cout << std::min(LeastCosts_DidHugeJump[StoneCount - 1], LeastCosts_DidNotHugeJump[StoneCount - 1]);
}
