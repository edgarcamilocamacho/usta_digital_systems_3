#include <iostream>

int main(int argc, char** argv){
    std::string name;

    std::cout << "Buenos días, ¿cómo te llamas?" << std::endl;
    getline(std::cin, name);

    std::cout << "Hola " << name << ", ¿cómo estás?" << std::endl;

    return 0;
}