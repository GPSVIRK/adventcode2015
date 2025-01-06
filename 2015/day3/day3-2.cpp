#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> movment(std::vector<int> curpos , char direction);// to change curPos to the newest pos

int main() //calculate number of new positions visited on an infinite 2d plane with two people following alternating instructions
{
    std::string instructions {};
    std::cin >> instructions;
    std::vector<std::vector<int>> posVisited {{0,0}}; //all positions visited
    int homesVisited {1} , firstOrSecond {1};         //first home is always visited at(0,0)
    std::vector<int> curPos1 {0,0} , curPos2 {0,0};


    for (auto iter {instructions.begin()} ; iter!=instructions.end() ; iter++)
    {
        if (firstOrSecond)
        {
            curPos1 = movment(curPos1 , (*iter));
            if (std::find(posVisited.begin(),posVisited.end(),curPos1) == posVisited.end())
            {
                homesVisited++;
                posVisited.push_back(curPos1);
            }
            firstOrSecond--;
        }
        else
        {
            curPos2 = movment(curPos2 , (*iter));
            if (std::find(posVisited.begin(),posVisited.end(),curPos2) == posVisited.end())
            {
                homesVisited++;
                posVisited.push_back(curPos2);
            }
            firstOrSecond++;
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