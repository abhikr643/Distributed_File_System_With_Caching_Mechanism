#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    size_t capacity;

    class doublyLinkedList {
    public:
        string fileName;
        string fileContent;
        doublyLinkedList* prev;
        doublyLinkedList* next;

        doublyLinkedList(string f_Name, string f_Content);
    };

    unordered_map<string, doublyLinkedList*> cacheList;
    doublyLinkedList* head;
    doublyLinkedList* tail;

    void deleteNode(doublyLinkedList* root);
    void addNode(doublyLinkedList* root);

public:
    LRUCache(int cap);
    string getFile(string file_Name);
    void addFile(string file_Name, string file_Content);
};
