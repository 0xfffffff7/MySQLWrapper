
#include	"mysqlwrapper.h"

// MYSQL TABLE EXAMPLE
//Å@ CREATE TABLE book
//    (
//    id INT(11) NOT NULL AUTO_INCREMENT,
//    title VARCHAR(64),
//    author_name VARCHAR(32),
//    detail TEXT,
//    PRIMARY KEY (id)
//    );

int main(int argc, char* argv[])
{
	char *server = "localhost";
	char *user = "root";
	char *password = "password";
	char *database = "myapp";

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

	__int64 nRows = sql.getRowCount();

	MYSQL_ROW row;
	while( (row = sql.getRow()) != NULL ){
	//for(__int64 n = 0; n < nRows; n++){
		
		printf("%s %s %s\n", row[0], row[1], row[2]);
	}
	sql.clear();


	sql.close();

	return 0;
}

