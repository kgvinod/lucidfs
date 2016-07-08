/**
 * @file   filefsnode.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A file node
 *
 * This class represents a file node that can support standard 
 * file operations such as open, write, read and close
 */
 
#include "filefsnode.h"
#include <string>
#include <iostream>

void FileFsNode::printNodes()
{
    std::string pstr;
    
    // Print name of this node
    std::cout << getTypeStr() << " " << getPath(pstr) << "\n";
}

int write(const char * data)
{

    return 0;


}


int read(char *data, int offset, int count)
{

    return 0;

}
