<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	Philosophers
</h1>

 <p align="center">
<img alt="total-views" src="https://img.shields.io/badge/views-11-blue">
<img alt="total-clone" src="https://img.shields.io/badge/clone-14-blue">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/Philosophers">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/Philosophers">
<img alt="GitHub repo file count" src="https://img.shields.io/github/directory-file-count/nach131/Philosophers/source">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/Philosophers">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<span align="center">

![visitors](https://visitor-badge.glitch.me/badge?page_id=nach131.Philosophers&left_color=green&right_color=blue)

</span>

El programa admite 5 argumentos.

- `number_of_philosophers`: es el número de filósofos, pero también el número de tenedores.

- `time_to_die`(enmilisegundos):si un filósofo no empieza acomer en time_to_die milisegundos desde el comienzo de su ultima comida o desde el principio de la simulación, este morirá.

- `time_to_eat` (en milisegundos): es el tiempo que tiene un filósofo para comer. Durante ese tiempo, tendrá los tenedores ocupados.

- `time_to_sleep` (en milisegundos): es el tiempo que tiene un filósofo para dormir.

- `number_of_times_each_philosopher_must_eat` (argumento opcional): si todos los filósofos comen al menos number_of_times_each_philosopher_must_eat veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.

## Funciones permitidas

### [memset](funciones/permitidas/memset.c)

```c
void *memset(void *ptr, int value, size_t num);
```
<details>
  <summary>Descripción</summary>

La función memset se utiliza para inicializar matrices y otros tipos de bloques de memoria.

Por ejemplo,el siguiente código utiliza memset para inicializar una matriz de enteros con el valor 0:

</details>

<details>
  <summary>Código</summary>

```c

int	main(void)
{
	int	myArray[10];
	int	i;

	memset(myArray, 0, sizeof(myArray));
	i = -1;
	while (++i < 10)
		printf("%d: %d\n", i, myArray[i]);
	return (0);
}
```
</details>

### [usleep](funciones/permitidas/usleep.c)

```c
int usleep(useconds_t usec);
```
<details>
  <summary>Descripción</summary>

- `usec`: Es el número de microsegundos durante los cuales el programa debe detenerse.

La función usleep es útil en situaciones en las que es necesario pausar el programa por un corto período de tiempo.

Se puede usar para controlar la velocidad a la que se envían datos a través de una conexión de red o para limitar la velocidad  de procesamiento de una aplicación.

</details>
<details>
  <summary>Código</summary>

```c
int	main(void)
{
	int	i;

	printf("Inicio del programa.\n");
	i = 0;
	while (i++ < 100000)
	{
		if (i == 5000)
		{
			printf("\tSE DETIENE\n");
			usleep(1000000); // Espera 1 segundo (1,000,000 microsegundos)}
		}
		printf("%d\n", i);
	}
	printf("Fin del programa.\n");
	return (0);
}
```
</details>

### [gettimeofday](funciones/permitidas/gettimeofday.c)
```c
int gettimeofday(struct timeval *tv, struct timezone *tz);
```
<details>
  <summary>Descripción</summary>
se utiliza para obtener el tiempo actual del sistema con una resolución de microsegundos

- `tv` : Es un puntero a una estructura timeval que se llenará con el tiempo actual.
- `tz` : Es un puntero a una estructura timezone.Este parámetro es obsoleto y
 no se utiliza en la mayoría de las implementaciones de gettimeofday.

```c
struct	timeval
{
	time_t tv_sec;       /* segundos */
	suseconds_t tv_usec; /* microsegundos */
};
```
La función gettimeofday es comúnmente utilizada para medir el tiempo transcurrido entre dos eventos en un programa, ya que tiene una resolución de microsegundos.

</details>

<details>
  <summary>Código</summary>

	```c
	int	main(void)
{
	long	tiempo_transcurrido;
	int		i;

	struct timeval inicio, fin;
	gettimeofday(&inicio, NULL); // Tiempo de inicio
	// Código que se desea medir
	i = 0;
	while (i++ < 100000)
	{
		;
	}
	gettimeofday(&fin, NULL); // Tiempo de fin
	tiempo_transcurrido = (fin.tv_sec - inicio.tv_sec) * 1000000L + (fin.tv_usec
			- inicio.tv_usec);
	printf("Tiempo transcurrido: %ld microsegundos.\n", tiempo_transcurrido);
	printf("Tiempo transcurrido: %ld segundos.\n", tiempo_transcurrido
			/ 1000000);
	return (0);
}
```
</details>

### [pthread_create](funciones/permitidas/pthread_create.c)

```c
int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
```
<details>
  <summary>Descripción</summary>

La función pthread_create se utiliza para crear un nuevo hilo en un programa multihilo. La función toma como argumentos un puntero a una variable de tipo `pthread_t`, que se utilizará para almacenar el identificador del nuevo hilo, un puntero a una estructura `pthread_attr_t`, que contiene los atributos del hilo, un puntero a una función que será la rutina del hilo y un puntero a un argumento que se pasará a la rutina del hilo.

- `thread`: un puntero a una variable de tipo pthread_t que se utilizará para almacenar el identificador del nuevo hilo creado por la función.

- `attr`: un puntero a una estructura de tipo pthread_attr_t que especifica los atributos del nuevo hilo. En la mayoría de los casos, se puede utilizar NULL para utilizar los valores por defecto.

- `start_routine`: un puntero a la función que será la rutina del hilo. Esta función debe ser de tipo void* y aceptar un argumento de tipo void*. La función devolverá un puntero void* cuando finalice.

- `arg` : un puntero a un argumento que se pasará a la función start_routine como su único argumento.La función devuelve 0 si el hilo se crea correctamente, o un valor de error en caso contrario.

</details>

<details>
  <summary>Código</summary>

	```c

	void	*funcion_hilo(void *arg)
{
	printf("\tHola desde el hilo\n");
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	id_hilo;

	pthread_create(&id_hilo, NULL, funcion_hilo, NULL);
	printf("Hola desde el hilo principal\n");
	pthread_exit(NULL);
}

	```
</details>