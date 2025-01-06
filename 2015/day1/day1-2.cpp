#include <iostream>

int main(){
    int floor {0};
    std::string instructions {};
    std::cin >> instructions;
    auto iter {instructions.begin()};
    for (int i=1; iter!=instructions.end() ; iter++,i++)
    {
        if ((*iter)=='('){
            floor++;
        }
        else if ((*iter)==')'){
            floor--;
        }
        if (floor<0){
            std::cout << i << '\n';
            break;
        }
    }
    std::cout << floor << std::endl;
    return 0;
}