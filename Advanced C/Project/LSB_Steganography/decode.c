#include <stdio.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"
#include <stdlib.h> 
#include <unistd.h> 


/* Function Definitions */

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
int num = 0, flag = 0, l = 0;
char ch, str_buffer[sizeof(MAGIC_STRING) + 3];    //<----- for magic string and file extention

Status open_files_decode(DecodeInfo *decInfo)   //<---- function definition for open files
{
    decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");   //<---- opening and reading the stego image file

    if (decInfo->fptr_stego_image == NULL)   //<---- validating the condition of stego file is NULL or not
    {
	perror("fopen");    //<----- error handling
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);

	return e_failure;
    }

    return e_success;    //<---- returning the success after opening the required files
}

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo)  //<---- function definition for decoding the process
{
    printf("INFO: Opening the requried files\n");
    sleep(1);
    if(open_files_decode(decInfo) == e_success) //<---- function calling for open file & validating the condition
    {   
	printf("INFO: Opened\n");
	sleep(1);
	printf("\n=== DECODING PROCEDURE STARTED ===\n\n");
	sleep(1);
	// parse 54B header
	rewind(decInfo -> fptr_stego_image);
	fseek(decInfo -> fptr_stego_image, 54, SEEK_SET);

	printf("INFO: Decoding the magic string\n");
	sleep(1);
	//function calling for decoding the magic string & validatong the condition
	if(decode_magic_string(strlen(MAGIC_STRING), decInfo) == e_success)
	{
	    printf("\nINFO: Done\n");
	    sleep(1);
	    printf("INFO: Decoding the file extension size\n");
	    sleep(1);
	    //function calling for decoding the file extention size and file size
	    if(decode_size(decInfo->fptr_stego_image) == e_success)
	    {
		printf("INFO: Done\n");
		sleep(1);
		decInfo->secret_file_extn_size = num;   //<--- assigning the secret file extention size 
		printf("INFO: size of extension is: %d bytes\n",num);
		sleep(1);
		printf("INFO: Decoding the file extension\n");
		sleep(1);
		//function calling for decoding the secret file extentiom & validating the condition
		if(decode_secret_file_extn(decInfo) == e_success)
		{
		    printf("\nINFO: Done\n");
		    sleep(1);
		    if ( decInfo->decode_fname != NULL )  //<--- validating the condition decoded file is NULL or not
			decInfo->fptr_decoded = fopen(decInfo->decode_fname, "w"); //<--creating decoded file as default name 
		    else
		    {
			decInfo->decode_fname = "output.txt"; //<---- assigning the decoded file nam as output.txt

			printf("INFO: default file with decoded extension created as %s\n", decInfo->decode_fname);
			sleep(1);
			decInfo->fptr_decoded = fopen(decInfo->decode_fname, "w");   //<--creating decoded file as defualt name
		    }
		    printf("INFO: Decoding the secret file size\n");
		    sleep(1);
		    //function calling for decoding secret file size & validating the condition
		    if(decode_size(decInfo -> fptr_stego_image) == e_success)
		    {
			printf("INFO: Done\n");
			sleep(1);
			decInfo->secret_file_size = num;    //<---- assigning the secret file size
			printf("INFO: size of secret file is: %d bytes\n",num);
			sleep(1);
			printf("INFO: Decoding the file data\n");
			sleep(1);
			//function calling for decoding the secret file data
			if(decode_secret_file_data(decInfo) == e_success)
			{
			    printf("INFO: Dnoe\n");
			    sleep(1);
			}
			else

			{
			    printf("ERROR: Decoding the secret file data is failure\n");
			    return e_failure;    
			}
		    }
		    else
		    {
			printf("ERROR: Decoding the secret file size failure\n");
			return e_failure;    
		    }
		}
		else
		{
		    printf("ERROR: Decoding the secret file extension failure\n");
		    return e_failure;    
		}
	    }
	    else
	    {
		printf("ERROR: Decoding size of extensiom failure\n");
		return e_failure;    
	    }
	}
	else
	{
	    printf("\nERROR: Magic string decoding failure, pass encoded .bmp file\n");
	    return e_failure; 
	}
    }
    else
    {
	printf("ERROR: Error in opening the required file\n");
	return e_failure;     
    }
    return e_success;      //<----- returning the success
}

/* Read and validate decode args from argv 
 * Input: command line arguments, source image, secret file name
 * Output: validate the command line arguments
 * Description: Read & validate the decode arguments for the argv
 * Return Value: e_success or e_failure, on file errors
 */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo) //<--- function definition for validate the args
{
    //stego image
    if (argv[2] != NULL && strstr(argv[2], ".bmp") != NULL ) //<--- validating the 2nd argument, checking the bmp file
	decInfo->stego_image_fname = argv[2];     //<---- assigning the 2nd position to the source image file
    else
    {
	printf("ERROR: Please enter the .bmp file\n");
	return e_failure;
    }
    //decoding file name
    if(argv[3] != NULL)
    {
	//ext_ptr=strstr(argv[3],".");
	if(strstr(argv[3],".txt") != NULL || strstr(argv[3],".c") != NULL)  //check if .txt or .c
	{
	    decInfo->decode_fname = argv[3];    //<---- assigning the rd position to the decoded file
	}
	else
	{   
	    printf("INFO : Output file must be of type '.txt' or '.c'\n");
	    return e_failure;
	}   
    }
    else
	decInfo->decode_fname = NULL;
    return e_success;    //<---- returning the success after read and validating arguments
}

