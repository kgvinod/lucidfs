#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

int main() 
{

    // Directory tests
    DirFsNode* root_node = new DirFsNode("/");
    DirFsNode* home_node = root_node->mkdir("home");
    DirFsNode* etc_node = root_node->mkdir("etc");
    DirFsNode* bin_node = root_node->mkdir("bin");
    DirFsNode* usr_node = root_node->mkdir("usr");
    DirFsNode* opt_node = root_node->mkdir("opt");
    
    DirFsNode* doc_node = home_node->mkdir("Documents");
    DirFsNode* vid_node = home_node->mkdir("Videos");       
    DirFsNode* pic_node = home_node->mkdir("Pictures"); 

    DirFsNode* usr_loc_node = usr_node->mkdir("local");
    DirFsNode* usr_lib_node = usr_node->mkdir("lib");       
    DirFsNode* usr_bin_node = usr_node->mkdir("bin");  
    
    // File tests   
    FileFsNode* file1 = doc_node->fopen("cover_letter.doc");
     
    root_node->printNodes();

    return 0;
}
