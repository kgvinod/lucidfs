/**
 * @file   lucidfs.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A simple mock file system
 *
 * A simple filesystem to demonstrate use of C++ to create a object oriented
 * file system
 */

#include <vector>
#include <string>
#include "lucidfs.h"


// Initialize and create root node
DirFsNode * LucidFS::init(std::string root_path)
{

    return new DirFsNode(root_path);

}

