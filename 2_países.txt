Problema 2 (RISK – UVA 567):

RISK es un juego de mesa en el que varios jugadores contrarios intento de conquistar el mundo. El tablero consta de un mapa del
mundo dividido en países hipotéticos. Durante el turno de un jugador, los ejércitos estacionados en un país sólo se les permite
atacar a los países con los que comparten una frontera común. Tras la conquista de ese país, los ejércitos pueden entrar en este
país recién conquistado.

Durante el juego, un jugador se involucra en una secuencia de conquistas con el objetivo de transferir ejércitos sus países hacía
los países enemigos. Por lo general, se eligen los países que deberán ser invadidos a fin de minimizar el número total de países
que deben ser conquistados para poder llegar a un país destino. Dada la descripción del tablero con 20 países cada uno mantiene
entre 1 y 19 conexiones a otros países, su tarea es escribir una función que toma un país de partida y un país de destino y
calcula el número mínimo de países que deben ser conquistados para llegar al de destino. Usted no necesita la secuencia de los
países resultantes, sólo el número de países que se conquistó incluyendo el destino. Por ejemplo, si el país de partida y el de
destino son vecinos, entonces el programa debe devolver uno.

Entrada:
La entrada a su programa consistirá en una serie de conjuntos de países de prueba y su respectiva configuración. 
De la línea (i) 1 a la 19 contiene el detalle de los países con los que límita el país i. Cada una de estas líneas contará con un
número x al inicio que indica la cantidad de países con los que el país i limita. 
La línea #20 contiene la cantidad n de casos de prueba que se deberán ejecutar. 
Por cada una de las siguientes n líneas se dará un par de números a,b en donde se pide hallar la cantidad de países que se deberán
conquistar para que el país a pueda invadir el país b.

Salida:
Por cada mapa se deberá escribir los resultados obtenidos de cada caso de prueba. 

Ejemplo de Entrada:  
1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20
4 2 3 5 6
1 4
3 4 10 5
5 10 11 12 19 18
2 6 7
2 7 8
2 9 10
1 9
1 10
2 11 14
3 12 13 14
3 18 17 13
4 14 15 16 17
0
0
0
2 18 20
1 19
1 20
6
1 20
8 20
15 16
11 4
7 13
2 16

Ejemplo de Salida:  
Test Set #1
 1 to 20: 7
 2 to  9: 5
19 to  5: 6
18 to 19: 2
16 to 20: 2
Test Set #2
 1 to 20: 4
 8 to 20: 5
15 to 16: 2
11 to  4: 1
 7 to 13: 3
 2 to 16: 4
 
