// Debug function to print all nodes recursively
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
