/*************************************************************************
	> File Name: 01_option.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年10月29日 星期六 20时41分36秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

/*
 * struct option{
 * 	const char *name;//选项名
 * 	int has_arg;//是否有参数，如果有是那种参数
 * 	int *flag;//若为NULL，则返回val的值，否则将val的值写入指定位置返回0
 * 	int val;//长选项的返回值，或者flag中的填充值
 * }
 *
 */

void print_usage(const char *program_name)
{
	printf("%s 1.0.0 (2016-10-29)\n",program_name);
	printf("This is a program decoding a BER encoded CDR file\n");
	printf("Usage: %s -f <file_name> -o <output_name> [-c <config_name>] [-k <keyword>]\n", program_name);
	printf("    -f --file       the CDR file to be decoded\n");
	printf("    -o --output     the output file in plain text format\n"); 
	printf("    -c --config     the description file of the CDR file, if not given, use default configuration\n");
	printf("    -k --keyword    the keyword to search, if not given, all records will be written into output file\n");
}

int main(int argc,char *argv[])
{
	char *file_name = NULL;
	char *output_name = NULL;
	char *config_name = NULL;
	char *keyword = NULL;

	printf("argc:%d,optind:%d\n",argc,optind);

	const char *short_opts = "hf:o:c:k:";
	const struct option long_opts[]={
		{.name="help",.has_arg=no_argument,.val='h'},
		{.name="file",.has_arg=required_argument,.val='f'},
		{.name="output",.has_arg=required_argument,.val='o'},
		{.name="config",.has_arg=required_argument,.val='c'},
		{.name="keyword",.has_arg=required_argument,.val='k'},
		{.name=NULL,.has_arg=0,.val='\0'}
	};

	int hflag=0;

	int c=0;
	int opterr = 0;
	//while((c=getopt_long(argc,argv,short_opts,long_opts,NULL))!=-1){
	while(1){
		c=getopt_long(argc,argv,short_opts,long_opts,NULL);
		if(c == -1)
			break;
		switch(c){
			case 'h':
				hflag = 1;
				break;
			case 'f':
				file_name = optarg;
				printf("File Name:%s\n",file_name);
				break;
			case 'o':
				output_name = optarg;
				printf("Output File Name:%s\n",output_name);
				break;
			case 'c':
				config_name = optarg;
				printf("Config File Name:%s\n",config_name);
				break;
			case 'k':
				keyword = optarg;
				printf("Keyword:%s\n",keyword);
				break;
			default:
				printf("Error:unknown option.\n");
		}
	}

	printf("argc:%d,optind:%d\n",argc,optind);
	if(optind < argc){
		printf("Error option.\n");
	}

	if(hflag || argc == 1){
		print_usage(argv[0]);
		return 0;
	}

	return 0;
}

