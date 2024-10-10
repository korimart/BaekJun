#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int SequenceSize;
    std::cin >> SequenceSize;

    std::vector<int> Sequence;
    Sequence.reserve(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        int Element;
        std::cin >> Element;
        Sequence.push_back(Element);
    }

    int LargestSequenceSize = 1;
    std::vector<int> MemoizationCache(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (Sequence[j] < Sequence[i])
            {
                MemoizationCache[i] = std::max(MemoizationCache[i], MemoizationCache[j]);
            }
        }
        MemoizationCache[i]++;
        LargestSequenceSize = std::max(LargestSequenceSize, MemoizationCache[i]);
    }

    std::cout << LargestSequenceSize;
}
