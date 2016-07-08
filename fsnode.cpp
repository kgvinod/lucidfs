/**
 * @file   fsnode.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A file system node
 *
 * This class represents the base filesystem node. 
 * Specialized nodes (dir, file, link) are derived from the bae node
 */
 
#include "fsnode.h"
#include <string>

std::string& FsNode::getPath(std::string& str) 
{        
    if (parent == nullptr)
        return (str = getName());
    
    return (str = parent->getPath(str) + "/" + getName());  
    
}

