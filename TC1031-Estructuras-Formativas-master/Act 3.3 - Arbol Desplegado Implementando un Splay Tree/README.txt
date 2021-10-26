Funciones y analisis de complejidad:
Las primeras 3 las tomamos de https://www.bigocheatsheet.com/ dado que el análisis resulta muy complejo.

-add
Descripción: Agregue un dato al Splay Tree.
O(logn)

-remove
Descripción: Elimina el dato del Splay Tree.
O(logn)

-find
Descripción: Regresa un valor boleano que representa si el dato qus se desea encontrar existe o no.
O(logn)

-size
Descripción: Regresa la cantidad de datos que tiene el Splay Tree.
O(1) Pues agregué un atributo sze que cuenta los datos con el remove y add.