#include "listItem.cpp"
#include <istream>
template <typename T>

class List {
private:
    ListItem<T>* head; 
    int length;  

public:
    
    List() : head(nullptr), length(0) {}

    
    ~List() {
        ListItem<T>* current = head;
        while (current != nullptr) {
            ListItem<T>* nextItem = current->next;
            delete current;
            current = nextItem;
        }
    }

 
    void add(const T& value) {
        ListItem<T>* newItem = new ListItem<T>(value);
        if (head == nullptr) {
            head = newItem;
        } else {
            ListItem<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newItem;
        }
        length++;
    }

    
    bool in(const T& value) const {
        ListItem<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

 
    void remove(const T& value) {
        ListItem<T>* current = head;
        ListItem<T>* previous = nullptr;
        
        while (current != nullptr && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            
            return;
        }

        if (previous == nullptr) {
            
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        length--;
    }

   
    int getLength() const {
        return length;
    }

  
    T& operator[](int index) {
        ListItem<T>* current = head;
        int i = 0;
        while (current != nullptr && i < index) {
            current = current->next;
            i++;
        }
        if (current != nullptr) {
            return current->data;
        } 
    }

   
    const T& operator[](int index) const {
        ListItem<T>* current = head;
        int i = 0;
        while (current != nullptr && i < index) {
            current = current->next;
            i++;
        }
        if (current != nullptr) {
            return current->data;
        } 
    }

 
    friend std::istream& operator>>(std::istream& is, List<T>& list) {
        T value;
        is >> value;
        list.add(value);
        return is;
    }

  
    friend std::ostream& operator<<(std::ostream& os, const List<T>& list) {
        ListItem<T>* current = list.head;
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};
