// A link node has a pointer to another node
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
