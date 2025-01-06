#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> movment(std::vector<int> curpos , char direction);

int main() //< > ^ v
{
    std::string instructions {};
    std::cin >> instructions;
    std::vector<std::vector<int>> posVisited {{0,0}};
    int homesVisited {1};
    std::vector<int> curPos {0,0};
    for (auto iter {instructions.begin()} ; iter!=instructions.end() ; iter++)
    {
        curPos = movment(curPos , (*iter));
        if (std::find(posVisited.begin(),posVisited.end(),curPos) == posVisited.end())
        {
            homesVisited++;
            posVisited.push_back(curPos);
        }
    }

    std::cout << homesVisited << std::endl;
    return 0;
}



std::vector<int> movment(std::vector<int> curpos , char direction)
{
    if (direction=='<'){curpos.at(0)--;}
    else if (direction=='>'){curpos.at(0)++;}
    else if (direction=='^'){curpos.at(1)++;}
    else if (direction=='v'){curpos.at(1)--;}

    return curpos;
}