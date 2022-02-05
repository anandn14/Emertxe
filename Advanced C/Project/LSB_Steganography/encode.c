#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include <stdlib.h> 
#include <unistd.h> 


/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
int ext_len = 0;
uint get_image_size_for_bmp(FILE *fptr_image)  //<--- function definition for get image size
{
    uint width, height;
    fseek(fptr_image, 18, SEEK_SET);    //<---- seek to 8th byte

    fread(&width, sizeof(int), 1, fptr_image);   //<----- reading the width
    printf("width = %u\n", width);

    fread(&height, sizeof(int), 1, fptr_image);  //<----- reading the height
    printf("height = %u\n", height);

    return width * height * 3;     //<----- returnong the image capacity after getting
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)   //<---- function definition for open files
{
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");   //<---- opening and reading the source file

    if (encInfo->fptr_src_image == NULL)   //<---- validating the condition of source file is NULL or not
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

	return e_failure;
    }

    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");   //<----- opening and reading the secret file 

    if (encInfo->fptr_secret == NULL)    //<---- validating the condition of secret file NULL or not
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

	return e_failure;
    }

    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");//<- opening the stego image file if not present it will create the file

    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

	return e_failure;
    }

    return e_success;    //<---- returning the success after opening the required files
}

/* Check operation type 
 * Input: command line arguments
 * output: validating first position command line arguments 
 * Descripton: for checking the operation type encoding or decoding process
 * Return Value: e_success or e_failure, on file errors
 */
OperationType check_operation_type(char *argv[])  //<---- function definition for check operation type
{
    if( strcmp( argv[1], "-e" ) == 0 )    //<--- validating & string checking the 1st argument position as -e for encoding
	return e_encode;
    else if( strcmp( argv[1], "-d" ) == 0 )  //<--- validating & string checking the 1st argument position as -d for decoding
	return e_decode;
    else
    {
	printf( "ERROR: operation type failure\n" );
	return e_unsupported;  ///<---- returning the unsupported file
    }
}

/* Get file size
 * Input: Secret file ptr
 * Output: size of the file
 * Return Value: file size
 */
uint get_file_size(FILE *fptr)  //<---- function definiton for get file size
{
    int size;
    fseek(fptr, 0, SEEK_END);   //<---- file pointer move from 0 position to end position 
    size = ftell(fptr);        //<---- getting the total size of the file
    rewind(fptr);             //<--- moves the file pointer to the beginning of the file
    return size;             //<----- returning the size value
}

/* check capacity 
 * Input: source image, secret file
 * Output: checking size of the secret file then comparing with the source file
 * Description: To chechk wather the secret file will be greater than original file
 * Return Value: e_success or e_failure, on file errors
 */
Status check_capacity(EncodeInfo *encInfo)  //<--- function definition for checking image capacity
{
    char *ext_ptr = strstr(encInfo -> secret_fname, ".");
    for( ext_len = 0; ext_len <= 4; ext_len++ )          //<---- iterating the 4 bytes iover the for loop
    {   
	encInfo -> extn_secret_file[ext_len] = *ext_ptr++;
    }   
    ext_len = strlen(encInfo -> extn_secret_file);                //<--- finding the length of the string in secret file
    fseek(encInfo -> fptr_secret, 0, SEEK_END);                  //<---- seeking the end of the file starting from 0
    encInfo -> size_secret_file = ftell(encInfo -> fptr_secret);
    int enc_req_size =( 54 + 2 * (ext_len * 8 ) + ( strlen(MAGIC_STRING) * 8 ) + ( encInfo -> size_secret_file * 8 ) + 32 );    
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);  //<---- function calling for getting the image size
    printf("INFO: Source Image capacity = %u bytes\n",encInfo->image_capacity);
    sleep(1);
    if(encInfo -> image_capacity >= enc_req_size)   //<--- comapring image camacity is greater than equal to required size
	return e_success;    //<---- returning the success after checking the capacity
    else
	return e_failure;   //<---- returning failure if not enough of image capacity
}

