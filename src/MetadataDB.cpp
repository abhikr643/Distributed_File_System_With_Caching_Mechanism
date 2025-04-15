#include "../include/MetadataDB.hpp"
#include <stdexcept>

void MetadataDB::storeFileMetadata(string fileName, FileNode fileNode) {
    lock_guard<mutex> lock(metadataMutex);
    fileMetadataMapping[fileName] = fileNode;
}

FileNode MetadataDB::retrieveFileMetadata(string fileName) {
    lock_guard<mutex> lock(metadataMutex);
    if (fileMetadataMapping.find(fileName) == fileMetadataMapping.end()) {
        throw runtime_error("File not found in metadata");
    }
    return fileMetadataMapping[fileName];
}
