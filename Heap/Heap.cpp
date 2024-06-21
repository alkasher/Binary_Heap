// Heap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

/* 
Куча представлена как массив, но надо держать в голове картинку в виде дерева,
где у каждого узла 2 ребенка и значение каждого узла не больше значения двух
его детей (простое следствие, минимальный по куче лежит в нулевом узле).
Например массив [0,1,2,3,4,5,6,7,8,9] есть куча
         0
    1         2
 3     4   5     6
7 8   9              
*/
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

    void printg() const {
        std::cout << "\n\n";
        int i = 0;
        int j = 0;
        while (j < len) {
            for (int k = 0; k < std::pow(2, i); ++k) {
                std::cout << a[j] << " ";
                if (++j >= len) break;
            }
            ++i;
            std::cout << '\n';
        }
    }

    void DecreaseKey(const int position, const T delta) {
        if (delta < 0) throw 'e';
        a[position] -= delta;
        SiftUp(position);
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
    //l.printg();
    l.ExtractMin();
    l.printg();
    l.Insert(0);
    l.printg();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
