Análisis temporal

-visit
Análizaremos la complejidad de cada una de las funciones que manda a llamar:

Descripción: Despliega cada uno de los datos almacenados en el BST:
1. Preorder 
2. Inorder
3. Postorder
Estas primeras tres pasan por cada uno de los nodos, es por eso que su complejidad es O(n)

4. Level by level
Esta última está implementada con un array auxiliar del tamaño de la profundidad del arbol. Gracias a esto puede recuperar todos los valores en tiempo O(n).
Posteriormente se usa un ciclo de complejidad O(h) donde n>h lo que se podría tomar como otro O(n).
Es decir, la catalogamos como 2(n)

La complejidad de visit queda como O(5n) o O(kn)

-height

Descripción: Obtiene la altura del BST (el número del nivel más profundo). Un árbol con solo la raíz tiene altura 1

Tambien es necesario explorar todas las ramas y encontrar la mas profunda por eso tambien es O(n)


-ancestors

Descripción: Obtiene los ancestros de un dato (todos los nodos arribas de n en línea directa hasta llegar a la raiz)


Ancestors tiene una validación con el find, de complejidad O(logn) luego el peor de los casos de ancestors tambien es log(n)
Por lo tanto es 2(log n).
#Nota: Se considera un BST normalizado, de lo contrario ambas complejidades se pueden extener a O(n) como una linked list y la complejidad seria O(2n)

-whatlevelamI

Descripción: Obtiene un entero que indica el nivel en que se encuentra un dato, o -1 en caso de que no se encuentre en el BST

Primero se hace una validación de log n considerando el caso anterior. Y finalemte otro log n porque solo recorre una rama.
Analogo que el caso anterior es O(2 log n) o O(2n) si está como linked list.