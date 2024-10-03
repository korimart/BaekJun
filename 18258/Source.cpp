#include <iostream>
#include <queue>
#include <string>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int InstructionCount;
    std::cin >> InstructionCount;
    std::string Nothing;
    std::getline(std::cin, Nothing);

    std::queue<int> Queue;
    for (int i = 0; i < InstructionCount; i++)
    {
        std::string Line;
        std::getline(std::cin, Line);
        std::istringstream LineStream{Line};
        std::string Instruction;
        LineStream >> Instruction;

        if (Instruction == "push")
        {
            int Parameter;
            LineStream >> Parameter;
            Queue.push(Parameter);
        }
        else if (Instruction == "pop")
        {
            std::cout << (Queue.empty() ? -1 : Queue.front()) << "\n";
            Queue.empty() ? (void)0 : Queue.pop();
        }
        else if (Instruction == "size")
        {
            std::cout << Queue.size() << "\n";
        }
        else if (Instruction == "empty")
        {
            std::cout << (Queue.empty() ? 1 : 0) << "\n";
        }
        else if (Instruction == "front")
        {
            std::cout << (Queue.empty() ? -1 : Queue.front()) << "\n";
        }
        else if (Instruction == "back")
        {
            std::cout << (Queue.empty() ? -1 : Queue.back()) << "\n";
        }
    }
}