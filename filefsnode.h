// A file node has a buffer that holds data
#ifndef FILEFSNODE_H
#define FILEFSNODE_H

#include "fsnode.h"

class FileFsNode : public FsNode {

    public:
        FileFsNode();
        ~FileFsNode();
        int write(const char * data);
        int read(char *data, int offset, int count);
        
        
    private:    
        char * buffer;
        int offset;
};

#endif
