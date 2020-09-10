#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

int main(int argc, char** argv){
    std::string str;

    for(int j=0; j<2; j++){
        getline(std::cin, str);
        for(int i=0; i<256; i++){
            char c = str[i];
            if(c==0) break;
            if(c>=97 && c<=122){
                str[i] = c - 32;
            }
        }
        printf("%s\n", str.c_str());
    }

    return 0;
}