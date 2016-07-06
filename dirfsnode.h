// A directory node has a collection of nodes
#ifndef DIRFSNODE_H
#define DIRFSNODE_H

#include <vector>
#include "fsnode.h"

class DirFsNode : public FsNode {

    public:
        DirFsNode();
        ~DirFsNode();
        
    private:    
        std::vector<FsNode> nodeList;
};

#endif
