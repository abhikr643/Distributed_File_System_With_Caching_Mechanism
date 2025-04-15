#pragma once
#include <vector>
#include <unordered_set>
#include <thread>
#include <iostream>
#include "LRUCache.hpp"
#include "MetadataDB.hpp"
#include "FileNode.hpp"

using namespace std;

class DistributedFileSystem {
private:
    vector<FileNode> fileNodes;
    LRUCache cacheData;
    MetadataDB metadataDB;
    mutex file_System_Mutex;
    int nodeCount = 8;
    unordered_set<int> failedNodes;

public:
    DistributedFileSystem(int cacheSize);
    void createFile(string fileName, string fileContent);
    string readFile(string fileName);
    void failNode(int nodeIdx);
    void simulateFileRequests();
};
