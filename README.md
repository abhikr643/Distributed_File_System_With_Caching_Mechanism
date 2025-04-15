
# Distributed File System with Caching Mechanism

This project simulates a **Distributed File System** with an integrated **LRU Caching Mechanism**, built in C++. It supports basic file operations, metadata handling, and optimized file access using in-memory caching.

---

## 📁 Project Structure

```
Distributed_File_System_With_Caching_GITHUB_Version/
├── include/                  # Header files
├── src/                      # Source files
├── main.cpp                  # Entry point for the program
└── README.md                 # Project instructions
```

---

## 🛠️ How to Compile and Run

### ✅ Requirements

- C++ compiler with C++17 support (`g++`, `clang++`, MSVC)
- Windows: Install **MinGW** or similar and ensure `g++` is added to your PATH

---

### Steps (from the main project folder)

1. **Open PowerShell or Terminal**
2. **Navigate to the project folder**:
   ```powershell
   cd path\to\Distributed_File_System_With_Caching_Mechanism
   ```

3. **Compile the project**:
   ```powershell
   g++ -std=c++17 src\DistributedFileSystem.cpp src\fileNode.cpp src\LRUCache.cpp src\MetadataDB.cpp main.cpp -Iinclude -o dfs_runner.exe
   ```

4. **Run the executable**:
   ```powershell
   .\dfs_runner.exe
   ```

---
## Author
- **Name**: Abhishek Kumar
- **GitHub**: [abhikr643](https://github.com/abhikr643)