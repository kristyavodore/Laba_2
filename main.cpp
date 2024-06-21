#include <iostream>
#include <vector>
#include <cstring>

class bigint{
    int _sing;
    unsigned int * _digits;
    size_t _size;

    void clear(){
        delete[]_digits;
        _digits= nullptr;
        _size=0;
        _sing=0;
    }

    void copy(bigint const & other_obj){
        _sing = other_obj._sing;
        _size = other_obj._size;
        _digits=new unsigned int [_size-1];
        std::memcpy(_digits, other_obj._digits,  (_size-1)* sizeof(unsigned int));
    }

public:
    bigint():_sing(0), _digits(nullptr), _size(0){};

    bigint(int *arr, size_t size): bigint(){
        if (size==1){
            _sing=arr[size-1];
            _size=1;
        }
        else{
            _sing=arr[size-1];
            _digits=new unsigned int [size-1];
            std::memcpy(_digits, arr,  (size-1)* sizeof(unsigned int));
            /*for (int i=0; i<_size-1; i++){
                _digits[i]= arr[i];
            }*/
            _size=size;
        }
        std::cout<< "constr"<<std::endl;
    };

    bigint(std::vector<int> vec_bigint): bigint(){};
    bigint(std::string str): bigint(){};

    bigint(bigint const & other_obj){
           copy(other_obj);// конструктор копирования
           std::cout<<"copy constr";
    }

    ~bigint(){
        clear();
        std::cout<< "destr"<<std::endl;// деструктор
    }

    bigint &operator=(bigint const & other_obj){ //оператор присваивания
        if (this != &other_obj){
            clear();
            copy(other_obj);
        }
        return *this;
    }

    friend void print(bigint const & obj){
        for (int i=0; i<obj._size-1; i++)
            std::cout << obj._digits[i]<<" ";
        std::cout << obj._sing << " " << "Size of massive: " << obj._size <<std::endl;
    }

    size_t get_size(){return _size;}

    unsigned int get_digit(int index)const{ // получаем цифры по индексу
        if (_size==1){
            return index==0? _sing : 0;
        }
        if (index<_size-1){
            return _digits[index];
        }
        if (index == _size - 1)
            return _sing;
        return 0;
    }


};



int main() {
    int massive[5]={5, 4, 3, 2, 1};
    bigint n(massive, 5);
    print(n);
    std::cout << n.get_digit(0) << std::endl;

    //std::cout <<  << std::endl;
    return 0;
}
