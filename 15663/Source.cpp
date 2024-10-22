#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

class FCandidatePool
{
public:
    void Free(int CandidateValue)
    {
        ++CandidateAvailability[CandidateValue];
    }

    bool Acquire(int& Out)
    {
        return AcquireFirstAvailable(CandidateAvailability.begin(), Out);
    }

    bool AcquireFirstLargerThan(int Value, int& Out)
    {
        return AcquireFirstAvailable(CandidateAvailability.upper_bound(Value), Out);
    }

private:
    std::map<int, int> CandidateAvailability;

    bool AcquireFirstAvailable(auto Begin, int& Out)
    {
        const auto FirstAvailable = std::find_if(Begin, CandidateAvailability.end(),
            [](const auto& Each) { return Each.second > 0; });

        if (FirstAvailable == CandidateAvailability.end())
        {
            return false;
        }

        --FirstAvailable->second;
        Out = FirstAvailable->first;
        return true;
    }
};

int main()
{
    int CandidateCount, ChooseCount;
    std::cin >> CandidateCount >> ChooseCount;

    FCandidatePool CandidatePool;
    for (int i = 0; i < CandidateCount; ++i)
    {
        int Value;
        std::cin >> Value;
        CandidatePool.Free(Value);
    }

    std::vector<int> Sequence;
    for (int i = 0; i < ChooseCount; ++i)
    {
        int Candidate;
        CandidatePool.Acquire(Candidate);
        Sequence.insert(Sequence.begin(), Candidate);
    }

    const auto PrintSequence = [&]()
    {
        for (int i = ChooseCount - 1; i >= 0; --i)
        {
            std::cout << Sequence[i] << " ";
        }
        std::cout << '\n';
    };

    const auto ForwardSequence = [&](auto& Self, auto SequenceIt, auto SequenceEnd)
    {
        if (SequenceIt == SequenceEnd)
        {
            return false;
        }

        const int CurrentDigitValue = *SequenceIt;
        CandidatePool.Free(CurrentDigitValue);

        if (!CandidatePool.AcquireFirstLargerThan(CurrentDigitValue, *SequenceIt))
        {
            if (!Self(Self, SequenceIt + 1, SequenceEnd))
            {
                return false;
            }

            if (!CandidatePool.Acquire(*SequenceIt))
            {
                return false;
            }
        }

        return true;
    };

    do
    {
        PrintSequence();
    }
    while (ForwardSequence(ForwardSequence, Sequence.begin(), Sequence.end()));
}
