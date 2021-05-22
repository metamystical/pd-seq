#include "m_pd.h"

t_class *seq_class;

typedef struct seq {
  t_object x_obj;
  t_inlet *in;
  t_outlet *out;
  int base;
  int size;
} t_seq;

void seq_bang (t_seq *x) {
  for (int i = 0; i < x->size; i++) outlet_float(x->out, (float)(x->base + i));
}

void seq_base (t_seq *x, t_floatarg f) {
  x->base = (int)f;
}

void seq_checkSize (t_seq *x) {
  if (x->size < 0) {
    x->size = 0;
    error("[seq ]: size < 0; setting to 0");
  }
}

void seq_size (t_seq *x, t_floatarg f) {
  x->size = (int)f;
  seq_checkSize(x);
}

void *seq_new (t_floatarg base, t_floatarg size) {
  t_seq *x = (t_seq *)pd_new(seq_class);
  // leftmost inlet automatically created (and freed)
  x->in = inlet_new(&x->x_obj, &x->x_obj.ob_pd, &s_float, gensym("size"));
  x->out = outlet_new(&x->x_obj, &s_float);
  x->base = (int)base;
  x->size = (int)size;
  seq_checkSize(x);
  return (void *)x;
}

void seq_free(t_seq *x) {
  inlet_free(x->in);
  outlet_free(x->out);
}

void seq_setup(void) {
  seq_class = class_new(gensym("seq"), (t_newmethod)seq_new, (t_method)seq_free,
    sizeof(t_seq), CLASS_DEFAULT, A_DEFFLOAT, A_DEFFLOAT, 0);
  class_addbang(seq_class, (t_method)seq_bang);
  class_addfloat(seq_class, (t_method)seq_base);
  class_addmethod(seq_class, (t_method)seq_size, gensym("size"), A_DEFFLOAT, 0);
}
