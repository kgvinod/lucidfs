// A directory node has a collection of nodes
#include "dirfsnode.h"
#include <iostream>

// Add a directory
DirFsNode* DirFsNode::mkdir(std::string node_name)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name))
        return nullptr;
     
    DirFsNode *dnode = new DirFsNode(node_name);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}
  
// Add a File
FileFsNode* DirFsNode::fopen(std::string node_name)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name))
        return nullptr;
     
    FileFsNode *dnode = new FileFsNode(node_name);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}     
     
// Check if node already exists
FsNode* DirFsNode::isNodeExist(std::string node_name)
{
    return nullptr;
}   

// Debug function to print all nodes recursively
void DirFsNode::printNodes()
{
    // Print name of this node
    std::cout << getTypeStr() << " " << getName() << "\n";
        
    // Print sub-nodes recursively    
    for (FsNode* x : nodeList) {
        x->printNodes();
    }
}
