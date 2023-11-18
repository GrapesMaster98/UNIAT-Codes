#include <stdio.h>

int
main ()
{
  //Definir el array con las materias, resultado y variable
  int cal[5], promedio, i;
  
  for( i = 0; i<5; i++ ) {
      printf("Ingrese las calificaciones del alumno... \n");
      scanf("%d", &cal[i]);
  }
  
  i=0;
  
  while(i>5) {
      promedio += cal[i];
      i++;
  }
  
  promedio /= 3;
  
  printf("%d", promedio);
  
  if(promedio >= 6) {
      printf("El alumno ha aprobado.");
  } else if (promedio <= 5) {
      printf("El alumno ha reprobado.");
  }
}