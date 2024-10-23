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
    const auto ChooseOneForIndex = [&](const auto& Self, int SequenceIndex, int PrevCandidateIndex)
    {
        if (SequenceIndex >= SequenceSize)
        {
            PrintSequence();
            return;
        }

        for (int i = PrevCandidateIndex + 1; i < CandidateCount; ++i)
        {
            const int Candidate = Candidates[i];
            if (Sequence[SequenceIndex] != Candidate && Candidate >= Sequence[SequenceIndex - 1])
            {
                Sequence[SequenceIndex] = Candidate;
                Self(Self, SequenceIndex + 1, i);
            }
        }
        
        Sequence[SequenceIndex] = 0;
    };

    for (int i = 0; i < CandidateCount; ++i)
    {
        const int Candidate = Candidates[i];
        if (Candidate != Sequence[0])
        {
            Sequence[0] = Candidate;
            ChooseOneForIndex(ChooseOneForIndex, 1, i);
        }
    }
}
