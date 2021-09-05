README

Fermín Méndez García A01703366

Análisis de complejidad:

Ordena Selección/Selection Sort
#Dos cilcos anidados
#En el peor de los casos que es cuando el acomodo está completamente invertido, podemos ver que se tendrían que hacer alredor de (n*n+1)/2 pasos. Por eso O(n^2) es la compledidad

Ordena Bubuja/Bubble Sort
#Dos ciclos anidados
#Al igual que Selección sort su peor caso cuando esta invetido el arreglo y los pasos son (n*n+1)/2 por lo que O(n^2) es la complejidad.

Ordena Merge /Merge Sort

#Splits recursivos y recorridos lineales.
#Se harán recursiones para partir de complejidad log 2 además en cada partición se efectua un recorrido con menor coste que el lineal. Ya que estan parcialmente ordenados. Por lo que dejamos la complejidad en (n*log 2)

Busqueda secuencial

#Recorrido lineal
#Es fácil ver que el peor caso es cuando se efectuan n operaciones es decir O(n) cuando el elemento buscado es el último del array o no está.

Busqueda binaria.
#Split recursivo
#Facilmente denotamos la complejidad como log 2, pues se parte a la mitad. Si bien es más barato que la búsqueda secuencial tambien exige de un acómodo previo.
