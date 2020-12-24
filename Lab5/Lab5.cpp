#include <iostream>
#include "DataManager.cpp"
#include "../Lab5/FileReader.h"
#include "Book.h"
#include "Catch.h"
int main()
{
    //    Написать шаблонный класс DataManager<T> для специфической работы с набором
    //    однотипных данных(максимальная вместимость равна 64 элементам).В набор можно
    //    добавлять данные(метод push(T elem) для добавления одного элемента и метод
    //        push(T elems[], size_t n) для добавления группы из n элементов), считывать без
    //    извлечения(метод T peek()) и извлекать(метод T pop()) по некоторым алгоритмам
    //    (в соответствии с вариантом, приложение А).Если набор заполнен на 100 % и
    //    поступает команда добавления нового элемента(ов), то данные полностью
    //    выгружаются(дописываются) в специальный файл dump.dat, а сам массив очищается
    //    и новые данные записываются уже в обновленный набор.

    DataManager<int> d;
    int mas[4] = { 1, 23, 4, 3 };
    d.push(mas, 4);

    std::cout << d.peek() << std::endl;

	DataManager<char> char_manager; 

    char_manager.push('T');

    auto charLower = char_manager.popLower();

     //  Написать код для чтения произвольного текстового файла и вывода на экран всех слов
     //  размером более 3 букв, встречающихся в нем не менее 7 раз, в порядке убывания
     //  частоты встречаемости(приложение А).В качестве разделителей слов рассматривать
     //  пробел, точку, запятую, тире, двоеточие, восклицательный знак, точку с запятой.
     //  Использовать контейнер std::map.

    FileReader fr;

    auto maps = fr.Read();
    
    for (auto mass_it = maps.begin(); mass_it != maps.end(); ++mass_it)
        std::cout << mass_it->first << ":(" << mass_it->second << ")" << std::endl;


     // Создать класс книги Book, в котором хранится название, автор и год издания книги.В
     // главной функции создать коллекцию книг(приложение А).Продемонстрировать
     // сортировку книг по автору(первичный ключ) и названию(вторичный ключ).
     // Продемонстрировать поиск в коллекции : найти все книги, год издания которых
     // находится в указанном диапазоне.Использовать контейнер std::vector и функторы.

    std::vector<Book> books{ Book("D", "D", 2000), Book("M", "M", 1999), Book("R", "R", 2002) };
    std::sort(books.begin(), books.end(), [](Book f, Book l) {return f.Year > l.Year; });

    for (auto author : books)
        std::cout << author.Year << std::endl;

    std::vector<Book>::iterator finder = std::find_if(books.begin(), books.end(), [](Book book)
        {
            if (2001 < book.Year && book.Year < 2003)
                return true;

            return false;
        });


    // Подсчитать и вывести на консоль количество всех книг новее 2009 года, используя
    // только стандартные алгоритмы и функторы STL(подcказка: std::count_if,
    // std::greater<>, std::bind2nd)

    int mc = std::count_if(books.begin(), books.end(), [](Book book) {return book.Year > 2000; });

    // Написать шаблонный класс кэша данных Cache<T> с методом добавления элемента в
    // кеш put(T elem) и его аналогом – оператором +=, а также методом проверки наличия
    // элемента в кеше bool contains(T elem).Написать явную специализацию шаблона
    // для типа std::string с такими нюансами : метод contains() должен возвращать true
    // по совпадению первого символа строки; метод add() должен генерировать
    // исключение, если в кеше уже есть 100 строк.В главной функции инстанцировать
    // Cache с типами int и std::string, добавить в каждый несколько элементов и
    // продемонстрировать для каждого работу метода contains() (см.Приложение А).

    Cache<int> cache;
    cache.put(1); 
    cache.put(2);
    cache.put(3);
    cache += 5; 

    Cache<std::string> voc;
    voc.put("test");

    std::cout << voc.contains("Only") << std::endl; // 1
    std::cout << cache.contains(5) << std::endl; // 1
    return 0;
}
