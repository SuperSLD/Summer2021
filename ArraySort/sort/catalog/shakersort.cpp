#include "shakersort.h"
#include <QList>

ShakerSort::ShakerSort() {
    this->title = "Шейкерная сортировка";
    this->shortDescription = "Почти то же самое что и сортировка пузырьком, но работает лучше на других тестах.";
    this->description = "(также известна как сортировка перемешиванием и коктейльная сортировка). Заметим, что сортировка пузырьком работает медленно на тестах, в которых маленькие элементы стоят в конце (их еще называют «черепахами»). Такой элемент на каждом шаге алгоритма будет сдвигаться всего на одну позицию влево. Поэтому будем идти не только слева направо, но и справа налево. Будем поддерживать два указателя begin и end, обозначающих, какой отрезок массива еще не отсортирован. На очередной итерации при достижении end вычитаем из него единицу и движемся справа налево, аналогично, при достижении begin прибавляем единицу и двигаемся слева направо. Асимптотика у алгоритма такая же, как и у сортировки пузырьком, однако реальное время работы лучше.";
    this->stepString = "O(n^2)";
    this->stepValue = "400";

    this->source =
            "int control = array.size() - 1;\n"
            "int left  = 0;\n"
            "int right = array.size() - 1;\n"
            "do {\n"
            "   for (int i = left; i < right; i++) {\n"
            "       if (array[i] > array[i + 1]) {\n"
            "           std::swap(array[i], array[i + 1]);\n"
            "           control = i;\n"
            "       }\n"
            "   }\n"
            "   right = control;\n"
            "   for (int i = right; i > left; i--) {\n"
            "       if (array[i] < array[i - 1]) {\n"
            "          std::swap(array[i], array[i - 1]);\n"
            "           control = i;\n"
            "       }\n"
            "   }\n"
            "   left = control;\n"
            "} while (left < right);\n";
}

QList<QList<int>> ShakerSort::sort(QList<int> array) {
    QList<QList<int>> steps;
    steps.append(cloneArray(array));
    int control = array.size() - 1;
    int left  = 0;
    int right = array.size() - 1;
    do {
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
                control = i;
            }
            steps.append(cloneArray(array));
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (array[i] < array[i - 1]) {
                std::swap(array[i], array[i - 1]);
                control = i;
            }
            steps.append(cloneArray(array));
        }
        left = control;
    } while (left < right);
    return steps;
}
