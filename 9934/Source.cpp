#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Depth;
    std::cin >> Depth;

    std::string Line;
    std::getline(std::cin, Line);
    std::getline(std::cin, Line);
    std::istringstream LineStream{Line};
    std::queue<int> Buildings;
    while (true)
    {
        int BuildingNumber;
        LineStream >> BuildingNumber;
        if (!LineStream)
        {
            break;
        }
        Buildings.push(BuildingNumber);
    }

    std::vector<int> Tree(Buildings.size(), -1);
    const auto IsValidNode = [TreeSize = Tree.size()](int Node) { return 0 <= Node && Node < TreeSize; };
    const auto IsVisited = [&](int Node) { return Tree[Node] >= 0; };

    std::stack<int> ToVisit;
    ToVisit.push(0);
    while (!ToVisit.empty())
    {
        const int CurrentNode = ToVisit.top();
        const int ChildNodeLeft = CurrentNode * 2 + 1;
        const int ChildNodeRight = ChildNodeLeft + 1;

        if (IsValidNode(ChildNodeLeft) && !IsVisited(ChildNodeLeft))
        {
            ToVisit.push(ChildNodeLeft);
            continue;
        }

        ToVisit.pop();
        Tree[CurrentNode] = Buildings.front();
        Buildings.pop();

        if (IsValidNode(ChildNodeRight) && !IsVisited(ChildNodeRight))
        {
            ToVisit.push(ChildNodeRight);
        }
    }

    int CountPerLine = 1;
    int IndexOnCurrentLine = 0;
    for (int i = 0; i < Tree.size(); i++)
    {
        std::cout << Tree[i];

        IndexOnCurrentLine++;
        if (IndexOnCurrentLine >= CountPerLine)
        {
            IndexOnCurrentLine = 0;
            CountPerLine = CountPerLine << 1;
            std::cout << "\n";
        }
        else
        {
            std::cout << " ";
        }
    }
}
