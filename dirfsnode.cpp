/**
 * @file   dirfsnode.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A directory node
 *
 * This class represents a directory node that can contain a collection of 
 * sub nodes, which in turn can be a directory, file or a link
 */
 
#include "dirfsnode.h"
#include <iostream>
#include <algorithm>

// Add a directory
DirFsNode* DirFsNode::mkdir(std::string node_name)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name)) {
        std::cout << node_name << " already exists ! \n";
        return nullptr;
    }
     
    DirFsNode *dnode = new DirFsNode(node_name);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}
  
// Add a File
FileFsNode* DirFsNode::fopen(std::string node_name)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name)) {
        std::cout << node_name << " already exists ! \n";
        return nullptr;
    }
     
    FileFsNode *dnode = new FileFsNode(node_name);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}     
   
// Add a link
LnkFsNode* DirFsNode::mklnk(std::string node_name, FsNode *lnk)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name)) {
        std::cout << node_name << " already exists ! \n";
        return nullptr;
    }
     
    LnkFsNode *dnode = new LnkFsNode(node_name, lnk);
    dnode->parent = this;

    nodeList.push_back(dnode);
    return dnode;
}     

bool mybool(int i) {return true;}
     
// Check if node already exists
bool DirFsNode::isNodeExist(std::string node_name)
{
        
    auto it = std::find_if (nodeList.begin(), 
        nodeList.end(), [=](FsNode *node) { return (node->getName() == node_name);});        
    
    return (it != nodeList.end());
}   

// Debug function to print all nodes recursively
void DirFsNode::printNodes()
{

    std::string pstr;
    
    // Print name of this node
    std::cout << getTypeStr() << " " << getPath(pstr) << "\n";
        
    // Print sub-nodes recursively    
    for (FsNode* x : nodeList) {
        x->printNodes();
    }
}
