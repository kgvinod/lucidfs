# lucidfs
A simple file system in C++

### Description

A basic file system supporting file nodes, directory nodes and link nodes. A node has a name and size.
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

### How to compile and run

#### Requirements : 
- Ubuntu 14.04 LTS  
- g++ compiler with c++11 support.
Can be built for other platforms, but the code is verified in the above setup only.

#### Compiling and running
Just run make from the project folder
```
make
```
The make command produces an executable `lucidfstest`. To run the executable:
```
./lucidfstest
```
To clean, run :
```
make clean
```

#### output of executable
The executable runs a set of unit tests and shows the test results. Then it dumps the complete directory tree to stdout.
Sample output:
```
-d- /
-d- //home
-d- //home/Documents
-f- //home/Documents/cover_letter.doc
-d- //home/Videos
-f- //home/Videos/movie.mp4
-d- //home/Pictures
-f- //home/Pictures/sunset.jpg
-l- //home/cover_letter->//home/Documents/cover_letter.doc
-l- //home/user_lib->//usr/lib
-d- //etc
-d- //bin
-d- //usr
```
Notes:
-d- : directory
-f- : file
-l- link

The test sets the root directory as "/", which appears as the first "/" in each line of the tree dump.

### Assumptions and design choices
