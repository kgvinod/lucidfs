/**
 * @file   lnkfsnode.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A link node
 *
 * This class represents a link node that links to another 
 * directory node or file node
 */
 
#include "lnkfsnode.h"
#include <string>
#include <iostream>

void LnkFsNode::printNodes()
{
    std::string pstr;
    
    // Print name of this node
    std::cout << getTypeStr() << " " << getPath(pstr) << "->" + lnk->getPath(pstr) + "\n";
}
