#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int SequenceSize, MaxDuplicateCount;
    std::cin >> SequenceSize >> MaxDuplicateCount;

    std::vector<int> Sequence;
    Sequence.reserve(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        int Element;
        std::cin >> Element;
        Sequence.push_back(Element);
    }

    int LongestLength = 0;
    std::vector<uint8_t> DuplicateCounts(100'001);

    auto WindowFirst = Sequence.begin();
    auto WindowLast = Sequence.begin();

    while (true)
    {
        while (++DuplicateCounts[*WindowLast] <= MaxDuplicateCount)
        {
            ++WindowLast;
            LongestLength = std::max(LongestLength, static_cast<int>(WindowLast - WindowFirst));

            if (WindowLast == Sequence.end())
            {
                goto Escape;
            }
        }

        while (DuplicateCounts[*WindowLast] > MaxDuplicateCount)
        {
            --DuplicateCounts[*WindowFirst];
            ++WindowFirst;
        }

        if (++WindowLast == Sequence.end())
        {
            LongestLength = std::max(LongestLength, static_cast<int>(WindowLast - WindowFirst));
            break;
        }
    }

Escape:
    std::cout << LongestLength;
}
