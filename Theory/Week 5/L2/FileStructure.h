#pragma once
#include <string>
#include <vector>

class systemElement {
protected:
    std::string name;
    char* date;
    float size;

    virtual void display() = 0;
    virtual ~systemElement();
};

struct innerFiles;

struct innerFolders;

class systemFile : public systemElement {
    int type;
public:
    systemFile(std::string name, char date[10], float size);
    void display();
};

class systemFolder : public systemElement {
    int number_of_files;
    innerFiles files;
    innerFolders folders;
public:
    systemFolder(std::string name, char date[10], float size);
    void inputFile(systemFile file);
    void inputFolder(systemFolder folder);
    void display();
};

struct innerFiles {
    std::vector<systemFile> files;
    float total_size;

    void addFile(systemFile file);
    void display();
};

struct innerFolders {
    std::vector<systemFolder> folders;
    float total_size;

    void addFolder(systemFolder folder);
    void display();
};