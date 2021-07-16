#include "sortfactory.h"

#include <sort/catalog/bubblesort.h>
#include <sort/catalog/combsort.h>
#include <sort/catalog/insertionsort.h>
#include <sort/catalog/shakersort.h>
#include <sort/catalog/selectionsort.h>
#include <sort/catalog/quicksort.h>
#include <sort/catalog/heapsort.h>
#include <sort/catalog/gnomesort.h>

SortFactory::SortFactory() {

}

BaseSort* SortFactory::create(int key) {
    BaseSort* baseSort;

    // вот тут по ключу создаем сортировку
    if (key == 0) {
        baseSort = new BubbleSort();
    } else if (key == 1) {
        baseSort = new ShakerSort();
    } else if (key == 2) {
        baseSort = new CombSort();
    } else if (key == 3) {
        baseSort = new InsertionSort();
    } else if (key == 4) {
        baseSort = new SelectionSort();
    } else if (key == 5) {
        baseSort = new QuickSort();
    } else if (key == 6) {
        baseSort = new HeapSort();
    } else if (key == 7) {
        baseSort = new GnomeSort();
    }

    // дальше говорим сортировке по какому
    // ключу ее создали и передаем интерфейсу программы
    baseSort->setKey(key);
    return baseSort;
}

int SortFactory::getMaxKey() {
    // последняя цифра в условии -> if (key == вот эта)
    return 7;
}
