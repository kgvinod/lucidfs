#include "lucidfs.h"
#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

void verify_result(FsNode *node, std::string name)
{
    if ((node != nullptr) && (node->getName() == name))
        std::cout << "** " << name << " creation test passed \n";
    else
        std::cout << "!! " << name << " creation test failed \n"; 
}

int main() 
{

    // Create filesystem with "/" as the root node
    LucidFS* lfs = new LucidFS();
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
    
    DirFsNode* usr_loc_dir = usr_dir->mkdir("local");
    DirFsNode* usr_lib_dir = usr_dir->mkdir("lib");       
    DirFsNode* usr_bin_dir = usr_dir->mkdir("bin");  
    
    // File tests   
    FileFsNode* file1 = doc_dir->fopen("cover_letter.doc");
    FileFsNode* file2 = pic_dir->fopen("sunset.jpg");
    FileFsNode* file3 = vid_dir->fopen("movie.mp4");
    
    // Duplicate node test
    FileFsNode* file4 = doc_dir->fopen("cover_letter.doc");
    if (file4 == nullptr) std::cout << "duplicate node test passed \n";
    
    // Link tests
    LnkFsNode* lnk1 = home_dir->mklnk("cover_letter", file1);  
    LnkFsNode* lnk2 = home_dir->mklnk("user_lib", usr_lib_dir);        
     
    root_dir->printNodes();

    return 0;
}
