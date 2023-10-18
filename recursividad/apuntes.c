/*recursividad:

    factorial propiedad recursiva

    double rFactorial(unsigned num)
    {
        if(!num || n==1)
            return 1;
        else
            return rFactorial(n-1)*n;

    }
*/

jerarquia
NODO PADRE (nodo raiz)------->hijos (cant variable)
          |
          |
          -> hijo

          nodos sin hijos(nodo hoja)

          altura - cant maxima de saltos para llegar hasta el ult nodo

            niveles (n desde 0 hasta el ult hijo)
          altura = niveles+1

          arboles binarios ->como maximo 2 hijos por nodo (hijo izq e hijo der)

          arboles de expresion = como el compilador intepreta la cuenta, la instruiccion q le das a la pc

          arboles binarios de busqueda -> se usa para indices
          balanceo del arbol = los hijos izquierdos tienen clave menor que el PADRE y los hijos derechos mayor

          arbol altura 3 con 7 nodos es completo
          cant max de nodos = (2^nodos) -1

          balanceado = completo hasta el ante ult nivel
          balanceo AVL = bastante eficiente y mas simple alcanzar el balanceo
            la dif de altura entre los arboles izq y derecho nunca es mayor a 1 para todos los nodos

            si es completo es balanceado




