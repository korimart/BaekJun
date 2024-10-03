#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int InstructionCount;
    std::cin >> InstructionCount;

    std::string Nothing;
    std::getline(std::cin, Nothing);

    std::stack<int> Stack;
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
            Stack.push(Parameter);
        }
        else if (Instruction == "pop")
        {
            std::cout << (Stack.empty() ? -1 : Stack.top()) << "\n";
            Stack.empty() ? (void)0 : Stack.pop();
        }
        else if (Instruction == "size")
        {
            std::cout << Stack.size() << "\n";
        }
        else if (Instruction == "empty")
        {
            std::cout << (Stack.empty() ? 1 : 0) << "\n";
        }
        else if (Instruction == "top")
        {
            std::cout << (Stack.empty() ? -1 : Stack.top()) << "\n";
        }
    }
}
