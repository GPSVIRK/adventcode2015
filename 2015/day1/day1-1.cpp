#include <iostream>

int main(){
    int floor {0};
    std::string instructions {};
    std::cin >> instructions;
    auto iter {instructions.begin()};
    for (; iter!=instructions.end() ; iter++)
    {
        if ((*iter)=='('){
            floor++;
        }
        else if ((*iter)==')'){
            floor--;
        }
    }
    std::cout << floor << std::endl;
    return 0;
}