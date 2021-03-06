# Ход конём
**1. Назначение программы**

Это учебная программа позволяет смоделировать движение шахматной фигуры "Конь" по полю размером 8x8.
Дополнительным условием является то, что "Конь" должен побывать в каждой ячейке только один раз. 
**Внимание! Программа тестировалась только в среде [Borland 3.1](http://ci-plus-plus-snachala.ru/?p=121)!**

**2. Структура проекта**

Название файла  | Содержимое файла
----------------|-----------------------
HORSEPRT.H      | Подключение стандартных библиотек, объявление переменных, классов, методов и функций
HORSE.CPP       | Основной файл проекта, содержит функцию **main()**
HORSECTR.CPP    | Описание функций управления программой
HORSERND.CPP    | Описание методов и функций поиска наилучшей траектории обхода
HORSEOUT.CPP    | Диалоговые функции, пользовательский интерфейс
HORSEVIZ.CPP    | Визуализация шахматного поля
HORSEGPR.CPP    | Описание методов и функций поиска наилучшей траектории обхода с визуализацией шахматного поля
Help.txt        | Файл с подсказками

**3. Компиляция**

Для компиляции и запуска лучше всего воспользоваться простым, как Лампочка Ильича, и надёжным, как Автомат Калашникова, [Borland 3.1](http://ci-plus-plus-snachala.ru/?p=121)
Выбор данной среды разработки был обусловлен принципом "необходимо и достаточно", а также предпочтениями "заказчика"(преподавателя программирования).
Итогом компиляции будет консольное приложение.


**4. Запуск программы**

После успешного запуска скомпилированного exe-файла, в новом окне появится заставка как на рисунке ниже(рис. 1.):

![Рис. 1. Заставка](https://github.com/rbforest/move-the-horse/blob/master/image/Greeting.JPG)

**5. Главное меню**

После запуска станет доступно главное меню  программы.

![Рис. 2. Главное меню](https://github.com/rbforest/move-the-horse/blob/master/image/Main%20menu.JPG)

Как можно видеть на рисунке выше(рис. 2.) в главном меню содержатся 7 пунктов, выбор которых осуществляется функциональными клавишами(F1-F6,F10).
Рассмотрим эти пункты подробней:

**5.1. Help**

При нажатии клавиши F1 в главном меню программа выводит содержимое файла Help.txt

![Рис. 3. Help](https://github.com/rbforest/move-the-horse/blob/master/image/Help.JPG)

**5.2 Я - и есть конь**

При нажатии клавиши F2 в окне программы появится шахматное поле размером 8х8 клеток(рис. 4.)

![Рис. 4. Шахматное поле](https://github.com/rbforest/move-the-horse/blob/master/image/Manual%20mode%20bypass.JPG)

Пользователь может самостоятельно, кликая мышью, выбирать те клетки, по которым должна перемещаться фигура "конь".
Так же он может переключиться в автоматический режим, кликнув по полю с надписью "РУЧ" в правом верхнем углу.
После чего надпись в этом поле сменится на "АВТ" и после выбора следующей клетки, программа начнёт самостоятельно перемещаться по полю(рис.5.).

![Рис. 5. Автоматический режим на шахматном поле](https://github.com/rbforest/move-the-horse/blob/master/image/The%20transition%20from%20manual%20to%20automatic%20mode.JPG)

**5.3. Хромая кобыла**

При нажатии клавиши F3 пользователю будет предложено ввести координаты начального положения шахматной фигуры "конь"
После чего запустится автоматический обход всего поля с заданной позиции.
При этом пользователь сможет отследить не только текущее положение, возможные пути перемещения или пройденную траекторию,
но так же методы и функции вызываемые в программе(рис. 6.).

![Рис. 6. Автоматический режим на шахматном поле](https://github.com/rbforest/move-the-horse/blob/master/image/Semi-automatic%20mode.JPG)

В случае возникновения тупиковых ситуаций(когда не во всех клетках ещё побывали, но из текущей позиции шагнуть уже некуда) происходит возврат к предыдущей развилке,
где программа меняет траекторию обхода(рис. 7.).

![Рис. 7. Возврат к развилке](https://github.com/rbforest/move-the-horse/blob/master/image/Rollback.JPG)

**5.4. Реактивный конь**

При нажатии клавиши F4 программа самостоятельно устанавливает начальное положение фигуры "конь", обходит всё шахматное поле, смещается на одну клетку и начинает обход заново.
И так пока не доёдёт до последней клетки.

**5.5. Посмотреть пройденный путь**

По нажатию клавиши F5, программа выведет на экран траекторию последнего обхода шахматного поля в виде последовательности координат(рис. 8.):

![Рис. 8. Траектория пройденного пути](https://github.com/rbforest/move-the-horse/blob/master/image/The%20path.JPG)

**5.6. Записать траекторию в файл**

По нажатию клавиши F6, программа создаст массив и проинициализирует его координатами последней траектории обхода(рис. 9.):

![Рис. 9. Инициализация массива](https://github.com/rbforest/move-the-horse/blob/master/image/Initialize%20array%20for%20output%20trajectory%20file.JPG)

После чего попросит пользователя ввести имя файла для записи траектории в файл(рис. 10.):

![Рис. 10. Запись траектории файл](https://github.com/rbforest/move-the-horse/blob/master/image/Save%20trajectory%20to%20file.JPG)

Результат записи траектории в файл(рис. 11):

![Рис. 11. Траектория](https://github.com/rbforest/move-the-horse/blob/master/image/track.JPG)

**5.7. Завершение работы программы**

По нажатию клавиши F10 происходит штатное завершение программы.

Дата релиза: ***14.06.2016***

_Спасибо Вам, что смогли дочитать это до конца! :)_
