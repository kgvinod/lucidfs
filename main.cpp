#include "lucidfs.h"
#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

int main() 
{

    // Create filesystem with "/" as the root node
    LucidFS* lfs = new LucidFS();
    DirFsNode* root_dir = lfs->init("/");

    // Directory tests
    DirFsNode* home_dir = root_dir->mkdir("home");
    DirFsNode* etc_dir = root_dir->mkdir("etc");
    DirFsNode* bin_dir = root_dir->mkdir("bin");
    DirFsNode* usr_dir = root_dir->mkdir("usr");
    DirFsNode* opt_dir = root_dir->mkdir("opt");
    
    DirFsNode* doc_dir = home_dir->mkdir("Documents");
    DirFsNode* vid_dir = home_dir->mkdir("Videos");       
    DirFsNode* pic_dir = home_dir->mkdir("Pictures"); 

    DirFsNode* usr_loc_dir = usr_dir->mkdir("local");
    DirFsNode* usr_lib_dir = usr_dir->mkdir("lib");       
    DirFsNode* usr_bin_dir = usr_dir->mkdir("bin");  
    
    // File tests   
    FileFsNode* file1 = doc_dir->fopen("cover_letter.doc");
    FileFsNode* file2 = pic_dir->fopen("sunset.jpg");
    FileFsNode* file3 = vid_dir->fopen("movie.mp4");
    
    // Link tests
    LnkFsNode* lnk1 = home_dir->mklnk("cover_letter", file1);  
    LnkFsNode* lnk2 = home_dir->mklnk("user_lib", usr_lib_dir);        
     
    root_dir->printNodes();

    return 0;
}
