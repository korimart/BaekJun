#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

template <typename ContainerType, typename EdgesType, typename FuncType>
void TraverseGraph(const EdgesType& Edges, int StartIndex, const FuncType& Visitor)
{
    ContainerType Container;
    Container.Push(StartIndex);

    std::vector<int> Visited(Edges.size(), false);
    while (!Container.IsEmpty())
    {
        const int ThisVisit = Container.Pop();
        if (Visited[ThisVisit])
        {
            continue;
        }

        Visited[ThisVisit] = true;
        Visitor(ThisVisit);

        for (int NextVisit : Edges[ThisVisit])
        {
            Container.Push(NextVisit);
        }
    }
}

struct FQueue
{
    std::queue<int> Queue;

    void Push(int Element) { Queue.push(Element); }

    int Pop()
    {
        const int Ret = Queue.front();
        Queue.pop();
        return Ret;
    }

    bool IsEmpty() const { return Queue.empty(); }
};

struct FStack
{
    std::stack<int> Stack;

    void Push(int Element) { Stack.push(Element); }

    int Pop()
    {
        const int Ret = Stack.top();
        Stack.pop();
        return Ret;
    }

    bool IsEmpty() const { return Stack.empty(); }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int VertexCount, EdgeCount, StartNode;
    std::cin >> VertexCount >> EdgeCount >> StartNode;

    std::vector<std::vector<int>> Edges(VertexCount);
    for (int i = 0; i < EdgeCount; ++i)
    {
        int From, To;
        std::cin >> From >> To;
        Edges[From - 1].push_back(To - 1);
        Edges[To - 1].push_back(From - 1);
    }

    for (auto& Each : Edges)
    {
        std::sort(Each.begin(), Each.end(), std::greater<>{});
    }
    TraverseGraph<FStack>(Edges, StartNode - 1, [](int Visited) { std::cout << Visited + 1 << " "; });
    
    std::cout << "\n";
    
    for (auto& Each : Edges)
    {
        std::reverse(Each.begin(), Each.end());
    }
    TraverseGraph<FQueue>(Edges, StartNode - 1, [](int Visited) { std::cout << Visited + 1 << " "; });
}
