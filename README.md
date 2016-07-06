# lucidfs
A simple file system in C++

A basic file system supporting files nodes, directory nodes and link nodes. A node has a name and size.
-        A file is a node with a buffer which holds data
-        A directory is a node which has a collection of nodes
-        A link is a node which has a pointer to another node

1. Design a class hierarchy and implement the bare using the appropriate STL containers. 
2. Implement as many of the following methods as you can (plus any helper methods that you need):
-        Add a directory within a directory
-        Add a file within a directory
-        Create a link to a node
-        Return the size of a file
-        Append data to a file
-        Read n bytes of data from a file at an offset
-        Given a directory return the first node in the directory
-        Given a node in a directory return the next node in the directory
-        List all in a directory to stdout recursively
3. You should have the ability to create a root node for your filesystem


