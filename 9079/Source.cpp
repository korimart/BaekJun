#include <iostream>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <array>

struct FBoard
{
    std::bitset<9> Board;

    operator const std::bitset<9>&() const
    {
        return Board;
    }

    friend bool operator==(const FBoard& Left, const FBoard& Right)
    {
        return Left.Board == Right.Board;
    }

    void ReadFromStream(std::istream& Stream)
    {
        for (int i = 0; i < 9; ++i)
        {
            char Each;
            Stream >> Each;
            Board[i] = Each == 'H';
        }
    }

    FBoard FlipRow(int Row) const
    {
        FBoard Ret = *this;
        Ret.Board[3 * Row + 0].flip();
        Ret.Board[3 * Row + 1].flip();
        Ret.Board[3 * Row + 2].flip();
        return Ret;
    }

    FBoard FlipColumn(int Column) const
    {
        FBoard Ret = *this;
        Ret.Board[Column].flip();
        Ret.Board[Column + 3].flip();
        Ret.Board[Column + 6].flip();
        return Ret;
    }

    FBoard FlipDiagonal() const
    {
        FBoard Ret = *this;
        Ret.Board[0].flip();
        Ret.Board[4].flip();
        Ret.Board[8].flip();
        return Ret;
    }

    FBoard FlipDiagonal2() const
    {
        FBoard Ret = *this;
        Ret.Board[2].flip();
        Ret.Board[4].flip();
        Ret.Board[6].flip();
        return Ret;
    }

    std::array<FBoard, 8> NextBoards() const
    {
        return
        {
            FlipRow(0),
            FlipRow(1),
            FlipRow(2),
            FlipColumn(0),
            FlipColumn(1),
            FlipColumn(2),
            FlipDiagonal(),
            FlipDiagonal2(),
        };
    }

    bool IsDone() const
    {
        return Board.all() || Board.none();
    }
};

template <>
struct std::hash<FBoard> : std::hash<std::bitset<9>>
{
};

int main()
{
    int TestCaseCount;
    std::cin >> TestCaseCount;

    FBoard InitialBoard;
    for (int i = 0; i < TestCaseCount; ++i)
    {
        InitialBoard.ReadFromStream(std::cin);

        std::queue<FBoard> ToVisit, ToVisit2;
        std::unordered_set<FBoard> Visited;
        Visited.emplace(InitialBoard);
        ToVisit2.emplace(InitialBoard);

        int StepCount = 0;
        do
        {
            std::swap(ToVisit, ToVisit2);
            while (!ToVisit.empty())
            {
                const FBoard CurrentBoard = ToVisit.front();
                ToVisit.pop();

                if (CurrentBoard.IsDone())
                {
                    std::cout << StepCount << '\n';
                    goto Next;
                }

                for (const FBoard& Each : CurrentBoard.NextBoards())
                {
                    if (!Visited.contains(Each))
                    {
                        Visited.emplace(Each);
                        ToVisit2.emplace(Each);
                    }
                }
            }
            StepCount++;
        }
        while (!ToVisit2.empty());

        std::cout << -1 << '\n';
    Next:;
    }
}
