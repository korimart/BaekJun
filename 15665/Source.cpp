#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int CandidateCount, SequenceSize;
    std::cin >> CandidateCount >> SequenceSize;

    int Candidates[10];
    for (int i = 0; i < CandidateCount; ++i)
    {
        std::cin >> Candidates[i];
    }
    std::sort(Candidates, Candidates + CandidateCount);

    int Sequence[10]{};
    const auto PrintSequence = [&]()
    {
        std::for_each_n(Sequence, SequenceSize, [&](int Each) { std::cout << Each << ' '; });
        std::cout << '\n';
    };
    const auto ChooseOneForIndex = [&](const auto& Self, int Index)
    {
        if (Index >= SequenceSize)
        {
            PrintSequence();
            return;
        }

        std::for_each_n(Candidates, CandidateCount, [&](int Each)
        {
            if (Sequence[Index] != Each)
            {
                Sequence[Index] = Each;
                Self(Self, Index + 1);
            }
        });
    };

    ChooseOneForIndex(ChooseOneForIndex, 0);
}
