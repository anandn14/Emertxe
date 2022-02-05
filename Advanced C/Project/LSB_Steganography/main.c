#include <stdio.h>
#include "encode.h"
#include "decode.h"
#include "types.h"
#include "common.h"
#include <unistd.h>
int main(int argc, char **argv)
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;
    /*Check operation type*/
    if(check_operation_type(argv) == e_encode)   //<----- validating the condition foe checking the operation type
    {
	printf("INFO: Data encoding started\n");
	sleep(1);
	if (read_and_validate_encode_args(argv,&encInfo) == e_success) //<---- validating the condition of read and validate
	{
	    printf("INFO: read and validate is succussfull\n");
	    sleep(1);
	    if ( do_encoding(&encInfo) == e_success)      //<--- validating the condition encoding
	    {
		printf("\n==== ENCODING DONE SUCCESSFULLY ====\n");
	    }
	    else
	    {
		printf("ERROR: Encoding is failure\n");
	    }
	}
	else
	{
	    printf("ERROR: Validation is failure\n");
	}
    }
    else if(check_operation_type(argv) == e_decode) //<----- validating the condition checking operation type
    {
	printf("INFO: Data decoding started\n");
	sleep(1);
	if (read_and_validate_decode_args(argv,&decInfo) == e_success)   //<---- validating the condition read and validate
	{
	    printf("INFO: read and validate is succussfull\n");
	    sleep(1);
	    if ( do_decoding(&decInfo) == e_success)   //<---- validating the condition decoding
	    {
		printf("\n==== DECODING DONE SUCCESSFULLY ====\n");
	    }
	    else
	    {
		printf("ERROR: Decoding is failure\n");
	    }
	}
	else
	{
	    printf("ERROR: Validation is failure\n");
	}
    }
    else
    {
	printf("ERROR: unsupported format\n");
    }
}

