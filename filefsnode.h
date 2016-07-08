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
#include <vector>

class FileFsNode : public FsNode {

    public:
        FileFsNode(std::string _name) : FsNode{_name} {};
        ~FileFsNode();
        int write(const unsigned char * data, int size);
        int read(unsigned char *data, int offset, int count);
        std::string getTypeStr() {return "-f-";}
        void printNodes();
        
        
    private:    
        std::vector<FsBlock *> buffer;
        int offset;
};

#endif
