#pragma once
#ifndef FS_FILE_H
#define FS_FILE_H
#include<iostream>
#include<fstream>
#include<cstdio>

class File {
public:
    File();
    File(std::string path);
    std::string path();//获取文件名
    std::string dir(); //获取文件所在目
    bool create();//创建文件
    bool remove();//删除文件
    bool copy(std::string path);//复制文件
    bool rename(std::string path);//文件重命名
    bool exists();//判断文件是否存在
    bool clear();//清空文件内容
    int line();//获取文件行数
    int size();//获取文件大小
    //time();//获取文件最后修改时间
    std::string read();//一次性读取文件全部内容
    std::string write(std::string content);//一次性写入文件，后续更新读写文件的细节
private:
    std::string pathstr;
    std::string dirstr;
};


#endif //FS_FILE_H
