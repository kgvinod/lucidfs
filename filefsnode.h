// A file node has a buffer that holds data
#ifndef FILEFSNODE_H
#define FILEFSNODE_H

#include "fsnode.h"

class FileFsNode : public FsNode {

    public:
        FileFsNode();
        ~FileFsNode();
        
    private:    
        char * buffer;
};

#endif
