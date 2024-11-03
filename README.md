# LRU2Q_Cache

## Описание 
Здесь реализованы алгоритм кэширования LRU 2Q и модель идельного кэша для сравнения

## Сборка и запуск

Для общей сборки необходимо выполнить следующие команды из корневой папки проекта:
> cmake -DCMAKE_BUILD_TYPE=Release -S . -B build\
> cd build\
> make

Далее для запуска программы реализующей LRU 2Q необходимо:
> cd lru2q

__Cтандартный режим__
> ./lru2q.x

__Прохождение встроенных тестов__
> ./lru2q.test


Аналогично для идеального кэша:
> cd idcache

__Cтандартный режим__
> ./idCache.x

__Прохождение встроенных тестов__
> ./idCache.test

## Сравнение стратегий кэширования
(из корневой папки проекта)
> cd comparision\
> python3 compare.py


В папке _comparision/Tests_ находятся тесты на которых необходимо провести сравнение
