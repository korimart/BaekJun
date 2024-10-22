#include <iostream>
#include <bitset>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int SequenceSize, TargetSum;
    std::cin >> SequenceSize >> TargetSum;

    std::vector<int> Sequence(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        std::cin >> Sequence[i];
    }

    const auto GetSumFromULong = [&](unsigned long Long)
    {
        const std::bitset<20> Bits{Long};

        int Ret = 0;
        for (int i = 0; i < SequenceSize; ++i)
        {
            if (Bits.test(i))
            {
                Ret += Sequence[i];
            }
        }
        return Ret;
    };

    int Count = 0;
    const unsigned long LastNumber = (1 << SequenceSize) - 1;
    for (unsigned long EnabledBitsBase10 = 1; EnabledBitsBase10 <= LastNumber; ++EnabledBitsBase10)
    {
        if (GetSumFromULong(EnabledBitsBase10) == TargetSum)
        {
            ++Count;
        }
    }

    std::cout << Count;
}
