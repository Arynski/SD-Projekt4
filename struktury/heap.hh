#ifndef HEAP_HH
#define HEAP_HH
#include "pair.hh"
#include "dynamic_array.hh"

//kopiec max (najwyzsza wartosc to RODZIC OSTATECZNY
class Heap {
private:
  DynamicArray<Pair> dane;
  void heapify_up(size_t i);
  void heapify_down(size_t i);
public:
  Heap() {}
  //wygodne
  Heap(std::initializer_list<Pair> lista) { build(lista); }
  void insert(Pair val);
  Pair extract_min();
  Pair& find_min();
  Pair* find(int val);
  //z poniższymi mam ten problem, że nie wiem jaki argument maja przyjmowac, rudy nie mowi -- indeks czy wartosc, klucz?
  //delete
  void decrease_key(int val, int i = 1);
  void increase_key(int val, int i = 1);
  void modify_key(int val, int k);
  //chyba po wartosciach:
  /*modify-key() – wciąż koszt O(n) (konieczność znalezienia węzła).
▶ Możemy dodatkowo przechowywać słownik mapujący indeks na węzeł.
▶ Koszt operacji spada do O(log n), ale stała wzrasta.
▶ Słownik oznacza konieczność dodatkowej pamięci.*/
  void build(DynamicArray<Pair>& tablica);
  void build(std::initializer_list<Pair> lista);
  size_t size() { return dane.size(); }

  void _show() { dane._show(); }
};

#endif
