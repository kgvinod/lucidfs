// A file system node
#ifndef FSNODE_H
#define FSNODE_H

#include <string>

class FsNode {
    public:
        FsNode(std::string _name) : name{_name}, size{0} {}
        ~FsNode() {};
        int getSize() {return size;};
    
    private:
        std::string name;
        int size;
        int fd;
};

#endif //#ifndef FSNODE_H
