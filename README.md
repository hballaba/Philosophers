# Philosophers

Project about inter-process communication. A program that can monitor multiple instances of itself, either processes or threads, using semaphores or mutexes

Philosophers (represented by parts of a program) sit around a table, with a big plate of spaghetti at its center. They each have a fork, but they need two forks to eat ; so they need to borrow their neighbor's fork to eat.

Of course, if they borrow a neighbor's fork, the neighbor can't use the fork. The processes / threads must communicate, to know the state of the forks (and of the other philosophers) at all times. There must also be a parent process that monitors everything.

philo_one does this using threads as philosophers, and mutexes as forks.

philo_two uses threads as well, but uses semaphores as forks instead.

philo_three forks itself, making philosophers processes. Its forks are semaphores. It uses threads too, but only for monitoring.

How to use it
Using make in the philo_one directory will create the philo_one executable. Same for philo_two and philo_three.

You run it specifying, in order :

The number of philosophers

The time in milliseconds until a philosopher dies from starvation

The time in milliseconds it takes for a philosopher to eat

The time in milliseconds it takes for a philosopher to sleep

(Optional) The number of meals before the program stops

Example:
./philo_one 6 400 200 100 5
