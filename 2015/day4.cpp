#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <openssl/md5.h>


std::string md5(const std::string &str){
  unsigned char hash[MD5_DIGEST_LENGTH];

  MD5_CTX md5;
  MD5_Init(&md5);
  MD5_Update(&md5, str.c_str(), str.size());
  MD5_Final(hash, &md5);

  std::stringstream ss;

  for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
    ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>( hash[i] );
  }
  return ss.str();
}

int main() //IF THIS SHIT WORKED I COULD TEST IT
{
    std::string input {"abcdef"} , md5Hash{};
    for (long long i {0LL} ; i<=10000000 ; i++)
    {
        md5Hash=md5(input+std::to_string(i));
        if (md5Hash.find("00000")!=std::string::npos){
            std::cout<<i<<std::endl;
            break;
        }
    }
    return 0;
}