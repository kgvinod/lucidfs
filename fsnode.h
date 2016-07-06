// A file system node
#ifndef FSNODE_H
#define FSNODE_H

#include <string>

class FsNode {
    public:
        FsNode() : size{0} {}
        ~FsNode();
    
    private:
        std::string name;
        int size;
};

#endif //#ifndef FSNODE_H
