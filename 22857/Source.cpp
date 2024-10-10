#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int SequenceSize, MaxDeleteCount;
    std::cin >> SequenceSize >> MaxDeleteCount;

    std::vector<int> Sequence;
    Sequence.reserve(SequenceSize);
    for (int i = 0; i < SequenceSize; ++i)
    {
        int Element;
        std::cin >> Element;
        Sequence.push_back(Element);
    }

    int LargestLength = 0;
    std::vector<int> PrevEvenSequenceSizePerDeleteCount(MaxDeleteCount + 1, 1);
    
    int PrevEvenElementIndex = -1;
    for (int i = 0; i < SequenceSize; ++i)
    {
        if (Sequence[i] % 2 == 0)
        {
            PrevEvenElementIndex = i;
            LargestLength = 1;
            break;
        }
    }
    
    for (int i = PrevEvenElementIndex + 1; i < SequenceSize; ++i)
    {
        if (Sequence[i] % 2 == 0)
        {
            std::vector<int> EvenSequenceSizePerDeleteCount(MaxDeleteCount + 1, 1);
            
            const int OddCount = i - PrevEvenElementIndex - 1;
            for (int DeleteCount = OddCount; DeleteCount <= MaxDeleteCount; ++DeleteCount)
            {
                EvenSequenceSizePerDeleteCount[DeleteCount] = PrevEvenSequenceSizePerDeleteCount[DeleteCount - OddCount] + 1;
                LargestLength = std::max(LargestLength, EvenSequenceSizePerDeleteCount[DeleteCount]);
            }

            PrevEvenElementIndex = i;
            PrevEvenSequenceSizePerDeleteCount = std::move(EvenSequenceSizePerDeleteCount);
        }
    }

    std::cout << LargestLength;
}