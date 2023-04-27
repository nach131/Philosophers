# Philosophers


El programa admite 5 argumentos.

- `number_of_philosophers`: es el número de filósofos, pero también el número de tenedores.

- `time_to_die`(enmilisegundos):siunfilósofonoempiezaacomerentime_to_die milisegundos desde el comienzo de su ultima comida o desde el principio de la simulación, este morirá.

- `time_to_eat` (en milisegundos): es el tiempo que tiene un filósofo para comer. Durante ese tiempo, tendrá los tenedores ocupados.

- `time_to_sleep` (en milisegundos): es el tiempo que tiene un filósofo para dormir.

- `number_of_times_each_philosopher_must_eat` (argumento opcional): si to- dos los filósofos comen al menos number_of_times_each_philosopher_must_eat veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.
