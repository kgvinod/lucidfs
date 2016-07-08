/**
 * @file   fsnode.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A file system node
 *
 * This class represents the base filesystem node. 
 * Specialized nodes (dir, file, link) are derived from the bae node
 */
 
#ifndef FSNODE_H
#define FSNODE_H

#include <string>
#include <iostream>

class FsNode {

    public:
    
        // Constructor and destructor 
        FsNode(std::string _name) : name{_name}, size{0}, parent{nullptr} {}
        ~FsNode() {};
        
        // Get name of the node (dir name, file name of link name).
        std::string getName() {return name;}
        
        // Get the size of the node
        int getSize() {return size;}
        
        // Print all the nodes recursively to stdout
        virtual void printNodes() = 0; 
        
        // Get the type string. 
        // -d- for directory
        // -f- for file
        // -l- for link
        virtual std::string getTypeStr() = 0;
        
        // Get the name of the node including the complete path
        // E.g. //home/Pictures/sunset.jpg
        std::string& getPath(std::string& str);
        
        // Get/Set parent node
        FsNode *getParent() {return parent;};
        void setParent(FsNode * _parent) {parent = _parent;};         
    
    private:
    
        std::string name;
        int size;
        FsNode *parent; 
};

#endif //#ifndef FSNODE_H
