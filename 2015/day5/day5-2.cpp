#include <iostream>
#include <fstream>
#include <string>

bool pairApperance(std::string str);
bool repeatingCharWithCharinbetween(std::string str); // checks for a character repeating with a character in between

int main()
{
    std::string input {};
    std::ifstream f("day5.txt");
    int niceStrings {0};

    while(f.peek()!=EOF)
    {
        std::getline(f,input);

        if (pairApperance(input) && repeatingCharWithCharinbetween(input)){
            niceStrings++;
        }
    }

    std::cout << niceStrings << std::endl;
    return 0;
}



bool pairApperance (std::string str)
{
    for (int index{0} ; index<str.length()-3 ; index++) //since we select aa and check after it for the repeating thing
                                                        //ie aaa is wrong cuz it has aa then a but aaaa is correct cus it has aa then aa
    {

        std::string selection {str.at(index),str.at(index+1)};
        if (str.find(selection,index+2) != std::string::npos){
            return true;
        }
    }
    return false;
}

bool repeatingCharWithCharinbetween(std::string str)
{
    for (int index {0} ; index < str.length()-2 ;  index++)
    {
        if (str.at(index)==str.at(index+2)){
            return true;
        }
    }
    return false;
}