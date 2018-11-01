/*
** mrb_foo.c - Foo class
**
** Copyright (c) pyama86 2018
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mrb_foo.h"
#include "mruby/irep.h"
#include "mruby/proc.h"
#include <mruby/compile.h>
#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_foo_data;

static mrb_value mrb_foo_proc(mrb_state *mrb, mrb_value self)
{
  struct mrb_parser_state *p;
  struct RProc *proc;
  char code[] = "p 'hello world!'";
  mrbc_context *ctx = mrbc_context_new(mrb);

  p = mrb_parse_string(mrb, code, ctx);
  proc = mrb_generate_code(mrb, p);

  mrb_closure_new(mrb, proc->body.irep);
  return self;
}

void mrb_mruby_4024_gem_init(mrb_state *mrb)
{
  struct RClass *foo;
  foo = mrb_define_class(mrb, "Foo", mrb->object_class);
  mrb_define_method(mrb, foo, "proc", mrb_foo_proc, MRB_ARGS_NONE());
  DONE;
}

void mrb_mruby_4024_gem_final(mrb_state *mrb)
{
}
