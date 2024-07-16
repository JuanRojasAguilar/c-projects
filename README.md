# C projects
`This is a repository where i'm uploading projects i have been develop in C to get to know better the intricancies of handling data, allocating, deallocating memory and many more core conceps of computing`

1. [c-server](#c-server)

## c-server

This is a simple HTTP server with will server an `index.html` page inside the `src/` folder, you can use it by running:

    `Make main && ./main` if you are on UNIX machines
    or
    `nmake main && main` if you are on a Windows machine

#### Explanation

First we define three variables

PORT 
: the port in wich is going to be connected our server
MAXIMUM_REQUEST_SIZE 
: is going to be the maximum buffer that we can send over the server, we are asigning here 2kb.
ROOT 
: it's the folder in which the server is going to read and then serve the index.html

Sockets are essentially a port for communication between your computer and any service that can connect to that socket. In C they come from the arpa/inet.h library wich contains networking functionalities.

We create a sock_address_internet (sockadd_in) for the serverAddr, clientAddr.
