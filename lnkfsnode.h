// A link node has a pointer to another node
#ifndef LNKFSNODE_H
#define LNKFSNODE_H

#include "fsnode.h"

class LnkFsNode : public FsNode {

    public:
        LnkFsNode();
        ~LnkFsNode();
        
    private:    
        FsNode * lnk;
};

#endif
