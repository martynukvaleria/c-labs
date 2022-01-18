//#include "Stack.h"
//
//template<typename T>
//Stack<T>::Stack(const Stack &rhs) {
//    if (rhs.elements_ == nullptr) {
//        Stack();
//        return;
//    }
//    size_ = rhs.size_;
//    capacity_ = rhs.capacity_;
//    elements_ = new T[capacity_];
//    for (int i = 0; i < size_; i++) {
//        elements_[i] = rhs.elements_[i];
//    }
//}
//
//template<typename T>
//Stack<T>::~Stack() {
//    clear();
//}
//
//template<typename T>
//T Stack<T>::pop() {
//    if (size_ == 0) {
//        throw std::underflow_error("Stack is empty");
//    }
//    T temp = elements_[size_ - 1];
//    size_--;
//    return temp;
//}
//
//template<typename T>
//void Stack<T>::push(T new_element) {
//    if (size_ + 1 > capacity_) {
//        reserve(std::max(capacity_ * 2, 1));
//    }
//    elements_[size_] = new_element;
//    size_++;
//}
//
//template<typename T>
//T &Stack<T>::top() {
//    assert(!empty());
//    return elements_[size_ - 1];
//}
//
//template<typename T>
//const T &Stack<T>::top() const {
//    assert(!empty());
//    return elements_[size_ - 1];
//}
//
//template<typename T>
//void Stack<T>::operator<<(T rhs) {
//    push(rhs);
//}
//
//template<typename T>
//Stack<T>& Stack<T>::operator>>(T &rhs) {
//    rhs = pop();
//    return *this;
//}
//
//template<typename T>
//Stack<T> &Stack<T>::operator=(const Stack &rhs) {
//    if (*this == rhs) { return *this; }
//    clear();
//    if (rhs.elements_ == nullptr) {
//        return *this;
//    }
//    size_ = rhs.size_;
//    capacity_ = rhs.capacity_;
//    elements_ = new T[capacity_];
//    for (int i = 0; i < size_; i++) {
//        elements_[i] = rhs.elements_[i];
//    }
//}
//
//template<typename T>
//bool Stack<T>::operator==(const Stack &rhs) const {
//    if (size_ != rhs.size_) { return false; }
//    for (int i = 0; i < size_; i++) {
//        if (elements_[i] != rhs.elements_[i]) { return false; }
//    }
//    return true;
//}
//
//template<typename T>
//bool Stack<T>::operator!=(const Stack<T> &rhs) {
//    //return             ?
//}
//
//template<typename T>
//bool Stack<T>::operator<(const Stack<T> &rhs) const {
//    bool result = (size_ < rhs.size_);
//    return result;
//}
//
//template<typename T>
//bool Stack<T>::operator>(const Stack<T> &rhs) const {
//    bool result = (size_ > rhs.size_);
//    return result;
//}
//
//template<typename T>
//int Stack<T>::size() {
//    return size_;
//}
//
//template<typename T>
//bool Stack<T>::empty() {
//    return size_ == 0;
//}
//
//template<typename T>
//T Stack<T>::operator[](int i) {
//    return elements_[i];
//}
//
//template<typename T>
//void Stack<T>::clear() {
//    delete[] elements_;
//    elements_ = nullptr;
//    size_ = 0;
//    capacity_ = 0;
//}
//
//template<typename T>
//void Stack<T>::reserve(int new_capacity) {
//    T *new_elements = new T[new_capacity];
//    for (int i = 0; i < size_; i++) {
//        new_elements[i] = elements_[i];
//    }
//    capacity_ = new_capacity;
//    delete[] elements_;
//    elements_ = new_elements;
//}
//
