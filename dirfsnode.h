// A directory node has a collection of nodes
#ifndef DIRFSNODE_H
#define DIRFSNODE_H

#include <vector>
#include <string>
#include "fsnode.h"
#include "filefsnode.h"

class DirFsNode : public FsNode {

    public:
        DirFsNode();
        ~DirFsNode();
        
        // Make a directory
        DirFsNode & mkdir(std::string new_dir);
        FileFsNode & fopen(std::string new_file);
        FsNode & getFirstNode() {return nodeList[0];}
        FsNode & getNextNode(int fd);
        
    private:    
        std::vector<FsNode> nodeList;
};

#endif
