#include <stdio.h>
#include <stdlib.h>
#include "gifdec.h"

int main(int argc, char *argv[]) {
    gd_GIF *gif;
    uint8_t *frame;
    int ret;
    uint8_t *buf = NULL;

    gif = gd_open_gif(buf);
    if (!gif) {
        fprintf(stderr, "Could not open gif");
        return 1;
    }
    frame = (uint8_t*) malloc(gif->width * gif->height * 3);
    if (!frame) {
        fprintf(stderr, "Could not allocate frame\n");
        return 1;
    }
    while (1) {
        ret = gd_get_frame(gif);
        if (ret == -1)
            break;
        gd_render_frame(gif, frame);
        if (ret == 0)
            gd_rewind(gif);
        // delay = gif->gce.delay * 10;
    }
    gd_close_gif(gif);
    free(frame);
    return 0;
}
