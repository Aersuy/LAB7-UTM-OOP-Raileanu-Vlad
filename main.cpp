#include "function.cpp"
#include <iostream>
#include "list.cpp"
int main()
{
    std::vector<int> lista = {0, 2, 3, 4, 3, 6};
    int param = 3;
    
    int rezultat = countAcour(lista, param);
    std::cout << "Parametrul " << param << " apare de " << rezultat << " ori in lista." << '\n';
    std::vector<char> alist = {'a','b','c','a'};
    char par = 'a';
    int res = countAcour(alist,par);
     std::cout << "Parametrul " << par << " apare de " << res << " ori in lista." << '\n';
   
     List<int> l;
     l.add(10);
     l.add(20);
     l.add(30);
   
     std::cout << l << '\n';


    return 0;
    
}