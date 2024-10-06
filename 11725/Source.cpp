#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int NodeCount;
    std::cin >> NodeCount;

    std::vector<std::vector<int>> NodeToNodes
    (
        NodeCount + 1,
        std::vector<int>{}
    );

    for (int i = 0; i < NodeCount - 1; i++)
    {
        int Node0, Node1;
        std::cin >> Node0 >> Node1;
        NodeToNodes[Node0].push_back(Node1);
        NodeToNodes[Node1].push_back(Node0);
    }
    
    std::vector<int> Parents(NodeCount + 1, -1);

    std::queue<int> NextNodes;
    NextNodes.push(1);
    while (!NextNodes.empty())
    {
        const int CurrentNode = NextNodes.front();
        NextNodes.pop();

        for (int ChildNode : NodeToNodes[CurrentNode])
        {
            if (Parents[ChildNode] >= 0)
            {
                continue;
            }
            
            Parents[ChildNode] = CurrentNode;
            NextNodes.push(ChildNode);
        }
    }

    for (int i = 2; i < Parents.size(); i++)
    {
        std::cout << Parents[i] << "\n";
    }
}
