/**
 * @file   fsnode.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A file system node
 *
 * This class represents the base filesystem node. 
 * Specialized nodes (dir, file, link) are derived from the base node
 */
 
#include "fsnode.h"
#include "dirfsnode.h"
#include <string>

std::string& FsNode::getPath(std::string& str) 
{        
    if (mpParent == nullptr)
        return (str = getName());
    
    return (str = mpParent->getPath(str) + "/" + getName());  
    
}

FsNode* FsNode::getNextNode()
{
    if (mpParent == nullptr)
        return (nullptr);
        
    // The parent node will be a directory node
    return dynamic_cast<DirFsNode*>(mpParent)->getNextChildNode(this);    
        
}
