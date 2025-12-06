#include "kernel/types.h"
#include "pipe.h"
#include "kmalloc.h"
#include "process.h"
#include "page.h"
#include "fs.h"
#include "fs_internal.h"
#include "console.h"
#include "kobject.h"
#include "kmalloc.h"
#include "string.h"
#include "device.h"
#include "fs.h"
#include "window.h"
#include "console.h"
#include "pipe.h"
#include "named_pipe.h"
#include "kernel/error.h"

#define PIPE_SIZE PAGE_SIZE

struct named_pipe {
	struct fs_dirent *f;
	char *fname;
};

struct named_pipe *named_pipe_create(struct fs_dirent *file, const char *filename) {
	/* Allocate memory for the named pipe*/
	struct named_pipe *p = kmalloc(sizeof(*p));
	if (!p) return 0;

	/* Put reference to the file inside the named pipe */
	p->f = file;
	/* Put the file's name inside named pipe, so that when the file is opened for the second time, it can be detected and retrieved from the local ktable */
	p->fname = filename;
	return p;
}

/* Reads from the file referenced in teh attribute */
int named_pipe_read(struct named_pipe *p, char *buffer, uint32_t length, uint32_t offset) {
	//printf("   dsize is: %d\n", (p->f)->size);
	//printf("   offset is: %d\n", offset);
	//printf("   size of the buffer (length) is: %d\n", length);
	return fs_dirent_read(p->f, buffer, length, offset);
}

/* Writes to the file referenced in the attribute */
int named_pipe_write(struct named_pipe *p, const char *buffer, uint32_t length, uint32_t offset) {
	return fs_dirent_write(p->f, (char *) buffer, (uint32_t) length, offset);
}
