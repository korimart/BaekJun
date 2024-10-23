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
    const auto ChooseOneForIndex = [&](const auto& Self, int SequenceIndex)
    {
        if (SequenceIndex >= SequenceSize)
        {
            PrintSequence();
            return;
        }

        std::for_each_n(Candidates, CandidateCount, [&](int EachCandidate)
        {
            if (Sequence[SequenceIndex] != EachCandidate && EachCandidate >= Sequence[SequenceIndex - 1])
            {
                Sequence[SequenceIndex] = EachCandidate;
                Self(Self, SequenceIndex + 1);
            }
        });

        Sequence[SequenceIndex] = 0;
    };

    std::for_each_n(Candidates, CandidateCount, [&](int EachCandidate)
    {
        if (EachCandidate != Sequence[0])
        {
            Sequence[0] = EachCandidate;
            ChooseOneForIndex(ChooseOneForIndex, 1);
        }
    });
}
