/**
 * @file   main.cpp
 * @Author Vinod Gopalan (kgvinod@gmail.com)
 * @date   July, 2016
 * @brief  Test / demo application for lucidfs
 *
 * A simple filesystem to demonstrate use of C++ to create an object oriented
 * file system
 */

#include "lucidfs.h"
#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

void verify_result(FsNode *node, std::string name)
{
    if ((node != nullptr) && (node->getName() == name))
        std::cout << name << " node creation test : PASS \n";
    else
        std::cout << name << " node creation test : FAIL \n"; 
}

int main() 
{

    // Create filesystem with "/" as the root node
    LucidFS* lfs = new LucidFS();
    
    std::cout << "\nRun Tests : \n\n"; 
        
    std::string node_name = "/";
    DirFsNode* root_dir = lfs->init(node_name);
    verify_result(root_dir, node_name);       

    // Directory tests
    DirFsNode* home_dir = root_dir->mkdir(node_name = "home");
    verify_result(home_dir, node_name);       
        
    DirFsNode* etc_dir = root_dir->mkdir(node_name = "etc");
    verify_result(etc_dir, node_name);       
        
    DirFsNode* bin_dir = root_dir->mkdir(node_name = "bin");
    verify_result(bin_dir, node_name);       
        
    DirFsNode* usr_dir = root_dir->mkdir(node_name = "usr");
    verify_result(usr_dir, node_name);       
        
    DirFsNode* opt_dir = root_dir->mkdir(node_name = "opt");
    verify_result(opt_dir, node_name);           
    
    DirFsNode* doc_dir = home_dir->mkdir(node_name = "Documents");
    verify_result(doc_dir, node_name);           
        
    DirFsNode* vid_dir = home_dir->mkdir(node_name = "Videos");  
    verify_result(vid_dir, node_name);           
             
    DirFsNode* pic_dir = home_dir->mkdir(node_name = "Pictures"); 
    verify_result(pic_dir, node_name);           
    
    DirFsNode* usr_loc_dir = usr_dir->mkdir(node_name = "local");
    verify_result(usr_loc_dir, node_name);   
            
    DirFsNode* usr_lib_dir = usr_dir->mkdir(node_name = "lib");   
    verify_result(usr_lib_dir, node_name);       
    
    DirFsNode* usr_bin_dir = usr_dir->mkdir(node_name = "bin");  
    verify_result(usr_bin_dir, node_name);       
    
    // File tests   
    FileFsNode* file1 = doc_dir->fopen(node_name = "cover_letter.doc");
    verify_result(file1, node_name);       
        
    FileFsNode* file2 = pic_dir->fopen(node_name = "sunset.jpg");
    verify_result(file2, node_name);       
        
    FileFsNode* file3 = vid_dir->fopen(node_name = "movie.mp4");
    verify_result(file3, node_name);  
    
    // File write/read
    file1->write((const unsigned char*)"0123456789", 10);    
    file1->write((const unsigned char*)"0123456789", 10); 
    
    char *buffer = new char[30];
    file1->read((unsigned char*)buffer, 50, 200);                 
    
    // Duplicate node test
    DirFsNode* tmpDir = home_dir->mkdir(node_name = "Documents");
    std::cout << "Duplicate node test : " << ((tmpDir == nullptr)? "PASS" : "FAIL") << "\n";
        
    
    // Link tests
    LnkFsNode* lnk1 = home_dir->mklnk(node_name = "cover_letter", file1);  
    verify_result(lnk1, node_name);           
        
    LnkFsNode* lnk2 = home_dir->mklnk(node_name = "user_lib", usr_lib_dir);        
    verify_result(lnk2, node_name);           
        
    std::cout << "\nDirectory Tree Dump : \n\n"; 
    root_dir->printNodes();

    return 0;
}
