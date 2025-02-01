/*!
  @file
  @brief Type declaration functions and macros.
  @ingroup type
*/

#ifndef VARS_TYPE_H
#define VARS_TYPE_H

/* Type definition */
struct v_type {
    char *name;                        /* Type name */
    char *code;                        /* Type code */

    void *(*create)();                 /* Creation function */
    void *(*copy)(void *);             /* Copy function */
    int (*next)(void *);               /* Iteration function */
    void (*print)(void *, FILE *);     /* Print function */
    void *(*read)(FILE *);             /* Read function */
    int (*write)(void *, FILE *);      /* Write function */
    int (*freeze)(void *, FILE *);     /* Freeze function */
    void *(*thaw)(FILE *);             /* Thaw function */
    void *(*yamlimport)();             /* Import-YAML function */
    void *(*yamlexport)();             /* Export-YAML function */
    void (*yamlcleanup)();             /* Cleanup-YAML function */
    int (*traverse)(void *, int (*)(void *));  /* Traversal function */
    void (*destroy)(void *);           /* Destruction function */
};

struct v_header {
    int magic;                         /* Magic number */
    struct v_type *type;               /* Variable type */
};

/*! @brief Variable-type type. */
typedef struct v_type vtype;

/*! @brief Type header type. */
typedef struct v_header vheader;

/* Include auxiliary type stuff */
#include <vars-debug.h>
#include <vars-destroy.h>
#include <vars-freeze.h>
#include <vars-iterate.h>
#include <vars-print.h>
#include <vars-traverse.h>
#include <vars-utils.h>
#include <vars-write.h>

#ifdef __cplusplus
extern "C" {
#endif

extern vtype *v_create(char *name, char *code);
extern void *v_create_object(char *code);
extern void v_declare(void);
extern vtype *v_find(char *code);
extern vtype *v_find_name(char *name);
extern vheader *v_header(vtype *t);
extern char *v_name(vtype *t);
extern char *v_ptrname(void *ptr);
extern vtype *v_type(void *ptr);
extern int v_unknown(void *ptr);

extern void v_copy_func(vtype *t, void *(*func)(void *));
extern void v_create_func(vtype *t, void *(*func)());
extern void v_destroy_func(vtype *t, void (*func)(void *));
extern void v_freeze_func(vtype *t, int (*func)(void *, FILE *));
extern void v_next_func(vtype *t, int (*func)(void *));
extern void v_print_func(vtype *t, void (*func)(void *, FILE *));
extern void v_read_func(vtype *t, void *(*func)(FILE *));
extern void v_thaw_func(vtype *t, void *(*func)(FILE *));
extern void v_traverse_func(vtype *t, int (*func)(void *, int (*)(void *)));
extern void v_write_func(vtype *t, int (*func)(void *, FILE *));
extern void v_yaml_import_func(vtype *t, void *(*func)());
extern void v_yaml_export_func(vtype *t, void *(*func)());
extern void v_yaml_cleanup_func(vtype *t, void (*func)());

#ifdef __cplusplus
}
#endif

#endif
