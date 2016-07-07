#include "fsnode.h"
#include "dirfsnode.h"
#include "filefsnode.h"
#include "lnkfsnode.h"

int main() 
{

    DirFsNode *root_node = new DirFsNode("/");
    DirFsNode *home_node = root_node->mkdir("home");

    return 0;
}
