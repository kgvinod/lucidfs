/**
 * @file   filefsnode.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A file node
 *
 * This class represents a file node that can support standard 
 * file operations such as open, write, read and close
 */
 
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
