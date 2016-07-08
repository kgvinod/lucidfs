/**
 * @file   lnkfsnode.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A link node
 *
 * This class represents a link node that links to another 
 * directory node or file node
 */
 
#ifndef LNKFSNODE_H
#define LNKFSNODE_H

#include "fsnode.h"

class LnkFsNode : public FsNode {

    public:
        LnkFsNode(std::string _name, FsNode* _lnk) : FsNode{_name}, lnk{_lnk} {};
        ~LnkFsNode();
        std::string getTypeStr() {return "-l-";}
        void printNodes();
        
    private:    
        FsNode* lnk;
};

#endif
