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

### [pthread_create](funciones/permitidas/pthread_create.c)

```c
int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*start_routine)(void*), void* arg);
```
<details>
  <summary>Descripción</summary>

La función `pthread_create` se utiliza para crear un nuevo hilo en un programa multihilo. La función toma como argumentos un puntero a una variable de tipo `pthread_t`, que se utilizará para almacenar el identificador del nuevo hilo, un puntero a una estructura `pthread_attr_t`, que contiene los atributos del hilo, un puntero a una función que será la rutina del hilo y un puntero a un argumento que se pasará a la rutina del hilo.

- `thread`: un puntero a una variable de tipo `pthread_t` que se utilizará para almacenar el identificador del nuevo hilo creado por la función.

- `attr`: un puntero a una estructura de tipo `pthread_attr_t` que especifica los atributos del nuevo hilo. En la mayoría de los casos, se puede utilizar NULL para utilizar los valores por defecto.

- `start_routine`: un puntero a la función que será la rutina del hilo. Esta función debe ser de tipo void* y aceptar un argumento de tipo void*. La función devolverá un puntero void* cuando finalice.

- `arg` : un puntero a un argumento que se pasará a la función start_routine como su único argumento.La función devuelve 0 si el hilo se crea correctamente, o un valor de error en caso contrario.

</details>

### [pthread_detach](funciones/permitidas/pthread_detach.c)

```c
int pthread_detach(pthread_t thread);
```
<details>
  <summary>Descripción</summary>

indicar al sistema que el hilo especificado debe ejecutarse de forma independiente, sin necesidad de que el hilo principal lo espere para realizar la limpieza de los recursos que utiliza.

En otras palabras, con esta función se puede liberar la memoria y otros recursos asociados al hilo de forma automática, sin necesidad de llamar a `pthread_join`.

- `thread` es el identificador del hilo que se desea desvincular.

</details>

### [pthread_join](funciones/permitidas/pthread_join.c)

```c
int pthread_join(pthread_t thread, void** retval);
```
<details>
  <summary>Descripción</summary>

se utiliza para esperar a que un hilo específico termine su ejecución.

Cuando se llama a esta función, el hilo principal (o cualquier otro hilo que llame a la función) se bloqueará hasta que el hilo especificado haya terminado su ejecución.
</details>

### [pthread_mutex_init](funciones/permitidas/pthread_mutex_init.c)

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
```
<details>
  <summary>Descripción</summary>

Inicializar un objeto mutex, que es un mecanismo de sincronización utilizado para evitar que varios hilos accedan simultáneamente a una sección crítica del código.

- `mutex` es un puntero al objeto mutex que se desea inicializar.
- `attr` es un puntero a un objeto pthread_mutexattr_t

</details>

### [pthread_mutex_destroy](funciones/permitidas/pthread_mutex_destroy.c)

```c
int	pthread_mutex_destroy(pthread_mutex_t *mutex);
```

<details>
  <summary>Descripción</summary>

 se utiliza para destruir un objeto mutex que fue creado previamente con la función `pthread_mutex_init`.

- `mutex` es un puntero al objeto mutex que se desea destruir.

</details>

### [pthread_mutex_lock](funciones/permitidas/pthread_mutex_lock.c)

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
```

<details>
  <summary>Descripción</summary>

Bloquear un objeto mutex. Si el mutex ya está bloqueado por otro hilo, la función `pthread_mutex_lock` esperará hasta que el mutex se desbloquee antes de continuar.

- `mutex` es un puntero al objeto mutex que se desea bloquear.

</details>