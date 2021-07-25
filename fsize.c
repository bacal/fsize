#include <stdio.h>
#include <getopt.h>

void print_file_size(char* file_path);

int main(int argc, char* argv[])
{
	int option;
	if(argc ==1)
		return -1;
	while((option = getopt(argc, argv, ":b:")) != -1){
		switch(option){
			case 'b':
				break;
			case ':':
				print_file_size(optarg);
				break;
			default:
				fprintf(stderr,"fsize: invalid arguement\n");
				return 1;
				break;
		}
	}

	for (int index = optind; index < argc; index++){
		//fprintf(stdout, "Args: %s\n",argv[index]);
		print_file_size(argv[index]);
	}

	return 0;
}

void print_file_size(char* file_path){
	if(!file_path)
		return;
	FILE* fp;
	fp = fopen(file_path,"r");
	if(!fp){
		fprintf(stderr, "Error: Failed to open file %s\n",file_path);
	}
	fseek(fp,0,SEEK_END);
	printf("%ld\t%s\n", ftell(fp),file_path);
	fclose(fp);
}
