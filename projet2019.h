#ifndef PROJET2019_H
#define PROJET2019_H

#define NTRANCHES 1024
#define min(a,b) (a<=b?a:b)

typedef union {
    intmax_t a;
    void* adr;
    long double c;
} align_data;

typedef struct node{
    ptrdiff_t next;
    ptrdiff_t previous;
    size_t len; //en nb de bloc de taille align_data
    align_data data[];
} node;

 typedef struct{
    ptrdiff_t decalage;
    size_t nb_blocs;
} tranche;

typedef struct{
    void* memory;
    ptrdiff_t first;
    ptrdiff_t last;
    size_t size;    //taille de la memoire pointée par memory en octets
    size_t nb_elem; //nb elements dans la liste
    size_t nb_bloc_libre;
    size_t tab_tranches_size; //nb de tranches total , valeur initiale=NTRANCHES
    size_t nb_elem_tab_tranches; //nb de tranches actuelle dans tab_tanches (cb sur NTRANCHES )
    tranche* libre;
} head;

extern size_t nb_blocs(size_t);
extern void* ld_create(size_t);
extern void* ld_first(void*);
extern void* ld_last(void*);
extern void* ld_next(void*, void*);
extern void* ld_previous(void*, void*);
extern void* ld_last(void*);
extern void* ld_first(void*);
extern void ld_destroy(void*);
extern size_t ld_get(void*, void*, size_t, void*);
extern void* ld_insert_first(void*, size_t, void*);
extern void* ld_insert_last(void*, size_t, void*);
extern void* ld_insert_before(void*, void*, size_t, void*);
extern void* ld_insert_after(void*, void*, size_t, void*);
extern void* ld_delete_node(void*, void*);
extern size_t ld_total_free_memory(void*);
extern size_t ld_total_useful_memory(void*);
extern void* ld_add_memory(void*, size_t);
extern void* ld_compactify(void*);
extern void* dec_to_pointer(void*, ptrdiff_t);
extern void print_list(void* liste);
extern void create_data(int, int, align_data*);
extern void* get_node_at(void*, int);

#endif