/* Store Magic String
 * Input: magic string, stego image
 * Output: decoding the magic string
 * Return Value: e_success or e_failure, on file errors
 */
Status decode_magic_string(int size, DecodeInfo *decInfo) //<---- function definition for decoding the magic string
{
    printf("INFO: The magic string is: ");
    //function calling for encoding the data to image & validating the condition
    if(decode_data_from_image(strlen(MAGIC_STRING), decInfo -> fptr_stego_image, decInfo -> fptr_decoded) == e_success)
	str_buffer[l] = '\0';
    l = 0;
    if(strcmp(str_buffer, MAGIC_STRING) == 0 )     //<---- comparing the string of buffer and magic_string equal to 0
	return e_success;                       //<---- returning the success after magic string found ok
    else
	return e_failure;                    //<----- returning the failure if magic string not found
}

/* Decode function, which does the real decoding 
 * Input: size of the string length, source image, stego image   
 * Return Value: e_success after encoded 
 */
Status decode_data_from_image(int size, FILE *fptr_stego_image, FILE *fptr_decoded) //<-- function definitio for decoding img
{
    char image_buffer[8];
    for(int k = 0 ; k < size ; k++)      //<---- iteraing the size over the for loop
    {
	fread(image_buffer, 1, 8, fptr_stego_image);   //<------ reading the image buffer and  store it in stego image
	decode_byte_from_lsb(size, image_buffer);     //<----- function call to decode lsb bytes
	if(flag == 1)                                //<---- validating the condition of checking flag = 1
	    fputc(ch, fptr_decoded);                 //<---- writing the char into the decoded file
    }

    return e_success;         //<---- returning success after decoding the data to image
}

/* Decode a byte into LSB of image data array 
 * Input: size, char array or string
 * Output: decoding the lsb bit to decoding the secret data
 * Description: To decoding the secret data each bit of #(magic string) from 1 byte of LSb data
 */
Status decode_byte_from_lsb(int size, char *image_buffer) //<--- function definition for decode byte from lsb
{
    int i;
    ch = 0 ;
    ch = ch | (image_buffer[0] & 0x01);  //<---- image buffer and with 1 and it shld or with ch and stored in ch
    for( i = 1 ; i < 8 ; i++ )
    {
	ch = ch << 1;                       //<---- 1 left shift with ch and store in ch
	ch |= (image_buffer[i] & 0x01);
    }

    if(flag == 0)                  //<----- validating the condition of checking flag = 0
    {
	printf("%c", ch);
	str_buffer[l] = ch;       //<---- store ch in str_buffer
	l++;                     //<---- increment l
    }
}

/* Decode extension size, secret file size
 * Input: secret file length, source iamge, stego image
 * Output: decode the secret file size and file size extention
 * Return Value: e_success on file errors
 */
Status decode_size(FILE *fptr_stego_image) //<--- function definition for encode size
{
    char image_buffer[32];
    fread(image_buffer, 1, 32, fptr_stego_image);    //<------ reading the image buffer
    num |= (image_buffer[0] & 0x01);      //<----- image buffer ANDing with 1 then Oring with num and storing in the num
    for(int i = 0 ; i < 32 ; i++)
    {
	num = num << 1 ;                   //<----- num left shift by 1 and store num
	num |= (image_buffer[i] & 0x01);   //<---- image buffer ANDing with 1 then ORing with num and storing in num
    }
    return e_success; 	       //<---- return success after decoding size			       
}

/* Decode secret file extenstion 
 * Input: secret file size,stego image, decoded fiel
 * Return Value: e_success on file errors
 */
Status decode_secret_file_extn(DecodeInfo *decInfo) //<---- function definition for encoding the secret file extn
{
    printf("INFO: The decoded file extention is: ");
    //function calling for decoding the data from image
    if(decode_data_from_image(num, decInfo -> fptr_stego_image, decInfo -> fptr_decoded) == e_success)
	return e_success;    //<---- returning success after dencoding the secret file extention
}

/* Decode secret file data
 * Input: secret file size (structure), stego image, decoded file
 * Output: decoded secret file data
 * Return Value: e_success after decoded
 */
Status decode_secret_file_data(DecodeInfo *decInfo) //<---- function definition for decode secret file data
{
    flag++;
    rewind(decInfo->fptr_decoded);    //<---- rewinding the decoded file
    // function calling for decoding thedata from image
    if(decode_data_from_image(num, decInfo -> fptr_stego_image, decInfo -> fptr_decoded) == e_success)
	return e_success;   //<---- returning the success after decoding the secret file data
}

/* Closing the opened file 
 * Input: stego image file, decoded file
 */
Status dec_close_files(DecodeInfo *decInfo)  //<---- function definition for closing the files
{
    fclose(decInfo->fptr_stego_image);   //<----- cloaing the stego image
    fclose(decInfo->fptr_decoded);     //<--- closing the decoded file
}
