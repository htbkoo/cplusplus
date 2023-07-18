#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <limits>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <sstream>
#include <iostream> // includes cin to read from stdin and cout to write to stdout
using namespace std; // since cin and cout are both in namespace std, this saves some text

class DoublyLinkedListNode {
public:
    int _key;
    int _val;
    DoublyLinkedListNode* _prev = nullptr;
    DoublyLinkedListNode* _next = nullptr;

    DoublyLinkedListNode(int key = 0, int val = 0, DoublyLinkedListNode* prev = nullptr, DoublyLinkedListNode* next = nullptr) {
        _key = key;
        _val = val;
        _prev = prev;
        _next = next;
    }    
};

void printList(DoublyLinkedListNode* node) {
    while (node != nullptr) {
        cout << node->_key << " ";
        node = node->_next;
    }
    cout << endl;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = new DoublyLinkedListNode();
        tail = new DoublyLinkedListNode();
        head->_next = tail;
        tail->_prev = head;
        
        // TODO: what if capacity is 0?
        _capacity = capacity;
        _size = 0;
        mapping = unordered_map<int, DoublyLinkedListNode*>();
    }
    
    ~LRUCache() {
        // TODO do we need to delete all nodes?
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (mapping.count(key) == 0) {
            return -1;
        }
        
        DoublyLinkedListNode* node = mapping[key];
        int val = node->_val;
        
        moveToTail(node);
        
        return val;
    }
    
    void put(int key, int value) {
        if (mapping.count(key) == 0) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(key, value);

            moveToTail(node);
            
            mapping[key] = node;
                        
            if (_size < _capacity) {
                _size++;
            } else {
                DoublyLinkedListNode* toDiscard = head->_next;
                
                mapping.erase(toDiscard->_key);
                
                DoublyLinkedListNode* nextNode = toDiscard->_next;
                head->_next = nextNode;
                nextNode->_prev = head;
            }
        } else {
            DoublyLinkedListNode* node = mapping[key];
            node->_val = value;

            moveToTail(node);
        }
    }
    
private:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;
    int _capacity;
    int _size;
    unordered_map<int, DoublyLinkedListNode*> mapping;
    
    void moveToTail(DoublyLinkedListNode* node) {
        if (node->_prev != nullptr && node->_next != nullptr) {
            node->_prev->_next = node->_next;
            node->_next->_prev = node->_prev;
        }
        
        DoublyLinkedListNode* tailPrev = tail->_prev;
        
        tailPrev->_next = node;
        node->_prev = tailPrev;

        node->_next = tail;
        tail->_prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */ 

int main() {
    vector<string> cmd= {"LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"};
    vector<vector<int>> args= {{3},{1,1},{2,2},{3,3},{4,4},{4},{3},{2},{1},{5,5},{1},{2},{3},{4},{5}};

    LRUCache cache(args[0][0]);

    for (int i = 1; i < cmd.size(); ++i) {
        if (cmd[i] == "get") {
            cache.get(args[i][0]);
        } else if (cmd[i] == "put") {
            cache.put(args[i][0], args[i][1]);
        }
    }

    return 0;
}