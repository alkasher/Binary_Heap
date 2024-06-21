#include <iostream>
#include <vector>

template <class T>
class Heap {
private:
    std::vector<T> a;
    int len;
public:
    Heap<T>(const T* b, int len) : len(len) {
        if (len < 0) throw 'e';
        for (int i = 0; i < len; ++i) {
            a.push_back(b[i]);
        }
    }
    Heap<T>(const std::vector<T> b, int len) : len(len) {
        if (len < 0) throw 'e';
        for (int i = 0; i < len; ++i) {
            a.push_back(b[i]);
        }
    }

    Heap<T>() : len(0) {}
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
        a.push_back(elem);
        ++len;
        SiftUp(len - 1);
    }

    void DecreaseKey(const int position, const T delta) {
        if (delta < 0) throw 'e';
        a[position] -= delta;
        SiftUp(position);
    }
};

template <class T>
Heap<T> heapify(const std::vector<T>& vect) {
    Heap<T> h(vect,vect.size());
    for (int i = vect.size() - 1; i >= 0; --i) {
        h.SiftDown(i);
    }
    return h;
}

template <class T>
void HeapSort(std::vector<T>& vect) {
    Heap<T> h = heapify(vect);
    for (int i = 0; i < vect.size(); ++i) {
        vect[i] = h.getMin();
        h.ExtractMin();
    }
}

int main()
{
    int n = 14;
    std::vector<int> vect;
    for (int i = 0; i < n; ++i) {
        vect.push_back(i * (i + 3) * (-5 + i) + std::log10(i + 2) - std::pow(0.5, i));
    }
    for (auto x : vect) std::cout << x << " ";
    std::cout << '\n';
    HeapSort(vect);
    for (auto x : vect) std::cout << x << " ";
}