/* Copy bmp image header
 * Input: source image & destination image
 * Output: copy the image header from source to destination imagei
 * Description: To copy the first 54 butes of header from bmp to destination image
 * Return Value: e_success or e_failure, on file errors
 */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image) //<--- function definition for copy bmp header
{
    char buffer[54];
    rewind(fptr_src_image);                      //<---- rewinding the source image
    fread(buffer, 1, 54, fptr_src_image);       //<---- reading 54 bytes from source (.bmp) file
    fwrite(buffer, 1, 54, fptr_dest_image);    //<----- writing 54 bytes into destination (stego.bmp) file
    fseek(fptr_dest_image, 0, SEEK_END);      //<----- seek end to the end of destinaltion (stego.bmp) file
    if(ftell(fptr_dest_image) == 54)         ///<---- validating the dest image file copied the header or not                             
	return e_success;	       //<---- returning the suceess after copying the header
    else
	return e_failure;             //<----- retruning the failure if not copied
}

/* Perform the encoding */
Status do_encoding(EncodeInfo *encInfo)  //<---- function definition for encoding the process
{
    printf("INFO: opening the requried files\n");
    sleep(1);
    if(open_files(encInfo) == e_success) //<---- function calling for open file & validating the condition
    {
	printf("INFO: Opened\n");
	sleep(1);
	printf("INFO: Checking image capacity\n");
	sleep(1);
	if(check_capacity(encInfo) == e_success)  //<---- function calling for check capacity & validating the condition
	{
	    printf("INFO: Check capacity Done\n");
	    sleep(1);
	    printf("\n=== ENCODING PROCEDURE STARTED ===\n\n");
	    sleep(1);
	    printf("INFO: copying the header file from bmp file\n");
	    sleep(1);
	    //function callinf for copy the bmp header & validating the condition
	    if(copy_bmp_header(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
	    {
		printf("INFO: Done\n");
		sleep(1);
		printf("INFO: Encoding the magic string\n");
		sleep(1);
		//function calling for encoding the magic string & validatong the condition
		if(encode_magic_string(MAGIC_STRING, encInfo) == e_success)
		{
		    printf("INFO: Done\n");
		    sleep(1);
		    printf("INFO: Encoding the file extension size\n");
		    sleep(1);
		    //function calling for encoding the file extention size and file size
		    if(encode_size(strlen(".txt"), encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
		    {
			printf("INFO: Done\n");
			sleep(1);
			printf("INFO: Encoding the file extension\n");
			sleep(1);
			//function calling for encoding the secret file extentiom & validating the condition
			if(encode_secret_file_extn(encInfo->extn_secret_file,encInfo) == e_success)
			{
			    printf("INFO: Done\n");
			    sleep(1);
			    printf("INFO: Encoding the secret file size\n");
			    sleep(1);
			    //function calling for secret file size & validating the condition
			    if(encode_secret_file_size(encInfo -> size_secret_file, encInfo) == e_success)
			    {
				printf("INFO: Done\n");
				sleep(1);
				printf("INFO: Encoding the file data\n");
				sleep(1);
				//function calling for encoding the secret file data
				if(encode_secret_file_data(encInfo) == e_success)
				{
				    printf("INFO: Done\n");
				    sleep(1);
				    printf("INFO: Copying the remaining image file data\n");
				    sleep(1);
				    //function calling for copyig the remaining data from source to dest image
				    if(copy_remaining_img_data(encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
				    {
					printf("INFO: Done\n");
					sleep(1);
				    }
				    else
				    {
					printf("ERROR: copying the remaining image data failure\n");	
				    }
				}
				else
				{
				    printf("ERROR: Encoding the secret file data is failure\n");
				}
			    }
			    else
			    {
				printf("ERROR: Encoding the secret file size failure\n");
			    }
			}
			else
			{
			    printf("ERROR: Encoding the secret file extension failure\n");
			}
		    }
		    else
		    {
			printf("ERROR: Encoding size of extensiom failure\n");
		    }
		}
		else
		{
		    printf("ERROR: Magic string encoding failure\n");
		}
	    }
	    else
	    {
		printf("ERROR: Copy of image header failure\n");
	    }
	}
	else
	{
	    printf("ERROR: Check capacity is failure\n");
	}
    } 
    else
    {
	printf("ERROR: Error in opening the required file\n");
    }
    return e_success;      //<----- returning the success after enceded
}

/* Read and validate Encode args from argv 
 * Input: command line arguments, source image, secret file name
 * Output: validate the command line arguments
 * Description: Read & validate the encode arguments for the argv
 * Return Value: e_success or e_failure, on file errors
 */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo) //<--- function definition for validate the args
{
    // for source image
    if ( argv[2] != NULL && strstr(argv[2], ".bmp") != NULL ) //<--- validating the 2nd argument, checking the bmp file
	encInfo->src_image_fname = argv[2];     //<---- assigning the 2nd position to the source image file
    else
    {
	printf("ERROR: Please enter the .bmp file\n");
	return e_failure;
    }

    // for secret file name
    if( argv[3] != NULL && (strstr(argv[3],".txt") != NULL || strstr(argv[3],".c") != NULL ))//<--- validating the 2nd argument, checking the .txt or .c file
	encInfo->secret_fname = argv[3];    //<---- assigning the rd position to the secret file
    else
    {
	printf("ERROR: Please pass secret file name of typr '.txt' or '.c'\n");
	return e_failure;
    }
    if( argv[4] != NULL )   //<---- validating condition of the the 4th argument
    {
	if( strstr(argv[4],".bmp") != NULL )   //<--- valiating & checking the 4th argument .bmp file
	    encInfo->stego_image_fname = argv[4];  //<---- assigniing the 4th position to the stego image file
	else
	{
	    printf("ERROR: Please enter the .bmp file name for encoded output file name\n");
	    return e_failure;  
	}
    }
    else
    {
	encInfo->stego_image_fname = "stego_img.bmp";     //<--- if not passed the stego file i t will create the dest file
	printf("INFO: Encoded file Created as %s\n", encInfo->stego_image_fname);
	sleep(1);
    }
    return e_success;    //<---- returning the success after read and validating arguments
}

/* Store Magic String
 * Input: magic string, soource image & stego image
 * Output: encoding the magic string
 * Return Value: e_success or e_failure, on file errors
 */
Status encode_magic_string(const char *magic_string, EncodeInfo *encInfo) //<---- function definition for encoding the magic string
{
    //function calling for encoding the data to image & validating the condition
    if(e_success == encode_data_to_image (MAGIC_STRING, strlen(MAGIC_STRING), encInfo -> fptr_src_image, encInfo -> fptr_stego_image))
	return e_success;    //<--- returning the success after endonig the magic string
    else
	return e_failure;   //<---- returning the failure if no encodede the magic string
}

/* Encode function, which does the real encoding 
 * Input: size of the string length, source image, stego image   
 * Return Value: e_success after encoded 
 */
Status encode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image) //<-- function definitio for encoding img
{
    char image_data[8];
    for(int i = 0; i < size; i++) //<--- iterating the string length over the for loop        
    {
	fread(image_data, 1, 8, fptr_src_image);      //<---- reading the image size 
	encode_byte_to_lsb(data[i], image_data);      //<-----function call to encode bytes to lsb
	fwrite(image_data, 1, 8, fptr_stego_image);   //<---- writing the data in stego image
    }	
    return e_success;         //<---- returning success after encoding the data to image
}

/* Encode a byte into LSB of image data array 
 * Input: data, char array or string
 * Output: encoding the lsb bit to store the secret data
 * Description: To store each bit of #(magic string) into 1 byte of LSb data
 * Return Value: e_success on file errors
 */
Status encode_byte_to_lsb(char data, char *image_buffer) //<--- function definition for encode byte to lsb
{
    char bit;                      //<----- declared the char type bit
    for(int i = 0; i < 8; i++ )
    {
	image_buffer[i] &= 0xFE;   //<--- ANDing image_buffer element with FE and store in image_buffer
	bit = (data >> (7 - i)) & 1; //<--- data tiems right shifting of bits the then ANDing with the 1 and storing in bit
	image_buffer[i] |= bit;   //<---- image_buffer element ORing with FE and store in image buffer
    }
    return e_success; 	//<---- returning the e_success after encoding the byte to lsb			         
}

/* Encode extension size and file size
 * Input: secret file length, source iamge, stego image
 * Output: encoded the secret file size and source file size
 * Return Value: e_success on file errors
 */
Status encode_size(int size, FILE *fptr_src_image, FILE *fptr_stego_image) //<--- function definition for encode size
{
    char image_buffer[32], data[32];
    int i, bit;
    fread(image_buffer, 1, 32, fptr_src_image);    //<---- reading the image buffer pointed by the source image
    for(int i = 0 ; i < 32 ; i++)
    {
	image_buffer[i] &= 0xfe;    //<---- image buffer ANDIng with FE and storing back to the image buffer
	bit = ( size >> ( 31 - i )) & 1;  //<---- size right shift the ANDing with the 1
	image_buffer[i] |= bit;      //<----- image buffer ORing with the bit
    }
    fwrite(image_buffer, 1 , 32, fptr_stego_image);    //<----- writing the image buffer data in stego image

    return e_success; 	       //<---- return success after encoding size			       
}

/* Encode secret file extenstion 
 * Input: file extention, source image, stego image
 * Return Value: e_success or e_failur on file errors
 */
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo) //<---- function definition for encoding the secret file extn
{
    // function calling for encoding the data to image
    if(encode_data_to_image(file_extn, ext_len, encInfo->fptr_src_image, encInfo->fptr_stego_image) == e_success)
	return e_success;    //<---- returning success after encoding the secret file extention
    else
	return e_failure;
}

/* Encode secret file size
 * Input: secret file size, source image & stego image
 * Output: encoded secter file size
 * Return Value: e_success or e_failur on file errors
 */
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo) //<---- function definition for encode secret file size
{
    // function calling for encoding size and & validating the condition
    if(encode_size(file_size, encInfo -> fptr_src_image ,encInfo -> fptr_stego_image) == e_success)
	return e_success;         //<--- returnig the success after encoding the secret file soze
    else
	return e_failure;
}


/* Encode secret file data
 * Input: secret file size (structure)
 * Output: encoded secret file data
 * Return Value: e_success after encoded
 */
Status encode_secret_file_data(EncodeInfo *encInfo) //<---- function definition for encode secret file data
{
    int size;
    fseek(encInfo -> fptr_secret, 0, SEEK_END);   //<--- seek to 0th byte from secret file 
    size = ftell(encInfo -> fptr_secret);       //<---- storing the secret file size in the variable size
    rewind(encInfo -> fptr_secret);             //<------ rewinding the secret file
    char buffer[size];
    fread(buffer, 1, size, encInfo -> fptr_secret);  //<-- reading the data fropm secret file
    encode_data_to_image(buffer, size, encInfo -> fptr_src_image, encInfo -> fptr_stego_image); // function callin for encodig image data 
    return e_success;   //<---- returning the success after encoding the secret file data
}

/* Copy remaining image bytes from src to stego image after encoding 
 * Input: source file & destination file
 * Output:copied the data into the destination file
 * Return Value: e_success after copied the data
 */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest) //<---- function definiton for copy remaining image data
{
    char ch;

    while(fread(&ch, 1, 1, fptr_src) > 0)  //<--- reading the source file to till the EOF
    {
	fwrite(&ch, 1, 1, fptr_dest);   //<--- writing into the destination file
    }
    return e_success;    //<----- returning the success after copying the data
}
Status close_files(EncodeInfo *encInfo)   //<---- functiondefinition for closing the files
{
    fclose(encInfo->fptr_src_image);   //<---- closing the source image file
    fclose(encInfo->fptr_secret);     //<---- closing the secret image file
    fclose(encInfo->fptr_stego_image);  //<--- closing the stego image file
    return e_success;
}
