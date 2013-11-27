MySQLWrapper for C++
============

#Install MySQL.
install mysql and mysql-devel.  
Please install the mysql-devel and mysql using the package management commands.  

Please Create a MySQL User, create databases and tables.

#example.cpp setting

mysql user "root"  
password  "password"  

DATABASE NAME  "myapp"  

MYSQL TABLE EXAMPLE  
 CREATE TABLE book  
 (  
 id INT(11) NOT NULL AUTO_INCREMENT,  
 title VARCHAR(64),  
 author_name VARCHAR(32),  
 detail TEXT,  
 PRIMARY KEY (id)  
);  

#compile example
gcc -lstdc++ example.cpp mysqlwrapper.cpp -o example -I/usr/include/mysql/ -L/usr/lib64/mysql/ -lmysqlclient


