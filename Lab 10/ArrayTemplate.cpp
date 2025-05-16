template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) {
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
        for (int i = 0; i < Capacity; ++i)
            List[i] = nullptr;
    }

    ~Array() {
        for (int i = 0; i < Size; ++i)
            delete List[i];
        delete[] List;
    }

    Array(const Array<T>& other) {
        Capacity = other.Capacity;
        Size = other.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; ++i)
            List[i] = new T(*other.List[i]);
    }

    T& operator[] (int index) {
        if (index < 0 || index >= Size)
            throw OutOfRangeException();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity)
            throw FullArrayException();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size || Size >= Capacity)
            throw OutOfRangeException();
        for (int i = Size; i > index; --i)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index > Size || Size + otherArray.Size > Capacity)
            throw OutOfRangeException();
        for (int i = Size - 1; i >= index; --i)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; ++i)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw OutOfRangeException();
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
            List[i] = List[i + 1];
        List[--Size] = nullptr;
        return *this;
    }

    bool operator=(const Array<T>& other) {
        if (this == &other)
            return true;

        for (int i = 0; i < Size; ++i)
            delete List[i];
        delete[] List;

        Capacity = other.Capacity;
        Size = other.Size;
        List = new T*[Capacity];
        for (int i = 0; i < Size; ++i)
            List[i] = new T(*other.List[i]);
        return true;
    }

    void Sort() {
        for (int i = 0; i < Size - 1; ++i)
            for (int j = i + 1; j < Size; ++j)
                if (*List[i] > *List[j])
                    swap(List[i], List[j]);
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; ++i)
            for (int j = i + 1; j < Size; ++j)
                if (compare(*List[i], *List[j]) > 0)
                    swap(List[i], List[j]);
    }

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; ++i)
            for (int j = i + 1; j < Size; ++j)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                    swap(List[i], List[j]);
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = compare(*List[mid], elem);
            if (cmp == 0)
                return mid;
            if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cmp = comparator->CompareElements(List[mid], (void*)&elem);
            if (cmp == 0)
                return mid;
            if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; ++i)
            if (*List[i] == elem)
                return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; ++i)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; ++i)
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(); }
};