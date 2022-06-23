/* Exercício 1 - Monitoria Prog I
   Autor: Jheam Storch Ross */

#include <stdio.h>

void main(void) {
    float x = .0, y = .0, z = .0;
    scanf("%f %f %f", &x, &y, &z);

    /* From 0 to 7,
     *     +x: 1
     *     +y: 2
     *     +z: 4
     */
    int octantSum = 0;
    
    octantSum += x > 0 ? 1 : 0;
    octantSum += y > 0 ? 2 : 0;
    octantSum += z > 0 ? 4 : 0;

    /* Octants:
     *     1º: 7
     *     2º: 6
     *     3º: 4
     *     4º: 5
     *     5º: 3
     *     6º: 2
     *     7º: 0
     *     8º: 1     
     */
    int octant = 0;
    switch (octantSum)
    {
    case 7:
    case 6:
    case 3:
    case 2:
        octant = 8 - octantSum;
        break;
    case 4:
    case 5:
        octant = octantSum - 1;
        break;
    case 0:
    case 1:
        octant = 7 + octantSum;
        break;
    }

    printf("%dº Octante", octant);
}
