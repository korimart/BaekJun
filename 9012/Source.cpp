#include <iostream>
#include <string>

bool IsPS(const std::string& MaybePS)
{
    int OpenCount = 0;
    for (char Each : MaybePS)
    {
        OpenCount += Each == '(' ? 1 : -1;
        if (OpenCount < 0)
        {
            return false;
        }
    }
    return OpenCount == 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int ProblemCount;
    std::cin >> ProblemCount;

    for (int i = 0; i < ProblemCount; i++)
    {
        std::string MaybePS;
        std::cin >> MaybePS;
        std::cout << (IsPS(MaybePS) ? "YES" : "NO") << "\n";
    }
}