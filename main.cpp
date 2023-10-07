#include <iostream>
#include "file.h"
int main() {
    File file("./../test/a/b/c.txt");
    std::cout<<file.path()<<std::endl;
    std::cout<<file.dir()<<std::endl;
    File file2("./../test/a/b/1.txt");
    file2.create();
    //file.remove();
    file.copy("./../test/c2.txt");
    file2.rename("./../test/a/b/2.txt");
    std::cout<<file.exists()<<std::endl;
    //std::cout<<file.clear()<<std::endl;
    std::cout<<file.line()<<std::endl;
    std::cout<<file.size()<<std::endl;
    //std::cout<<file.read()<<std::endl;
    return 0;
}
