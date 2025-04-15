#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class FileNode {
public:
    string fileName;
    string fileContent;
    unordered_set<int> nodeIndices;

    FileNode(string name, string content);
    FileNode();
};
