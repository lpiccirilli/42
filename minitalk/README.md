# Minitalk 

Minitalk is part of the third ring of the Common Core, the goal is to develop two executables, a server and a client. The server must print his PID at start-up and listen for incoming messages until the user kills the process. The client requires the server PID and a message as arguments; once executed, it must transmit the message to the server. After receiving the message, the server prints it to the standard output and continues listening for messages from other clients. 

Communication between the two processes must be implemented exclusively using the Unix signals SIGUSR1 and SIGUSR2. These are user defined signals meant to communicate between different processes.
## Implementation

The most natural way to implement this is to take advantage of the correspondence between binary representation and the two signals we must use. Since the values to send are ascii values each character can be represented using 8 bits.

We define as convection that SIGUSR1 corresponds to 1 and SIGUSR2 to 0. 

For example:

```text
'a' == 01000001

SIGUSR2 SIGUSR1 SIGUSR2 SIGUSR2 SIGUSR2 SIGUSR2 SIGUSR1 SIGUSR1
   0       1       0       0       0       0       1       1
```

On the client side we can use bitwise operation to check the value of each bit:

```c
c & (1 << bit) 
```
where c is the character to convert and bit is the position to check. By iterating eight times, we can examine every bit of the character and send them to the server using [kill()](https://man7.org/linux/man-pages/man2/kill.2.html).

Server side is pretty much the same logic, We receive signals and reconstruct the original character bit by bit.
A char variable can be used to store the reconstructed value. When a SIGUSR1 signal is received, the corresponding bit can be set:
```c
c |= (0x01 << bit); // we can skip this for 0 since it is the default value
```

since we cannot know at which point we are at the character bits I can help myself with static variables. They will mantain they're value between different function calls, so after each received signal:

    - The bit counter is incremented.
    - Once all 8 bits have been received, the complete character is printed.
    - After printing the completed character the static variables are reset to prepare for the next character.