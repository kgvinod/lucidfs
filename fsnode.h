// A file system node
#ifndef FSNODE_H
#define FSNODE_H

#include <string>
#include <iostream>

class FsNode {
    public:
        FsNode(std::string _name) : name{_name}, size{0} {}
        ~FsNode() {};
        virtual int getSize() {return size;}
        virtual void printNodes() {std::cout << getTypeStr() << " " << name << "\n";}
        std::string getName() {return name;}
        virtual std::string getTypeStr() = 0;
    
    //protected:
        std::string name;
        int size;
        int fd;
        FsNode *parent; 
};

#endif //#ifndef FSNODE_H
