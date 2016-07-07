// A directory node has a collection of nodes
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
        FsNode * getFirstNode() {return nodeList[0];}
        
        // Given a node in a directory return the 
        // next node in the directory
        FsNode * getNextNode(int fd);
        
        // Print all nodes
        void printNodes();
        
        // Get the type of node
        std::string getTypeStr() {return "-d-";}
        
        
    private:    
    
        // Private methods
        FsNode* isNodeExist(std::string node_name);
    
        // Private variables
        std::vector<FsNode *> nodeList;

};

#endif
