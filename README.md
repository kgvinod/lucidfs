# lucidfs
A simple file system in C++

A basic file system supporting files nodes, directory nodes and link nodes. A node has a name and size.
- A file is a node with a buffer which holds data
- A directory is a node which has a collection of nodes
- A link is a node which has a pointer to another node

Supports the following operations::
- Add a directory within a directory
- Add a file within a directory
- Create a link to a node
- Return the size of a file
- Append data to a file
- Read n bytes of data from a file at an offset
- Given a directory return the first node in the directory
- Given a node in a directory return the next node in the directory
- List all nodes in a directory to stdout recursively
- Ability to create a root node for the filesystem


