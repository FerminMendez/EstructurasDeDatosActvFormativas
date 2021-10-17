Análisis de complejidad

-push
Descripción: Agregue un dato a la fila priorizada.

Para agregar el valor es O(1). Lo "costoso" es acomodarlo en su nivel. Por la estructura del heap es O(logn)

-pop
Descripción: Saca de la fila priorizada el dato que tiene mayor prioridad.

La forma recursiva solo hace un cambio y un heapify de una rama a lo mas es O(log n)

-top
Descripción: Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
Para agregar el valor es O(1). Ya que solo regresa el valor de la posición 0.

-empty
Descripción: Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
Solo hace una comparación con el count. Entonces es O(1)

-size
Descripción: Regresa la cantidad de datos que tiene la fila priorizada.
Simplemente regresa el valor de count. Entonces es O(1)