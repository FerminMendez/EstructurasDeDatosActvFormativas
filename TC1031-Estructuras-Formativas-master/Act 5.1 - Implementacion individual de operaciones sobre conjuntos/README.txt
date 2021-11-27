Análisis de complejidad

-put

Descripción: inserta elementos a una tabla de hash con prueba cuadrática.
put usa algunas funciones auxiliares.

full: Tiempo constante O(1) pues solo compara count con size
indexOf:Complejidad O(n) ejecuta el salto cuadrática n veces. Sabemos que a diferencia de lo implementación lineal de colisiones d
este método no garantiza recorrer todo el hash completo.

Además la función por si misma tiene un ciclo de complejidad O(n) que busca encontrar un espacio vacío en la tabla

En resumen, la complejidad de la función put es de O(2n) aproximadamente


get
Descripción: obtiene el elemento asociado a la llave dentro de la tabla hash.

get usa indexOf desde una interfaz llamada constains luego usa indexOf

Por lo tanto tiene una complediad de O(2n) al igual que put.