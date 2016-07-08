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
#include <string.h>


void FileFsNode::printNodes()
{
    std::string pstr;
    
    // Print name of this node
    std::cout << getTypeStr() << " " << getPath(pstr) << "\n";
}

int FileFsNode::write(const unsigned char * data, int size)
{
    // First fill any remaining space in the last block
    if (!buffer.empty()) {
    
        FsBlock *block = buffer.back();
        if (block->size < BLOCK_SZ) {
            
            int space_avail = BLOCK_SZ - block->size;
            int write_sz = (size <= space_avail)? size : space_avail;
            std::cout << __FUNCTION__ << " : Filling " << write_sz << " bytes \n";        
                
            memcpy((void*)(block->data + block->size), 
                (const void*)data, write_sz);  
            
            data += write_sz;
            size -= write_sz;   
            
            setSize(getSize() + write_sz);                   
        }
    }
    
    // Create and fill new blocks
    for (int i=0; i<size/BLOCK_SZ + 1; i++) {
    
        FsBlock *block = new FsBlock;
        
        unsigned long start_offset = (unsigned long)data + i*BLOCK_SZ;
        int sz_to_copy = (i==size/BLOCK_SZ)? size % BLOCK_SZ : BLOCK_SZ;
        
        std::cout << __FUNCTION__ << " : " << getSize() << " " << sz_to_copy << "\n";        
        
        memcpy((void*)block->data, (const void*)start_offset, sz_to_copy);
        
        block->size = sz_to_copy;
        buffer.push_back(block); 
        
        setSize(getSize() + sz_to_copy);                   
    }
    
    std::cout << __FUNCTION__ << " : Total size " << getSize() << " bytes \n";            
    return size;
}


int FileFsNode::read(unsigned char *data, int offset, int count)
{
    // Error check : offset out of bounds
    if (offset >= getSize())
        return 0;
        
    // Adjust if offset+count out of bounds
    if ((offset + count) >= getSize())
        count = getSize() - offset;      
      
    // Find the starting/ending blocks
    int start_idx = offset/BLOCK_SZ;
    int end_idx = (offset + count)/BLOCK_SZ; 
    
    int write_offset = 0;
    for (int i=start_idx; i<=end_idx; i++) {
    
        int block_offset = (i==start_idx) ? offset % BLOCK_SZ : 0;
        int block_read_bytes = BLOCK_SZ;
        
        if ((i== start_idx) && (i == end_idx)) 
            block_read_bytes = count;
        else if (i==start_idx) 
            block_read_bytes -= offset % BLOCK_SZ;
        else if (i==end_idx) 
            block_read_bytes = (offset+count) % BLOCK_SZ;
        
        memcpy((void*)(data + write_offset), 
            (void *)(buffer[i]->data + block_offset), block_read_bytes);
            
        std::cout << __FUNCTION__ << " : Read " << block_read_bytes << " from block " << i << "\n";                      
            
        write_offset += block_read_bytes;
    }      
        
    return write_offset;

}
