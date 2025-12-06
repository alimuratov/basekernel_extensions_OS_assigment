#include "kernel/types.h"

struct named_pipe *named_pipe_create();
int named_pipe_read(struct named_pipe *p, char *buffer, uint32_t length, uint32_t offset);
int named_pipe_write(struct named_pipe *p, const char *buffer, uint32_t length, uint32_t offset);
