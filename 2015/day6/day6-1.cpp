#include <iostream>
#include <fstream>
#include <vector> //test
#include <string>

void initAllLights (std::vector<bool> &v);
void turnOnRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn);
void turnOffRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn);
void toggleRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn);
void toggle (std::vector<bool> &v , int &curPos , int &lightsTurnedOn);
void instructionParser (int pos , int &start , int &end , std::string &str);

int main(){
    int lightsOn{0};
    std::string instruction {};
    std::ifstream f("day6.txt");
    std::vector<bool> allLights {};
    initAllLights(allLights);

    while(f.peek()!=EOF)
    {
        std::getline(f,instruction);
        if (instruction.find("turn on") != std::string::npos)
        {
            turnOnRange(allLights , instruction , lightsOn);
        }
        else if (instruction.find("turn off") != std::string::npos)
        {
            turnOffRange(allLights , instruction , lightsOn);
        }
        else if (instruction.find("toggle") != std::string::npos)
        {
            toggleRange(allLights , instruction , lightsOn);
        }
    }

    std::cout << lightsOn << std::endl;

    f.close();
    return 0;
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


void initAllLights (std::vector<bool> &v)
{
    for (int i {0} ; i<(1000*1000) ; i++){
        v.push_back(false);
    }
}

void turnOnRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn)
{
    int start {0} , end {0} , curPos {0} , ycrement {1};
    instructionParser(8,start,end,str);
    curPos=start;
    for(; curPos<end ; curPos+=1000)
    {
        if (!v.at(curPos))
        {
            v.at(curPos)=true;
            lightsTurnedOn++;
        }
        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            ycrement++;
            if (!v.at(curPos)){
                v.at(curPos)=true;
                lightsTurnedOn++;
            }
        }
    }
    if (!v.at(end))
    {
        v.at(end)=true;
        lightsTurnedOn++;
    }
}

void turnOffRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn)
{
    int start {0} , end {0} , curPos {0} , ycrement {1};
    instructionParser(9,start,end,str);
    curPos=start;
    for(; curPos<end ; curPos+=1000)
    {
        if (v.at(curPos))
        {
            v.at(curPos)=false;
            lightsTurnedOn--;
        }
        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            ycrement++;
            if (v.at(curPos)){
                v.at(curPos)=false;
                lightsTurnedOn--;
            }
        }
    }
    if (v.at(end))
    {
        v.at(end)=false;
        lightsTurnedOn--;
    }
}

void toggleRange (std::vector<bool> &v , std::string &str , int &lightsTurnedOn)
{
    int start {0} , end {0} , curPos {0} , ycrement {1};
    instructionParser(7,start,end,str);
    curPos=start;
    for(; curPos<end ; curPos+=1000)
    {
        toggle(v , curPos , lightsTurnedOn);

        if ((curPos/1000) == (end/1000))
        {
            curPos = start + (1*ycrement);
            toggle(v , curPos , lightsTurnedOn);
            ycrement++;
        }
    }
    if (v.at(end))
    {
        v.at(end)=false;
        lightsTurnedOn--;
    }
    else
    {
        v.at(end)=true;
        lightsTurnedOn++;
    }
}

void toggle (std::vector<bool> &v , int &curPos , int &lightsTurnedOn)
{
    if (v.at(curPos))
    {
        v.at(curPos)=false;
        lightsTurnedOn--;
    }
    else
    {
        v.at(curPos)=true;
        lightsTurnedOn++;
    }
}