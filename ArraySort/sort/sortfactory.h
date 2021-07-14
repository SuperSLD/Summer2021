#ifndef SORTFACTORY_H
#define SORTFACTORY_H

#include "basesort.h"


/**
 * @brief The SortFactory class
 *
 * Фабрика классов с информацией
 * о сортировке для каталога и не только
 * для него.
 */
class SortFactory {
public:
    SortFactory();

    /**
     * @brief create
     *
     * Создание экземпляра с информацией
     * о виде сортировки для каталога.
     *
     * @param key ключ для опреледения вида сортировки.
     * @return дата класс с инфой по сортировке.
     */
    BaseSort* create(int key);

    /**
     * @brief getMaxKey
     *
     * Получение максимального значения
     * ключа для того чтоб можно было
     * создать все экземпляры по порядку так
     * как ключи длджны идти в порядке возрастания.
     *
     * 1, 2, 3, 4 ....... MAX_KEY
     *
     * @return MAX_KEY
     */
    int getMaxKey();
};

#endif // SORTFACTORY_H
