template <typename T>
class ListItem {
public:
    T data;  
    ListItem* next;  

   
    ListItem(const T& value) : data(value), next(nullptr) {}

   
    ~ListItem() = default;
};