// A file system node
#include "fsnode.h"
#include <string>

std::string& FsNode::getPath(std::string& str) 
{        
    if (parent == nullptr)
        return (str = getName());
    
    return (str = parent->getPath(str) + "/" + getName());  
    
}

