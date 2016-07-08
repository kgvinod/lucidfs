/**
 * @file   dirfsnode.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A directory node
 *
 * This class represents a directory node that can contain a collection of 
 * sub nodes, which in turn can be a directory, file or a link
 */
 
#ifndef DIRFSNODE_H
#define DIRFSNODE_H

#include <vector>
#include <string>
#include "fsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

class DirFsNode : public FsNode {

    public:
        DirFsNode(std::string _name) : FsNode{_name} {};
        ~DirFsNode();
        
        // Add a directory
        DirFsNode * mkdir(std::string new_dir);
        
        // Add a file
        FileFsNode * fopen(std::string new_file);
        
        // Create a link to another node
        LnkFsNode * mklnk(std::string new_file, FsNode *node);
        
        // Return the first node in the directory
        FsNode * getFirstNode() {return nodeList.empty()?nullptr:nodeList[0];}
        
        // Given a sub-node, get the next sub-node
        FsNode* getNextChildNode(FsNode*);
        
        // Print all nodes
        void printNodes();
        
        // Get the type of node
        std::string getTypeStr() {return "-d-";}
        

                
    private:    
    
        // Private methods
        bool isNodeExist(std::string node_name);
        
        // Get a node, given the name
        FsNode* getNode(std::string node_name);   
    
        // Private variables
        // Vector for child nodes
        std::vector<FsNode *> nodeList;

};

#endif
