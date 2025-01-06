#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void initAllLights (std::vector<int> &v);
void turnOnRange (std::vector<int> &v , std::string &str , long long &brightness);
void turnOffRange (std::vector<int> &v , std::string &str , long long &brightness);
void toggleRange (std::vector<int> &v , std::string &str , long long &brightness);
void toggle (std::vector<int> &v , int &curPos , long long &brightness);
void instructionParser (int pos , int &start , int &end , std::string &str);

int main(){
    long long brightness{0LL};
    std::string instruction {};
    std::ifstream f("day6.txt");
    std::vector<int> allLights {};
    initAllLights(allLights);

    while(f.peek()!=EOF)
    {
        std::getline(f,instruction);
        if (instruction.find("turn on") != std::string::npos)
        {
            // long long bef {brightness};
            turnOnRange(allLights , instruction , brightness);
            // std::cout << "turn on for: " << instruction << " led to " << brightness-bef << '\n';
        }
        else if (instruction.find("turn off") != std::string::npos)
        {
            // long long bef {brightness};
            turnOffRange(allLights , instruction , brightness);
            // std::cout << "turn off for: " << instruction << " led to " << brightness-bef << '\n';
        }
        else if (instruction.find("toggle") != std::string::npos)
        {
            // long long bef {brightness};
            toggleRange(allLights , instruction , brightness);
            // std::cout << "toggle for: " << instruction << " led to " << brightness-bef << '\n';
        }
    }

    std::cout << brightness << std::endl;

    f.close();
    return 0;
}

void initAllLights (std::vector<int> &v)
{
    for (int i {0} ; i<(1000*1000) ; i++){
        v.push_back(0);
    }
    v.shrink_to_fit();
}


void instructionParser (int pos , int &start , int &end , std::string &str)
{
    int buffer{0};
    for (int i {pos} ; str.at(i)!=' ' ; i++)
    {
        if (str.at(i) != ',')
        {
            buffer = buffer*10 + (str.at(i)-'0');
        }
        else if (str.at(i)==',')
        {
            start = buffer*1000;
            buffer=0;
        }
    }
    start+=buffer;
    buffer=0;

    pos = str.find("through") + 8;
    for (int i {pos} ; i<str.length() ; i++)
    {
        if (str.at(i) != ',')
        {
            buffer = buffer*10 + (str.at(i)-'0');
        }
        else if (str.at(i)==',')
        {
            end = buffer*1000;
            buffer=0;
        }
    }
    end+=buffer;
}



void turnOnRange (std::vector<int> &v , std::string &str , long long &brightness)
{
    int start {0} , end {0} , curPos {0} , ycrement {1} , xcrement{1000};
    instructionParser(8,start,end,str);
    curPos=start;
    while(curPos<end)
    {
        v.at(curPos)++;
        brightness++;
        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            ycrement++;
            continue;
        }
        curPos+=1000;
    }
    v.at(end)++;
    brightness++;
}

void turnOffRange (std::vector<int> &v , std::string &str , long long &brightness)
{
    int start {0} , end {0} , curPos {0} , ycrement {1};
    instructionParser(9,start,end,str);
    curPos=start;
    while(curPos<end)
    {
        if (v.at(curPos)>0){
            v.at(curPos)--;
            brightness--;
        }
        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            ycrement++;
            continue;
        }
        curPos+=1000;
    }
    if(v.at(end)>0){
        v.at(end)--;
        brightness--;
    }
}

void toggleRange (std::vector<int> &v , std::string &str , long long &brightness)
{
    int start {0} , end {0} , curPos {0} , ycrement {1};
    instructionParser(7,start,end,str);
    curPos=start;
    while(curPos<end)
    {
        toggle(v,curPos,brightness);
        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            ycrement++;
            continue;
        }
        curPos+=1000;
    }
    toggle(v,end,brightness);
}

void toggle (std::vector<int> &v , int &curPos , long long &brightness)
{
    v.at(curPos)+=2;
    brightness+=2;
}

//14686528 is wrong 14686611 634 is missing
//14687245 is the answer