#ifndef _USUARIO_H_
#define _USUARIO_H_

typedef struct Usuario Usuario;

Usuario *construtorUsuario(char *, char *);

void *destrutorUsuario(Usuario *);

char *adquireNome(Usuario *);

#endif
