#include "../include/fileNode.hpp"

FileNode::FileNode(string name, string content) 
    : fileName(name), fileContent(content) {}

FileNode::FileNode() : fileName(""), fileContent("") {}
