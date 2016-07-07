// Lucid FileSystem

#include <vector>
#include <string>
#include "lucidfs.h"


// Initialize and create root node
DirFsNode * LucidFS::init(std::string root_path)
{

    return new DirFsNode(root_path);

}

