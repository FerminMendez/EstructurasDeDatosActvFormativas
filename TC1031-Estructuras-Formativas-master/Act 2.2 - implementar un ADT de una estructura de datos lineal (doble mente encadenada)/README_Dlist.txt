Complejidades temporales:
insertion
O(n) siempre recorre hasta el ultimo link para agregarlo.

search
O(n) En el peor de los casos no está y habrá recorrido los n elementos de la lista.

update
O(n/2) Como sabemos el indice podemos recorrerlo desde el head o de la cola por lo que el peor de los casos es la mitad hay n/2 pasos.


deleteAt

O(n/2) De manera muy similar a update solo recorremos la mitad del arreglo.
