#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception {
    virtual const char* what() const throw() {
        return "Index is out of bounds!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current;
public:
    ArrayIterator() : List(nullptr), Current(0) {}
    ArrayIterator(T** list, int current) : List(list), Current(current) {}
    ArrayIterator<T>& operator ++ () {
        ++Current;
        return *this;
    }
    ArrayIterator<T>& operator -- () {
        --Current;
        return *this;
    }
    ArrayIterator<T> operator ++ (int val) {
        ArrayIterator<T> temp = *this;
        ++Current;
        return temp;
    }
    ArrayIterator<T> operator -- (int val) {
        ArrayIterator<T> temp = *this;
        --Current;
        return temp;
    }

    bool operator=(ArrayIterator<T>& other) {
        this->List = other.List;
        this->Current = other.Current;
        return true;
    }
    bool operator!=(ArrayIterator<T> other) {
        return this->Current != other.Current;
    }
    T* GetElement() {
        if (this->Current >= 0)
            return List[Current];
        return nullptr;
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() { // Lista nu e alocata, Capacity si Size = 0
        this->List = nullptr;
        this->Capacity = 0;
        this->Size = 0;
    }
    ~Array() { // destructor
        delete[] this->List;
    }
    Array(int capacity){ // Lista e alocata cu 'capacity' elemente
        this->Capacity = capacity;
        this->Size = 0;
        this->List = new T * [capacity];
    }
    Array(const Array<T>& otherArray) { // constructor de copiere
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        for (int i = 0; i < this->Size; i++)
            this->List[i] = new T(*otherArray.List[i]);
    }

    T& operator[] (int index){ // arunca exceptie daca index este out of range
        if (index < 0 || index >= this->Size)
            throw IndexOutOfBoundsException();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem){ // adauga un element de tipul T la sfarsitul listei si returneaza this
        if (this->Size >= this->Capacity) Resize(2*Capacity);
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index > this->Size)
            throw IndexOutOfBoundsException();
        if (Size >= Capacity) Resize(2 * Capacity);
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray){ // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index > this->Size)
            throw IndexOutOfBoundsException();
        if (Size + otherArray.Size >= Capacity) Resize(2*Capacity);
        for (int i = 0; i < otherArray.Size; ++i) {
            Insert(index + i, *otherArray.List[i]);
        }
        return *this;
    }
    const Array<T>& Delete(int index){ // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index >= this->Size)
            throw IndexOutOfBoundsException();
        delete List[index];
        for (int i = index; i < Size - 1; ++i) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;
        for (int i = 0; i < this->Size; i++)
            this->List[i] = new T(*otherArray.List[i]);
        return true;
    }

    void Sort(){ // sorteaza folosind comparatia intre elementele din T
        for(int i=0;i<Size-1;i++)
            for(int j=i+1;j<Size;j++)
                if (*List[i] > *List[j]) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
    }
    void Sort(int(*compare)(const T&, const T&)){ // sorteaza folosind o functie de comparatie
        for (int i = 0; i < Size - 1; ++i) {
            for (int j = i + 1; j < Size; ++j) {
                if (compare(*List[j], *List[i]) < 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }
    void Sort(Compare* comparator){ // sorteaza folosind un obiect de comparatie
        for (int i = 0; i < Size - 1; ++i) {
            for (int j = i + 1; j < Size; ++j) {
                if (comparator->CompareElements(*List[j], *List[i]) < 0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem){ // cauta un element folosind binary search in Array
        int left = 0, right = Size - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (*List[mid] == elem) return mid;
            else if (*List[mid] < elem) left = mid + 1;
            else right = mid - 1;
        }
        return -1;

    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)){//  cauta un element folosind binary search si o functie de comparatie
        int left = 0, right = Size - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (compare(elem, *List[mid])==0) return mid;
            else if (compare(elem, *List[mid]) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;

    }
    int BinarySearch(const T& elem, Compare* comparator){//  cauta un element folosind binary search si un comparator
        int left = 0, right = Size - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (comparator->CompareElements(elem, *List[mid]) == 0) return mid;
            else if (comparator->CompareElements(elem, *List[mid]) < 0) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem){ // cauta un element in Array
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem) return i;
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&)){//  cauta un element folosind o functie de comparatie
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem)==0) return i;
        return -1;
    }
    int Find(const T& elem, Compare* comparator){//  cauta un element folosind un comparator
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(*List[i], elem) == 0) return i;
        return -1;
    }

    int GetSize() {
        return this->Size;
    }
    int GetCapacity() {
        return this->Capacity;
    }
    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, 0);
    }
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size);
    }

    void Resize(int newCapacity) {
        T** newList = new T * [newCapacity];
        for (int i = 0; i < this->Size; i++) {
            newList[i] = this->List[i];
        }
        delete[] List;
        this->List = newList;
        this->Capacity = newCapacity;
    }
};


int main() {

    Array<int> arr(2);
    try {
        arr += 1;
        arr += 4;
        arr += 3;
        arr += 2;
        for (int i = 0; i < arr.GetSize(); i++)
            cout << arr[i] << ' ';
        cout << endl;
        arr.Sort();
        for (int i = 0; i < arr.GetSize(); i++)
            cout << arr[i] << ' ';
        cout << endl;
        arr.Insert(2, 10);
        for (int i = 0; i < arr.GetSize(); i++)
            cout << arr[i] << ' ';
        cout << endl;
        arr.Delete(2);
        for (int i = 0; i < arr.GetSize(); i++)
            cout << arr[i] << ' ';
        cout << endl;
        cout << "Array's capacity is " << arr.GetCapacity() << endl;
        for (ArrayIterator<int> it = arr.GetBeginIterator(); it != arr.GetEndIterator(); it++)
            cout << *(it.GetElement()) << ' ';
        cout << endl;
        cout << "Element 4 is found on position " << arr.Find(4) << endl;
        cout << "Using binary search, element 2 is found on position " << arr.BinarySearch(2) << endl;
    }
    catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        arr[10] = 5;
    }
    catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        arr.Insert(10, 2);
    }
    catch(exception& e){
        cout << "Exception: " << e.what() << endl;
    }
	return 0;
}