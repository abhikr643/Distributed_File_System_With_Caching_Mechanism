#include "../include/DistributedFileSystem.hpp"

void setupDistributedFileSystem() {
    DistributedFileSystem dfs(3);
    dfs.createFile("file0", "This is file 0 content.");
    dfs.createFile("file1", "This is file 1 content.");
    dfs.createFile("file2", "This is file 2 content.");
    dfs.createFile("file3", "This is file 3 content.");
    dfs.createFile("file4", "This is file 4 content.");
    dfs.createFile("file5", "This is file 5 content.");

    dfs.failNode(1);
    dfs.failNode(3);

    cout << endl;
    dfs.simulateFileRequests();
}

int main() {
    setupDistributedFileSystem();
    return 0;
}
