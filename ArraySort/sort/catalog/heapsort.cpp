#include "heapsort.h"
#include <QList>

HeapSort::HeapSort()
{
    // описание алгоритма
    this->title = "Пирамидальная сортировка";
    this->shortDescription = "При этой сортировке сначала строится пирамида из элементов исходного массива. Пирамида (или двоичная куча) — это способ представления элементов, при котором от каждого узла может отходить не больше двух ответвлений. А значение в родительском узле должно быть больше значений в его двух дочерних узлах.";
    this->description = "Развитие идеи сортировки выбором. Воспользуемся структурой данных «куча» (или «пирамида», откуда и название алгоритма). Она позволяет получать минимум за O(1), добавляя элементы и извлекая минимум за O(logn). Таким образом, асимптотика O(nlogn) в худшем, среднем и лучшем случае.";
    this->stepString = "O(n log n)";
    this->stepValue = "26"; // просто считаем эту фигню для 20 элементов. n^log n -> 20^1,3 = 26

    // шари алгоритма
    this->algoritm.append("1. Построение пирамиды. Определяем правую часть дерева, начиная с n/2-1 (нижний уровень дерева). Берем элемент левее этой части массива и просеиваем его сквозь пирамиду по пути, где находятся меньшие его элементы, которые одновременно поднимаются вверх; из двух возможных путей выбираете путь через меньший элемент.");
    this->algoritm.append("2. Сортировка на построенной пирамиде. Берем последний элемент массива в качестве текущего. Меняем верхний (наименьший) элемент массива и текущий местами. Текущий элемент (он теперь верхний) просеиваем сквозь n-1 элементную пирамиду. Затем берем предпоследний элемент и т.д.");

    // код алгоритма
    this->source =
            "std::make_heap(array.begin(), array.end());\n"
            "for (auto i = array.end(); i != array.begin(); --i) {\n"
            "   std::pop_heap(array.begin(), i);\n"
            "}"
            ;

    this->markers.append(COOL_MARKER);
    this->markers.append(SIMPLE_MARKER);
    this->markers.append(FUN_MARKER);

}

QList<QList<int>> HeapSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение
    steps.append(cloneArray(array));
    std::make_heap(array.begin(), array.end());
    for (auto i = array.end(); i != array.begin(); --i) {
        std::pop_heap(array.begin(), i);
        steps.append(cloneArray(array));
     }
    return steps;
}

