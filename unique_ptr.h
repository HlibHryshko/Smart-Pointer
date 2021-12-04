//
// Created by glebg on 04.12.2021.
//

#ifndef SMART_POINTER_UNIQUE_PTR_H
#define SMART_POINTER_UNIQUE_PTR_H

// making class generic
template <typename T>
class unique_ptr {
public:

    // constructor
    explicit unique_ptr(T* ptr = nullptr) noexcept:
        m_ptr{ptr}{}

    // deleting copy constructor and assignment operator
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // const overloaded function, which returns the pointer
    T* get() const{
        return m_ptr;
    }
    T* get() {
        return m_ptr;
    }

    // function reset, which sets pointer to the given pointer, default = nullptr
    void reset(T* ptr = nullptr){
        T* tmp = m_ptr;
        m_ptr = ptr;
        delete tmp;
    }

    // function release, which sets pointer to zero and returns its previous value
    T* release(){
        T* tmp = m_ptr;
        m_ptr = nullptr;
        return tmp;
    }

    // bool operators
    explicit operator bool() const{
        return m_ptr != nullptr;
    }
    bool operator !() const{
        return m_ptr == nullptr;
    }

    // dereference operator
    T& operator*() const{
        return *m_ptr;
    }

    //operator that returns the ptr
    T* operator->() const{
        return m_ptr;
    }

    // function swap that swaps pointers
    friend inline void swap(unique_ptr& a, unique_ptr& b){
        auto tmp{a.m_ptr};
        a.m_ptr = b.m_ptr;
        b.m_ptr = tmp;
    }

    // destructor that just deletes m_ptr
    ~unique_ptr() noexcept{
        delete m_ptr;
    }
private:
    T* m_ptr;
};

// function for creating unique_ptr with nothing in it
template <typename T>
unique_ptr<T> make_unique(){
    return unique_ptr<T>(new T);
}

// function for creating unique_ptr with pointer to argument, passed by reference
template <typename T>
unique_ptr<T> make_unique(const T& arg){
    return unique_ptr<T>(new T(arg));
}

#endif //SMART_POINTER_UNIQUE_PTR_H
