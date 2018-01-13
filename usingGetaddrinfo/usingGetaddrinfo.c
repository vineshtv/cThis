/*
 *  The getaddrinfo() function is used to get a list of IP addresses and port numbers for host hostname and service servname.
 *
 *  usage - int
 *          getaddrinfo(const char *hostname,           // The hostname you are trying to lookup. In this case www.google.com 
 *                      const char *servname,           // The port number or service name.  
 *                      const struct addrinfo *hints,   // Hints on what to lookup. 
 *                      struct addrinfo **res);         // The results. A linked list of addrinfo structs 
 *  
 *  addrinfo struct is as follows
 *  struct addrinfo {
 *               int ai_flags;              // input flags
 *               int ai_family;             // protocol family for socket 
 *               int ai_socktype;           // socket type 
 *               int ai_protocol;           // protocol for socket 
 *               socklen_t ai_addrlen;      // length of socket-address 
 *               struct sockaddr *ai_addr;  // socket-address for socket 
 *               char *ai_canonname;        // canonical name for service location 
 *               struct addrinfo *ai_next;  // pointer to next in list 
 *  };
 *
 *  man getaddrinfo for more :)
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main()
{
    struct  addrinfo    hints;
    struct  addrinfo    *res, *rp;
    char                host[256];

    // Everything other than what we want to specify in the hints have to be null
    memset(&hints, 0, sizeof(struct addrinfo));
    
    hints.ai_family = AF_INET; // AF_INET means IPv4 addresses only
    
    int result = getaddrinfo("www.google.com",
                             NULL,
                             &hints,
                             &res);

    if(result)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        return -1;
    }

    for(rp = res; rp != NULL; rp = rp->ai_next)
    {
        // getnameinfo converts a sockaddr structure to a pair of host name and service strings.
        getnameinfo(rp->ai_addr, 
                    rp->ai_addrlen,
                    host,
                    sizeof(host),
                    NULL, 
                    0, 
                    NI_NUMERICHOST);  

        puts(host);
    }

    freeaddrinfo(res);
    return 0;
}
