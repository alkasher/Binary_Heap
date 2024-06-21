#include <iostream>

template <class T>
class Heap {
private:
    T* a;
    int len;
public:
    Heap<T>(const T* a, int len) : len(len) {
        if (len < 0) throw 'e';
        if (!(this->a = new T[len])) throw 'e';
        for (int i = 0; i < len; ++i) {
            this->a[i] = a[i];
        }
    }
    T getMin() const {
        if (len == 0) throw 'e';
        return a[0];
    }
    void print() {
        
        for (int i = 0; i < len; ++i) {
                std::cout << a[i] << " ";
            } 
        std::cout << '\n';
    }
    void SiftUp(const int v) {
        if (v >= len || v < 0) throw 'e'; //index v out of a
        if (v == 0) return;
        int p = v / 2 - (v%2==0);
        if (a[v] < a[p]){ 
            std::swap(a[v], a[p]);
            SiftUp(p);
        }
    }
    void SiftDown(const int v) {
        int u = 0;
        if (2 * v +1 >= len) return;
        
        u = 2 * v+1;
        if (2 * v + 2 < len) {
            u = a[2 * v + 1] < a[2 * v + 2] ? 2 * v + 1: 2 * v + 2;
        }

        if (a[u] < a[v]) {
            std::swap(a[u], a[v]);
            SiftDown(u);
        }
    }

    void ExtractMin() {
        if (len == 0) throw 'e';
        std::swap(a[0], a[--len]);
        SiftDown(0);
    }

    void Insert(T elem) {
        T* b = new T[++len];
        for (int i = 0; i < len-1; ++i) {
            b[i] = a[i];
        }
        b[len - 1] = elem;
        delete[] a;
        a = new T[len];
        for (int i = 0; i < len; ++i) {
            a[i] = b[i];
        }
        delete[] b;
        SiftUp(len - 1);
    }

    void DecreaseKey(const int position, const T delta) {
        if (delta < 0) throw 'e';
        a[position] -= delta;
        SiftUp(position);
    }

    ~Heap() {
        delete[] a;
    }

};


int main()
{
    int n = 10;
    int* a = new int[n];
    for (int i = 0; i < 10; ++i) {
        a[i] = i;
    }
    
    Heap<int> l(a, 10);
}
