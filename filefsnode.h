// A file node has a buffer that holds data
#ifndef FILEFSNODE_H
#define FILEFSNODE_H

#include "fsnode.h"

class FileFsNode : public FsNode {

    public:
        FileFsNode(std::string _name) : FsNode{_name} {};
        ~FileFsNode();
        int write(const char * data);
        int read(char *data, int offset, int count);
        std::string getTypeStr() {return "-f-";}
        void printNodes();
        
        
    private:    
        char * buffer;
        int offset;
};

#endif
