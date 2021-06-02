#include <stdio.h>
#include <mysql/mysql.h>
#include <error.h>

int main()
{
	MYSQL mysql;
	if(NULL == mysql_init(&mysql)){
   
		printf("mysql_init");
	}

	if(mysql_library_init(0, NULL, NULL) != 0){
   
		printf("mysql_library_init");
	}

	if(NULL == mysql_real_connect(&mysql, "127.0.0.1", "root", "1551097460", "test", 0, NULL, 0)){
   
		printf("mysql_real_connect");
	}

	if(mysql_set_character_set(&mysql, "utf8") < 0){
   
		printf("mysql_set_character_set");
	}

    	printf("连接mysql数据库成功!\n");

	int id=1;
	char buf[100];
	sprintf(buf, "select id from stu_info where id = %d", id);
	
    int ret =  mysql_query(&mysql,buf);
    if(ret)
        perror("query fail");

    MYSQL_RES *result = mysql_store_result(&mysql);
    unsigned int num_fields = mysql_num_fields(result);

    MYSQL_FIELD *field;
  /*  while ( (field = mysql_fetch_field(result)))
	    printf("%-20s", field->name);

    printf("\n");
    MYSQL_ROW row;
    while (row = mysql_fetch_row(result)) 
    {
   
	    for (int i = 0; i < num_fields; i++)
		    printf("%-20s", row[i]);
	    printf("\n");
    }*/

	MYSQL_ROW row = mysql_fetch_row(result);
		
	if(row != NULL)
		printf("%s\n", row[0]);
	else
	printf("no");

	mysql_close(&mysql);
	mysql_library_end();

	return 0;
}
