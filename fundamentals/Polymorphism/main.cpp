#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    private:
        int count;
    public:
        LRUCache(int capacity);
        void set(int key, int value);
        int get(int key);
    
};

LRUCache :: LRUCache (int capacity)
{
    // capacitity will initialize the size of the cache.
    cp = capacity;
    count = 0;
    head = NULL;
    tail = NULL;
}

int LRUCache :: get(int key)
{
    Node* temp = head;
    
    if (mp.count(key) == 1)
    {
        for(int i = 0; i < cp; i ++)
        {
            
            if(temp->key == key) 
            {
                return mp[key]->value; 
            }
            temp = temp->prev;
        }
    }
    
        
    return -1;
}

void LRUCache :: set(int key, int value)
{
    Node *node = new Node (key,value);
    
    //Not in the map.
    
    if (head == NULL)
    {
        head = node;
        tail = node;
        mp.insert(mp.begin(),pair<int, Node*> (key,node));
        count++;
    }
    
    else if(mp.count(key) != 1)
    {
        node->next = tail;
        node->prev = head;
        head->next = node;
        
        //Node* current = new Node(head,tail,key,value);
        //mp.emplace(key,node);
        mp.insert(mp.begin(),pair<int, Node*> (key,node));
        head = head->next;
        count++;
    }
    
}

int main() {
    int n, capacity,i;
    string line;
    // Opening files to test.
    string fileTest []= {"test1.txt","test2.txt","test3.txt"};
    std::ifstream inputFile; 
    inputFile.open(fileTest[0]);
    while(!getline(inputFile,line).eof())
    {
        cin >> n >> capacity;
        LRUCache l(capacity);
        for(i=0;i<n;i++) 
        {
            string command;
            cin >> command;
            if(command == "get") 
            {
                int key;
                cin >> key;
                cout << l.get(key) << endl;
            } 
        else if(command == "set") 
        {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }

    }
    
   return 0;
}