#include "selectionsort.h"
#include <QList>

SelectionSort::SelectionSort(){
    // описание алгоритма
    this->title = "Сортировка выбором";
    this->shortDescription = "Сортировка выбором (Selection sort) — алгоритм сортировки. Может быть как устойчивый, так и неустойчивый. На массиве из n элементов имеет время выполнения в худшем, среднем и лучшем случае Θ(n2), предполагая что сравнения делаются за постоянное время.";
    this->description = "На очередной итерации будем находить минимум в массиве после текущего элемента и менять его с ним, если надо. Таким образом, после i-ой итерации первые i элементов будут стоять на своих местах. Асимптотика: O(n2) в лучшем, среднем и худшем случае. Нужно отметить, что эту сортировку можно реализовать двумя способами – сохраняя минимум и его индекс или просто переставляя текущий элемент с рассматриваемым, если они стоят в неправильном порядке. Первый способ оказался немного быстрее, поэтому он и реализован.";
    this->stepString = "O(n^2)";
    this->stepValue = "400"; // просто считаем эту фигню для 20 элементов. n^2 -> 20x20 = 400

    // шари алгоритма
    this->algoritm.append("1. Находим номер минимального значения в текущем списке.");
    this->algoritm.append("2. Производим обмен этого значения со значением первой неотсортированной позиции (обмен не нужен, если минимальный элемент уже находится на данной позиции)");
    this->algoritm.append("3. Теперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы");

    // код алгоритма
    this->source =
            "  for (auto i = array.begin(); i != array.end(); ++i) {\n"
            "    auto j = std::min_element(i, array.end());\n"
            "    std::swap(*i, *j);\n"
            "}";

    this->nominations.append(SIMPLE_NOMINATION);
    this->nominations.append(SLOW_NOMINATION);
}

QList<QList<int>> SelectionSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    // добавляем изначальное значение в шаги
    steps.append(cloneArray(array));
    for (auto i = array.begin(); i != array.end(); ++i) {
       auto j = std::min_element(i, array.end());
       std::swap(*i, *j);
       steps.append(cloneArray(array));
    }

    return steps;
}
