#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    int SequenceSize;
    std::cin >> SequenceSize;

    std::array<int, 1001> Sequence;
    for (int i = 0; i < SequenceSize; ++i)
    {
        int Element;
        std::cin >> Element;
        Sequence[i] = Element;
    }

    std::array<int, 1001> MemoizationCache;
    std::fill(MemoizationCache.begin(), MemoizationCache.end(), 0);
    int LargestSum = 0;

    for (int i = 0; i < SequenceSize; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (Sequence[j] < Sequence[i])
            {
                MemoizationCache[i] = std::max(MemoizationCache[i], MemoizationCache[j]);
            }
        }
        MemoizationCache[i] += Sequence[i];
        LargestSum = std::max(LargestSum, MemoizationCache[i]);
    }

    std::cout << LargestSum;
}