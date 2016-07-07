// A directory node has a collection of nodes
#include "dirfsnode.h"

// Add a directory
DirFsNode *DirFsNode::mkdir(std::string new_dir)
{
    // Check if a node exists with the same name
     
    DirFsNode *dnode = new DirFsNode(new_dir);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}
     
     
// Check if node already exists
FsNode* DirFsNode::isNodeExist(std::string node_name)
{

    return nullptr;
}   

