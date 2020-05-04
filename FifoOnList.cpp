
struct fifoNode{
    fifoNode *next;
    int key;
};

class FifoOnList{
    size_t _size;
    fifoNode *head;
    fifoNode *tail;
public:
    FifoOnList(): _size(0), head(nullptr), tail(nullptr){};
    void insert(int key);
    bool remove(int &key);
    bool headValue(int &key);
    size_t size();
    void clear();
    bool isEmpty();
    ~FifoOnList();
};

FifoOnList:: ~FifoOnList(){
    if(_size){
        clear();
    }
}

size_t FifoOnList::size() {
    return _size;
}

void FifoOnList::clear() {
    fifoNode *curElem = head;
    fifoNode *prevElem;
    while(curElem){
        prevElem = curElem;
        curElem = curElem->next;
        delete(prevElem);
    }
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

bool FifoOnList::headValue(int &key) {
    if(_size == 0){
        return false;
    }
    key = head->key;
}

bool FifoOnList::remove(int &key) {
    if(_size == 0){
        return false;
    }
    key = head->key;
    _size --;
    fifoNode *removeElem = head;
    head = head->next;
    delete(removeElem);
    return true;
}

void FifoOnList::insert(int key) {
    if(_size == 0){
        auto *headNode = new fifoNode{nullptr, key};
        head = headNode;
        tail = headNode;
    }
    else{
        auto *newNode = new fifoNode{nullptr,key};
        tail->next = newNode;
        tail = newNode;
    }
    _size++;
}

bool FifoOnList::isEmpty() {
    return _size == 0;
}