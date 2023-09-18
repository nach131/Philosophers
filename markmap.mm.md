# Filosofos comensales

## main.c

- main()
    - Validación de argumentos
    - Inicialización de datos
        - init_data()
    - Espera que terminen procesos
        - waiting()
    - Destruye mutex
    - Libera memoria
- print_does()
    - Imprime estado de filósofo
- err_argc()
    - Muestra error si faltan argumentos
- free_data()
    - Libera memoria 
- destroy()
    - Destruye mutex e hilos

## init_data.c
- init_data()
    - Asigna valores de argumentos
    - Comprueba valores válidos
    - Inicializa
        - init_threads_mutex()
- init_threads_mutex()
    - Crea mutex e hilos
    - Crea filósofos
        - create_philo()
- create_philo()
    - Inicializa estructura de filósofo

## processes.c
- processes()
    - Bucle de estados de filósofo
- take_spoon()
    - Toma Cuchara/mutex
- drop_spoon()
    - Suelta Cuchara/mutex	
- eating()
    - Simula comer

## waiting.c
- waiting()
    - Espera a que terminen procesos
- is_die()
    - Comprueba si alguno muere
- all_eating()
    - Comprueba si terminaron de comer

## clock.c
- Funciones para manejar tiempo