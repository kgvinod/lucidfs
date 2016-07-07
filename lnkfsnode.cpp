// Debug function to print all nodes recursively
#include "lnkfsnode.h"
#include <string>
#include <iostream>

void LnkFsNode::printNodes()
{
    std::string pstr;
    
    // Print name of this node
    std::cout << getTypeStr() << " " << getPath(pstr) << "->" + lnk->getPath(pstr) + "\n";
}
