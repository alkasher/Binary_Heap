#include <iostream>
#include <vector>

template <class T>
void SiftUp(std::vector<T>& vect, int index, int& len) {
	if (index < 0 || index >= len) throw 'e';
	if (index == 0) return;
	int p = index / 2 - (index % 2 == 0);
	if (vect[index] >= vect[p]) return;
	std::swap(vect[p], vect[index]);
	SiftUp(vect, index, len);
}

template <class T>
void SiftDown(std::vector<T>& vect, int index, int& len) {
	if (index < 0) throw 'e';
	if (index >= len) return;
	int u = 2 * index + 1;
	if (u >= len) return;
	if (u + 1 < len)
		u = vect[u] < vect[u + 1] ? u : u + 1;
	if (vect[u] < vect[index]) {
		std::swap(vect[u], vect[index]);
		SiftDown(vect, u, len);
	}
}

template <class T>
void heapify(std::vector<T>& vect, int& len) {
	for (int i = len - 1; i >= 0; --i) {
		SiftDown(vect, i, len);
	}
}

template<class T>
void ExtractMin(std::vector<T>& vect, int& len) {
	//if (len == 0) throw 'e';
	std::cout << vect[0] << " ";
	std::swap(vect[0], vect[--len]);
	SiftDown(vect, 0, len);
}

template <class T>
void HeapSort(std::vector<T>& vect) {
	int len = vect.size();
	heapify(vect, len);

	for (int i = 0; i < vect.size(); ++i) {
		ExtractMin(vect, len);
	}
}

template <class T>
bool is_sorted(std::vector<T> vect) {
	for (int i = 1; i < vect.size(); ++i) {
		if (vect[i] < vect[i - 1]) return false;
	}
	return true;
}
/*
int main() {
	int n = 14;
	std::vector<int> vect;
	for (int i = 0; i < n; ++i) {
		vect.push_back(i * (i + 3) * (-5 + i) + std::log10(i + 2) - std::pow(0.5, i));
	}
	for (auto x : vect) std::cout << x << " ";
	std::cout << '\n';
	HeapSort(vect);

}*/