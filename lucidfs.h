/**
 * @file   lucidfs.h
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  A simple mock file system
 *
 * A simple filesystem to demonstrate use of C++ to create a object oriented
 * file system
 */

#ifndef LUCIDFS_H
#define LUCIDFS_H

#include <vector>
#include <string>
#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

class LucidFS {

    public:
        LucidFS() {};
        ~LucidFS();
        
        // Initialize and create root node
        DirFsNode* init(std::string root_path);
        
    private:    
    
        // Private variables
        std::vector<FsNode *> open_files;

};

#endif
