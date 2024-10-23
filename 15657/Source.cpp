#include <iostream>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int CandidateCount, SequenceSize;
    std::cin >> CandidateCount >> SequenceSize;

    int Candidates[10];
    std::for_each_n(Candidates, CandidateCount, [&](int& Each) { std::cin >> Each; });
    std::sort(Candidates, Candidates + CandidateCount);

    int Sequence[10];
    const auto PrintSequence = [&]()
    {
        std::for_each_n(Sequence, SequenceSize, [&](int Each) { std::cout << Each << " "; });
        std::cout << "\n";
    };
    const auto ChooseOneForIndex = [&](const auto& Self, int Index)
    {
        if (Index >= SequenceSize)
        {
            PrintSequence();
            return;
        }

        std::for_each_n(Candidates, CandidateCount, [&](int Candidate)
        {
            if (Candidate >= Sequence[Index - 1])
            {
                Sequence[Index] = Candidate;
                Self(Self, Index + 1);
            }
        });
    };

    std::for_each_n(Candidates, CandidateCount, [&](int Candidate)
    {
        Sequence[0] = Candidate;
        ChooseOneForIndex(ChooseOneForIndex, 1);
    });
}
