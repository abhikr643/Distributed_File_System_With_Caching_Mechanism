#pragma once
#include "FileNode.hpp"
#include <unordered_map>
#include <mutex>

using namespace std;

class MetadataDB {
private:
    unordered_map<string, FileNode> fileMetadataMapping;
    mutex metadataMutex;

public:
    void storeFileMetadata(string fileName, FileNode fileNode);
    FileNode retrieveFileMetadata(string fileName);
};
