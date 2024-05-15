#include <stdexcept>
using namespace std;
template<class T>
class ArrayList {
	T* arr;
	int count;
	int size;
	void resize() {
		T* tmp = new T[size * 2];
		for (int i = 0; i < size; i++)
			tmp[i] = arr[i];
		delete[]arr;
		arr = tmp;
		size *= 2;
	}
	bool isfull() {
		return count == size;
	}
public:
	ArrayList() {
		size = 10;
		arr = new T[size];
		count = 0;
	}
	ArrayList(T size) {
		this->size = size;
		arr = new T[size];
		count = 0;
	}
	~ArrayList() {
		delete[]arr;
	}
	void Add(T item) {
		if (isfull())
			resize();
		arr[count++] = item;
	}
	int find(T item) {
		for (int i = 0; i < count; i++)
			if (arr[i] == item)
				return i;
		return -1;
	}
	void Delete(T item) {
		int idx = find(item);
		if (idx == -1)
			throw std::runtime_error("Runtime error");
		for (int i = idx; i < count - 1; i++)
			arr[i] = arr[i + 1];
		count--;
	}
	void Insert(int idx, T item) {
		if (isfull())
			resize();
		for (int i = count; i > idx; i--)
			arr[i] = arr[i - 1];
		arr[idx] = item;
		count++;
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= count)
			throw std::runtime_error("Runtime error");
		return arr[idx];
	}
	int GetCount() {
		return count;
	}
};