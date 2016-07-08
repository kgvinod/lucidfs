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
        
        // Append data of size sz to the file 
        int write(const unsigned char * data, int sz);
        
        // Read count bytes from the file starting from offset to data buffer
        int read(unsigned char *data, int offset, int count);
        
        // Get the type string - for debug
        std::string getTypeStr() {return "-f-";}
        
        // Print node recursively
        void printNodes();
        
        
    private:    
        std::vector<FsBlock *> buffer;
};

#endif
