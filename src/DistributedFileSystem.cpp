#include "../include/DistributedFileSystem.hpp"
#include <mutex>

DistributedFileSystem::DistributedFileSystem(int cacheSize) : cacheData(cacheSize) {}

void DistributedFileSystem::createFile(string fileName, string fileContent) {
    lock_guard<mutex> lock(file_System_Mutex);

    FileNode newFile(fileName, fileContent);
    for (int i = 0; i < 5 && i < nodeCount; ++i) {
        newFile.nodeIndices.insert(i);
    }

    fileNodes.push_back(newFile);
    metadataDB.storeFileMetadata(fileName, newFile);
    cacheData.addFile(fileName, fileContent);
}

string DistributedFileSystem::readFile(string fileName) {
    lock_guard<mutex> lock(file_System_Mutex);

    string cached = cacheData.getFile(fileName);
    if (!cached.empty()) return cached;

    FileNode fileNode;
    try {
        fileNode = metadataDB.retrieveFileMetadata(fileName);
    } catch (const runtime_error& e) {
        return e.what();
    }

    for (int idx : fileNode.nodeIndices) {
        if (failedNodes.find(idx) == failedNodes.end()) {
            cacheData.addFile(fileName, fileNode.fileContent);
            return fileNode.fileContent;
        }
    }

    return "Error: All replicas are unavailable";
}

void DistributedFileSystem::failNode(int nodeIdx) {
    lock_guard<mutex> lock(file_System_Mutex);
    failedNodes.insert(nodeIdx);
    cout << "Node " << nodeIdx << " has failed." << endl;
}

mutex printMutex;
void DistributedFileSystem::simulateFileRequests() {
    vector<thread> threads;
    for (int i = 0; i < 8; ++i) {
        threads.emplace_back([this, i]() {
            string fileName = "file" + to_string(i);
            string content = readFile(fileName);
            lock_guard<mutex> lock(printMutex);
            cout << "Thread " << i << " accessed file_Name-" << fileName << " : " << content << endl << endl;
        });
    }

    for (auto& t : threads) 
        t.join();
}
