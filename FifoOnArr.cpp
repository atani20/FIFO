#define MAX_SIZE 1000
using namespace std;

class FifoOnArr{
    int queue[MAX_SIZE];
    size_t _size;
    size_t head;
    size_t tail;
public:
    FifoOnArr(): _size(0), head(0), tail(0){};
    bool insert(int key);
    int remove();
    int headValue();
    size_t size();
    void clear();
    bool isEmpty();
};

bool FifoOnArr::isEmpty() {
    return _size == 0;
}

void FifoOnArr::clear() {
    _size = 0;
    head = 0;
    tail = 0;
}

int FifoOnArr::headValue() {
    if(_size == 0){
        return 0;
    }
    return queue[head];
}

int FifoOnArr::remove() {
    if(_size == 0){
        return 0;
    }
    int key = queue[head];
    _size--;
    head++;
    if(head >= MAX_SIZE){
        head = 0;
    }
    return key;
}

size_t FifoOnArr::size() { return _size;}

bool FifoOnArr::insert(int key) {
    if(_size == MAX_SIZE){
        return false;
    }
    queue[tail] = key;
    _size++;
    tail++;
    if(tail == MAX_SIZE){
        tail = 0;
    }
    return true;
}

