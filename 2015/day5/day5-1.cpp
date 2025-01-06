#include <iostream>
#include <fstream>
#include <string>

bool isVow(char c);
bool hasForbiddenStr (std::string str);

int main()
{
    std::string input {};
    std::ifstream f("day5.txt");
    int niceStrings {0};

    while(f.peek()!=EOF)
    {
        std::getline(f,input);
        int doublechars{0} , threeVowels{0} ;
        for (auto iter {input.begin()} ; iter!=input.end() ; iter++)
        {
            if (!(threeVowels==3) && isVow(*iter)){threeVowels++;}

            if (!doublechars && iter!=input.begin() && (*iter)==(*(iter-1))){doublechars++;}
        }
        if ((threeVowels==3) && (doublechars==1) && !hasForbiddenStr(input)){
            niceStrings++;
        }
    }

    std::cout << niceStrings << std::endl;
    return 0;
}

bool isVow(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }
    return false;
}

bool hasForbiddenStr(std::string str)
{
    if ((str.find("ab")!=std::string::npos) || (str.find("cd")!=std::string::npos) || (str.find("pq")!=std::string::npos) || (str.find("xy")!=std::string::npos))
    {
        return true;
    }
    return false;
}