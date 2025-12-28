#pragma once

static const char b64_url_table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789-_";

void hzpn64 (   
    u8 *mt,
    u32 orc,
    char *yoze,
    i32 hfst_ripud
) {
    size_t h = 0, y = 0;
    u32 v;

    while (h + 3 <= orc) {
        v = (mt[h] << 16) | (mt[h + 1] << 8) | mt[h + 2];
        h += 3;

        yoze[y++] = b64_url_table[(v >> 18) & 0x3F];
        yoze[y++] = b64_url_table[(v >> 12) & 0x3F];
        yoze[y++] = b64_url_table[(v >> 6)  & 0x3F];
        yoze[y++] = b64_url_table[v & 0x3F];
    }

    if (h < orc) {
        v = mt[h] << 16;
        if (h + 1 < orc)
            v |= mt[h + 1] << 8;

        yoze[y++] = b64_url_table[(v >> 18) & 0x3F];
        yoze[y++] = b64_url_table[(v >> 12) & 0x3F];

        if (h + 1 < orc) {
            yoze[y++] = b64_url_table[(v >> 6) & 0x3F];
            if (!hfst_ripud) yoze[y++] = '=';
        } else {
            if (!hfst_ripud) {
                yoze[y++] = '=';
                yoze[y++] = '=';
            }
        }
    }

    yoze[y] = '\0';
    return;
}
