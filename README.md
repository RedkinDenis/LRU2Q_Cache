# LRU2Q_Cache

## Описание 
Здесь реализованы алгоритм кэширования LRU 2Q и модель идельного кэша для сравнения

## Сборка и запуск
Для сборки программы реализующей LRU 2Q необходимо:
> cd lru2q\
> cmake -DCMAKE_BUILD_TYPE=Release -S . -B build\
> cd build\
> make

__Cтандартный режим__
> ./lru2q.x

__Прохождение встроенных тестов__
> ./lru2q.test


Аналогично для идеального кэша:
> cd idcache\
> cmake -DCMAKE_BUILD_TYPE=Release -S . -B build\
> cd build\
> make

__Cтандартный режим__
> ./idCache.x

__Прохождение встроенных тестов__
> ./idCache.test

## Сравнение стратегий кэширования

> cd comparision\
> python3 compare.py


Папке _comparision/Tests_ находятся тесты на которых необходимо провести сравнение
