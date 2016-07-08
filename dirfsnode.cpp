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
        std::cout << __FUNCTION__ << " : " << node_name << " node already exists ! \n";
        return nullptr;
    }
     
    DirFsNode *dnode = new DirFsNode(node_name);
    dnode->setParent(this);

    nodeList.push_back(dnode);
    return dnode;
}
  
// Add a File
FileFsNode* DirFsNode::fopen(std::string node_name)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name)) {
        std::cout << __FUNCTION__ << " : " << node_name << " node already exists ! \n";
        
        // Return the node is it is a file node. Else return null.
        return dynamic_cast<FileFsNode *>(getNode(node_name));
    }
     
    FileFsNode *dnode = new FileFsNode(node_name);
    dnode->setParent(this);

    nodeList.push_back(dnode);
    return dnode;
}     
   
// Add a link
LnkFsNode* DirFsNode::mklnk(std::string node_name, FsNode *lnk)
{
    // Check if a node exists with the same name
    if (isNodeExist(node_name)) {
        std::cout << __FUNCTION__ << " : " << node_name << " node already exists ! \n";
        return nullptr;
    }
     
    LnkFsNode *dnode = new LnkFsNode(node_name, lnk);
    dnode->setParent(this);

    nodeList.push_back(dnode);
    return dnode;
}     

     
// Check if node already exists
bool DirFsNode::isNodeExist(std::string node_name)
{
    // Search for the node name in the directory node    
    auto it = std::find_if (nodeList.begin(), 
        nodeList.end(), [=](FsNode *node) { return (node->getName() == node_name);});        
    
    return (it != nodeList.end());
}   

// Check if node already exists
FsNode* DirFsNode::getNode(std::string node_name)
{
    // Search for the node name in the directory node    
    auto it = std::find_if (nodeList.begin(), 
        nodeList.end(), [=](FsNode *node) { return (node->getName() == node_name);});        
    
    return (it != nodeList.end())? *it : nullptr;
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

// Get the next adjacent child node
FsNode* DirFsNode::getNextChildNode(FsNode* _node)
{
    std::string node_name = _node->getName();
    
    // Search for the node name in the directory node    
    auto it = std::find_if (nodeList.begin(), 
        nodeList.end(), [=](FsNode *node) { return (node->getName() == node_name);}); 
        
    if(it == nodeList.end())
        return nullptr;
        
    return *std::next(it);         
      
}
