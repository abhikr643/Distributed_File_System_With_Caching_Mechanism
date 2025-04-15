#include "../include/LRUCache.hpp"

LRUCache::doublyLinkedList::doublyLinkedList(string f_Name, string f_Content) {
    fileName = f_Name;
    fileContent = f_Content;
    prev = nullptr;
    next = nullptr;
}

LRUCache::LRUCache(int cap) {
    capacity = cap;
    head = new doublyLinkedList("-1", "-1");
    tail = new doublyLinkedList("-1", "-1");
    head->next = tail;
    tail->prev = head;
}

void LRUCache::deleteNode(doublyLinkedList* root) {
    root->prev->next = root->next;
    root->next->prev = root->prev;
}

void LRUCache::addNode(doublyLinkedList* root) {
    root->next = head->next;
    root->prev = head;
    head->next->prev = root;
    head->next = root;
}

string LRUCache::getFile(string file_Name) {
    if (cacheList.find(file_Name) == cacheList.end()) return "";
    doublyLinkedList* curr = cacheList[file_Name];
    deleteNode(curr);
    addNode(curr);
    return curr->fileContent;
}

void LRUCache::addFile(string file_Name, string file_Content) {
    if (cacheList.find(file_Name) != cacheList.end()) {
        doublyLinkedList* curr = cacheList[file_Name];
        deleteNode(curr);
        addNode(curr);
        curr->fileContent = file_Content;
    } else {
        if (cacheList.size() == capacity) {
            doublyLinkedList* last = tail->prev;
            string key = last->fileName;
            deleteNode(last);
            cacheList.erase(key);
        }
        doublyLinkedList* newNode = new doublyLinkedList(file_Name, file_Content);
        cacheList[file_Name] = newNode;
        addNode(newNode);
    }
}
