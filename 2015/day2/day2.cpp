#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> input (std::ifstream &f ); // converts lxwxh into three elements of a vector
int wrapReq(std::vector<int> dimensions);   // computes surface area, then adds area of smallest side
int ribbonReq(std::vector<int> dimensions); // takes two smallest sides and uses 2l+2b on it, then adds l*b*h

int main(){
    std::ifstream f("day2.txt");
    std::vector<int> dimensions {0,0,0};
    int sumwrap {0} , sumribbon{0};

    while(f.peek()!=EOF)
    {
        dimensions=input(f);
        sumwrap += wrapReq (dimensions);
        sumribbon += ribbonReq(dimensions);
    }

    std::cout << sumwrap << std::endl;
    std::cout << sumribbon << std::endl;
    f.close();
    return 0;
}

std::vector<int> input (std::ifstream &f ) // requires call by reference since it needs to look at the same ifstream obj
{
    std::vector<int> returnvect{0,0,0};
    std::string input{};
    int intovect {0} , i{0}; //i is for index in returnvect
    
    std::getline(f,input);

    for(auto iter {input.begin()} ; iter!=input.end() ; iter++) //iterator is used because we dont know the length of input
    {
        if ((*iter)=='x')
        {
            returnvect.at(i) = intovect;
            i++;
            intovect=0;
        }
        else{
            intovect = (intovect*10)+((*iter)-'0');
        }
    }
    returnvect.at(i) = intovect;



    return returnvect;
}


int wrapReq(std::vector<int> dimensions)
{

    std::vector<int> areas {dimensions.at(0)*dimensions.at(1) , dimensions.at(2)*dimensions.at(1) , dimensions.at(0)*dimensions.at(2)};
    int surfacearea {((2*areas.at(0)) + (2*areas.at(1)) + (2*areas.at(2))) + (*std::min_element(areas.begin(),areas.end()))};
    return surfacearea;
}

int ribbonReq(std::vector<int> dimensions) 
{
    sort(dimensions.begin(),dimensions.end());     // I am too lazy to create an algorithm that finds the smalles two
    int len {dimensions.at(0)}, bread{dimensions.at(1)};
    
    return ((2*len) + (2*bread) + (len * bread * dimensions.at(2)));
}

