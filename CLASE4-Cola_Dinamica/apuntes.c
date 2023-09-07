/*
COLA-QUEUE
-Aplica FIFO


Dos puntos de acceso
1) fondo para entrada

            ----------------------
fondo-fin -->                       --> frente-inicio-salida
            ----------------------
2) frente para salida


Primitivas:
poner_en_cola
sacar_de_cola
crear_cola
cola_llena
cola_vacia
vaciar_cola
frente_de_cola

EJ: dado un archivo binario o txt, viene ordenado por "numero_de_pedido",codigo_de_producto,cantidad y precio

ped/cod     /cant/precio
01 martillo 1     10
01 destor   2     20
01
02  clavos

un archivo tiene el stock, guardar el pedido y validar el stock si es que se pudo hacer, actualizar stock y gaurdar el pedido,
si el pedido no se puede realizar, guardar en un archivo de errores

!!HACER!!
guardar en 1 archivo los pedidos que tengan mas de $100 en un archivo y en otro archivo los pedidos que tengan menos de $100

el pedido completo tiene que estar en el mismo orden.
*leer el pedido e ir guardandolo en una cola*

*/
