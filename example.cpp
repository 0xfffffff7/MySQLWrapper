
#include	"mysqlwrapper.h"

// MYSQL TABLE EXAMPLE
//　 CREATE TABLE book
//    (
//    id INT(11) NOT NULL AUTO_INCREMENT,
//    title VARCHAR(64),
//    author_name VARCHAR(32),
//    detail TEXT,
//    PRIMARY KEY (id)
//    );

int main(int argc, char* argv[])
{
	const char *server = "localhost";
	const char *user = "root";
	const char *password = "password";
	const char *database = "myapp";

	MySqlWrapper sql;

	sql.init();
	
	if(sql.connect(server, user, password, database) == false){
		printf("error %s\n", sql.getError());
		return 0;
	}

	if( sql.query("DELETE FROM book;") == false){
		printf("error %s\n", sql.getError());
		return 0;
	}
	sql.clear();

	if( sql.query("INSERT INTO book (title, author_name) VALUES ('book_A', 'auth_A');") == false){
		printf("error %s\n", sql.getError());
		return 0;
	}
	sql.clear();
	if( sql.query("INSERT INTO book (title, author_name) VALUES ('book_B', 'auth_B');") == false){
		printf("error %s\n", sql.getError());
		return 0;
	}
	sql.clear();

	if( sql.query("SELECT * FROM book;") == false){
		printf("error %s\n", sql.getError());
		return 0;
	}

	long long nRows = sql.getRowCount();

	MYSQL_ROW row;
	while( (row = sql.getRow()) != NULL ){		
		printf("%s %s %s\n", row[0], row[1], row[2]);
	}
	sql.clear();


	sql.close();

	return 0;
}

