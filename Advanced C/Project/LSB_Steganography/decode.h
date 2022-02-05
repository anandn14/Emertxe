#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4
#define MAX_PASS_LENGTH 20
typedef struct _DecodeInfo
{
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* decoded file  Info */
    char *decode_fname;
    int secret_file_extn_size;
    char *secret_file_extention;
    int secret_file_size;
    FILE *fptr_decoded;
} DecodeInfo;


/* Encoding function prototype */

/* Read and validate Encode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_files_decode(DecodeInfo *decInfo);

/* Store Magic String */
Status decode_magic_string(int size, DecodeInfo *decInfo);

/* Decode secret file extenstion */
Status decode_secret_file_extn(DecodeInfo *decInfo);

/* Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

/* Decode function, which does the real decoding */
Status decode_data_from_image(int size, FILE *fptr_stego_image, FILE *fptr_decoded);

/* Decode a byte ifrom LSB of image data array */ 
Status decode_byte_from_lsb(int size, char *image_buffer);

/* Decode extension size and file size */
Status decode_size(FILE *fptr_stego_image);

/* Closing the files*/
Status dec_close_files(DecodeInfo *decInfo);
#endif
