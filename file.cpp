#include "file.h"

File::File(std::string path) {
    this->pathstr = path;
}

std::string File::path() {
    return pathstr;
}

std::string File::dir() {
    //返回的目录路径不包含路径末尾的斜杠或反斜杠。
    //如果 path 是空字符串或不包含目录部分，dirname 函数将返回单个点字符.，表示当前目录。
    //如果 path 包含多个斜杠或反斜杠，dirname 函数将忽略除最后一个之外的所有斜杠，并提取最后一个斜杠之前的部分。
    std::string path = pathstr;
    if(path.size() == 0){
        return ".";
    }

    for(int i = path.size()-1; i > 0; i--){
        if(path[i] == '/'){
            path = path.substr(0,i);
            break;
        }
    }
    if(path.size() == 0)
        return "/";

    dirstr = path;
    return path;
}

bool File::create(){
    std::ofstream outputFile(pathstr);
    if(outputFile.is_open()){
        outputFile.close();
        return true;
    }
    else return 0;
}

bool File::remove(){
    if(exists() == false) {
        std::cout<<"文件不存在"<<std::endl;
        return false;
    }
    if(std::remove(pathstr.c_str()) == 0){
        return true;
    }
    return false;
}

bool File::copy(std::string path) {
    File copyfile(path);
    if(copyfile.create() == false) return false;
    std::ifstream sourceFile(this->pathstr,std::ios::binary);
    std::ifstream targetFile(path,std::ios::binary);
    char ch;
    while(sourceFile.get(ch)){
        targetFile.putback(ch);
    }
    sourceFile.close();
    targetFile.close();
    return true;
}

bool File::rename(std::string path) {
    //重命名
    if(std::rename(this->pathstr.c_str(),path.c_str()) == 0) {
        this->pathstr = path;
        return true;
    }
    return false;
}

bool File::exists() {
    std::ifstream file(pathstr);
    if(file.good())
        return true;
    return false;
}

bool File::clear() {
    std::fstream outputFile(this->pathstr,std::ios::trunc|std::ios::out);
    if(outputFile.is_open()) {
        outputFile.close();
        return true;
    }
    return false;
}
int File::line(){
    std::ifstream inputFile(pathstr);
    if(exists()== false){
        std::cout<<"文件不存在"<<std::endl;
        return 0;
    }
    if(!inputFile.is_open()){
        std::cout<<"无法打开文件"<<std::endl;
        return 0;
    }
    int linecnt = 0;
    std::string linestr;
    while(std::getline(inputFile,linestr)){
        linecnt++;
    }
    inputFile.close();
    return linecnt;
}

int File::size() {
    std::ifstream inputFile(pathstr);
    if(exists()== false){
        std::cout<<"文件不存在"<<std::endl;
        return 0;
    }
    if(!inputFile.is_open()){
        std::cout<<"无法打开文件"<<std::endl;
        return 0;
    }
    //会包含不可见字符（包括换行符、回车符等）
    inputFile.seekg(0, std::ios::end); // 将文件指针移到文件末尾
    std::streampos fileSize = inputFile.tellg(); // 获取文件指针的位置（文件大小）
    inputFile.close();
    return fileSize;
}

std::string File::read() {
    //打开文件部分也可以写一个函数
    std::ifstream inputFile(pathstr);
    if(exists()== false){
        std::cout<<"文件不存在"<<std::endl;
        return 0;
    }
    if(!inputFile.is_open()){
        std::cout<<"无法打开文件"<<std::endl;
        return 0;
    }
    std::string fileContent;
    std::string line;

    while (std::getline(inputFile, line)) {
        fileContent += line + "\n"; // 将每行内容添加到文件内容中，包括换行符
    }
    inputFile.close();
    return fileContent;
}
