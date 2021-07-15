#ifndef BASESORT_H
#define BASESORT_H

#include <QString>
#include <QList>


/**
 * @brief The BaseSort class
 * 
 * Базовый класс для реализации
 * алгоритма сортировки со всей информацией,
 * выводом и пошаговым отображением алгоритма.
 * 
 */
class BaseSort {
protected:
    int key = -1;
    QString title = "";
    QString shortDescription;
    QString description;
    QString stepString;
    QString stepValue;
    QList<QString> algoritm;
    QString source = "";
    QList<QList<QString>> nominations;

    const QList<QString> COOL_NOMINATION = {"cool", "Один из самых прикольных методов сортировки"};
    const QList<QString> FAST_NOMINATION = {"fast", "Один из самых прикольных методов сортировки"};
    const QList<QString> SLOW_NOMINATION = {"slow", "Один из самых прикольных методов сортировки"};
    const QList<QString> SIMPLE_NOMINATION = {"simple", "Один из самых прикольных методов сортировки"};
public:
    BaseSort();
    ~BaseSort();
    
    /**
     * @brief getTitle
     * 
     * Получение названия метода
     * сортировки.
     * 
     * @return строка с названием
     */
    QString getTitle();
    
    /**
     * @brief getShortDescription
     * 
     * Получение которкого описания
     * для отображения в списке.
     * 
     * @return строка с коротким описанием.
     */
    QString getShortDescription();
    
    /**
     * @brief getDescription
     * 
     * Длинное описание алгоритма сортировки
     * для отображения в подробной карточке.
     * 
     * @return строка с описанием
     */
    QString getDescription();
    
    /**
     * @brief getStepString
     * 
     * Получение строки с формулой средней
     * сложности алгоритма сортировки.
     * 
     * @return строка с формулой (которая подсвечивается синим)
     */
    QString getStepString();
    
    /**
     * @brief getStepString
     * 
     * Среднее количество действий 
     * на 20 элементов массива для болшей
     * наглядности сложности алгоритма.
     * 
     * @return строка с числом (которая подсвечивается оранжевым)
     */
    QString getStepValue();

    /**
     * @brief setKey
     *
     * Ключ по которому созд данный объект,
     * устанавливается самой фабрикой при
     * создании.
     *
     * @param key ключ для фобрики.
     */
    void setKey(int key);

    /**
     * @brief getFactoryKey
     *
     * Получение ключа для создания
     * такого же обЪекта в фабрике.
     *
     * @return ключ по которому
     *         создан текущий объект.
     */
    int getFactoryKey();

    /**
     * @brief sort
     *
     * Сортировка массива и получение
     * поэтапной картинки действий.
     *
     * @param array изначальный массив.
     * @return этапы сортировки.
     */
    virtual QList<QList<int>> sort(QList<int> array);

    /**
     * @brief generateStartArray
     * @return создание изначального списка для сортировки;
     */
    QList<int> generateStartArray(int size);

    /**
     * @brief cloneArray
     *
     * Создание нкизменяемой копии массива.
     *
     * @param array исходный массив
     * @return копия.
     */
    QList<int> cloneArray(QList<int> array);

    /**
     * @brief cloneArray
     *
     * Создание нкизменяемой копии массива.
     * Из массива по указателю;
     *
     * @param array исходный массив
     * @return копия.
     */
    QList<int> cloneArray(int *array, int size);

    /**
     * @brief getAlgoritm
     *
     * Получение шагов алгоритма для описания
     *
     * @return шаги.
     */
    QList<QString> getAlgoritm();

    /**
     * @brief getSourceCode
     *
     * Получение исходного кода
     * алгоритма сортировки.
     *
     * @return строка с кодом.
     */
    QString getSourceCode();

    /**
     * @brief getNominations
     *
     * Получение номинаций которые заслужил
     * данный метод сортировки.
     *
     * @return строковые кодовые названия.
     */
    QList<QList<QString>> getNominations();
};

#endif // BASESORT_H
