# makefile for Parsing_HTTP_server_logs
Parsing_HTTP_server_logs: 
	gcc  -Wall -Wextra -Wpedantic -std=c11 -o Parsing_HTTP_server_logs Parsing_HTTP_server_logs.c hash_table.c thread_data.c parse_functions.c	-pthread -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lgthread-2.0 -pthread -lglib-2.0	

