#ifndef _listener_h
#define _listener_h
#include <stdlib.h>
#include <server.h>
#include <http11/http11_parser.h>

enum
{
	LISTENER_STACK = 32 * 1024,
    BUFFER_SIZE = 2 * 1024
};


typedef struct Listener {
    Server *server;
    int fd;
    http_parser *parser;
    int nread;
    int nparsed;
    int finished;
    int registered;
    int rport;
    char remote[IPADDR_SIZE];
    char buf[BUFFER_SIZE];
} Listener;

void Listener_init();

void Listener_destroy(Listener *listener);

Listener *Listener_create(Server *srv, int fd, int rport, const char *remote);

void Listener_accept(Server *srv, int fd, int rport, const char *remote);

int Listener_deliver(int to_fd, char *buffer, size_t len);

void Listener_task(void*);

int Listener_process_json(Listener *listener);

int Listener_process_http(Listener *listener);

int Listener_process_flash_socket(Listener *listener);

int Listener_parse(Listener *listener);

#endif