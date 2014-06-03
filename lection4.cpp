#include "lections.h"

#include <iostream>
using namespace std;

#include "struct_vector3.h"
typedef Vector3 V3;

#include "class_vector2.h"
typedef Vector2 V2;

#include "class_unit.h"
typedef Unit U;

void lection4() {
  // Прямая инициализация (direct initialization)
  /* 1.1 */ U direct1("U direct1(\"\", 0, 0)", 0, 0);
  /* 1.2 */ U direct2{"U direct2{\"\", 0, 0}", 0, 0};
  /* 2.1 */ new U("new U(\"\", 0, 0)", 0, 0);
  /* 2.2 */ new U{"new U{\"\", 0, 0}", 0, 0};
  /* 3.1 */ U("U(\"\", 0, 0)", 0, 0);
  /* 3.2 */ U{"U{\"\", 0, 0}", 0, 0};
  /* 4 */ // базовый класс или поле-объект, указанные в списке инициализации
          // с непустыми круглыми или фигурными скобками
  // При прямой инициализации на основании передаваемых аргументов
  // происходит разрешение перегрузки и вызов соответствующего конструктора
  // из полного списка, включая конструкторы явного преобразования.
  
  // Инициализация копии (copy initialization)
  /* 1 */ U copy1 = direct1;
  /* 2 */ void f(U copy);
  /* 3 */ U f() /* { return global1; } */;
  /* 4 */ try { throw direct2; }
  /* 5 */ catch (U copy) {}
  // При инициализации копии аргумент либо имеет тип U, либо приводится к нему,
  // причем не рассматриваются конструкторы и операторы явного преобразования,
  // после чего происходит прямая инициализация аргументом типа U,
  // т.е. разрешение перегрузки и вызов конструктора копирования или перемещения;
  // в ситуациях 1-3 возможно исключение копирование, в т.ч. (N)RVO в ситуации 3.

  // Обратите внимание:
  // U(direct1); // это ОПРЕДЕЛЕНИЕ ОБЪЕКТА!
  U{direct2}; // это прямая инициализация

  // Инициализация по умолчанию (default initialization)
  /* 1 */ U default1;
  /* 2 */ new U;
  /* 3 */ // базовый класс или поле-объект, не указанные в списке инициализации
  // При инициализации по умолчанию вызывается конструктор по умолчанию.
  // Если U - массив, то происходит инициализация по умолчанию каждого элемента.
  // Если U - простой тип, то при инициализации по умолчанию не происходит ничего.

  // Инициализация значением (value initialization)
  /* 1.1 */ // U value1(); // это объявление ФУНКЦИИ!
  /* 1.2 */ U value2{};
  /* 2.1 */ new U();
  /* 2.2 */ new U{};
  /* 3.2 */ U();
  /* 3.2 */ U{};
  /* 4 */ // базовый класс или поле-объект, указанные в списке инициализации
          // с пустыми круглыми или фигурными скобками
  // Инициализация значением в большинстве случаев сводится к инициализации по умолчанию,
  // но если конструктор по умолчанию сгенерирован автоматически,
  // то сначала происходит инициализация нулем, и только потом - инициализация по умолчанию,
  // и то если сгенерированный конструктор не тривиален.
  // Если U - массив, то происходит инициализация значением каждого элемента.
  // Если U - простой тип, то происходит инициализация нулем.
  
  // Инициализация нулем (zero initialization)
  /* 1 */ // поле-переменная, не указанное в списке инициализации

  /* 2-3 */ // В следующих случаях инициализация нулем происходит в момент запуска программы
  // на первом шаге этапа статической инициализации, но может быть оптимизирована компилятором:

  /* 2.1 */ static U static1;
  /* 2.2 */ // static U static2(); // это объявление функции
  /* 2.3 */ static U static3{};
  /* 2.4 */ static U static4("static U name9(\"\", 0, 0)", 0, 0);
  /* 2.5 */ static U static5{"static U name10(\"\", 0, 0)", 0, 0};
  // Соответствующая определению инициализация происходит позже, в процессе работы функции.
}

/* 3.1 */ U global1;
/* 3.2 */ // U global2(); // это объявление функции
/* 3.3 */ U global3{};
/* 3.4 */ U global4("U name14(\"\", 0, 0)", 0, 0);
/* 3.5 */ U global5{"U name15(\"\", 0, 0)", 0, 0};
// Соответствующая определению инициализация происходит далее в процессе запуска программы,
// на следующем этапе динамической инициализации, но может быть оптимизирована компилятором
// и происходить сразу на этапе статической инициализации, если это не влияет на результат.

// Если U - массив, то происходит инициализация нулем каждого элемента.
// Если U - сложный тип, то происходит инициализация нулем каждого поля и бита выравнивания.
// Если U - объединение, то происходит инициализация нулем только первого поля.
// Если U - простой тип, то к этому типу приводится целочисленный ноль.

// Инициализация констант (constant initialization) происходит в процессе запуска программы
// на втором шаге этапа статической инициализации, но может быть оптимизирована компилятором.

void lection4_bonus() {
  // Инициализация ссылки (reference initialization)
  
  // Агрегатная инициализация (aggregate initialization)

  // Инициализация списком (list initialization)
  
}
