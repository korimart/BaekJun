#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class FSolver
{
public:
    FSolver(std::vector<int>&& InStairs)
        : Stairs(std::move(InStairs))
          , ShortLastJumpMemoizationCache(Stairs.size(), 0)
          , LongLastJumpMemoizationCache(Stairs.size(), 0)
    {
    }

    int SolveForMaxScore()
    {
        return std::max(
            SolveForMaxScoreShortLastJump(Stairs.size() - 1),
            SolveForMaxScoreLongLastJump(Stairs.size() - 1));
    }

private:
    std::vector<int> Stairs;
    std::vector<int> ShortLastJumpMemoizationCache;
    std::vector<int> LongLastJumpMemoizationCache;

    int SolveForMaxScoreShortLastJump(int StairIndex)
    {
        if (StairIndex < 0)
        {
            return 0;
        }
        
        int& Cache = ShortLastJumpMemoizationCache[StairIndex];
        if (Cache)
        {
            return Cache;
        }

        return Cache = Stairs[StairIndex] + SolveForMaxScoreLongLastJump(StairIndex - 1);
    }
    
    int SolveForMaxScoreLongLastJump(int StairIndex)
    {
        if (StairIndex < 0)
        {
            return 0;
        }
        
        int& Cache = LongLastJumpMemoizationCache[StairIndex];
        if (Cache)
        {
            return Cache;
        }

        return Cache = Stairs[StairIndex] + std::max(
            SolveForMaxScoreShortLastJump(StairIndex - 2),
            SolveForMaxScoreLongLastJump(StairIndex - 2));
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int StairCount;
    std::cin >> StairCount;

    std::vector<int> Stairs;
    Stairs.reserve(StairCount);
    std::copy_n(std::istream_iterator<int>{std::cin}, StairCount, std::back_inserter(Stairs));

    FSolver Solver{std::move(Stairs)};
    std::cout << Solver.SolveForMaxScore();
}
