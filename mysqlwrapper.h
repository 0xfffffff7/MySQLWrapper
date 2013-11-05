#include	"my_global.h"
#include	"mysql.h"
#include	<string>

#define	LOCK_MODE_READ	1
#define	LOCK_MODE_WRITE	2

#define	MYSQL_TIMEOUT 1000000

class MySqlWrapper
{
public:
	MySqlWrapper();
	~MySqlWrapper();

public:
	bool init();
	bool connect(char *host, char *user, char *password, char *dbname);
	bool isConnect();
	bool close();
	bool query(const char *pQuery);
	MYSQL_RES* getResult();
	MYSQL_ROW getRow();
	bool clear();

	const char* getError();
	bool lock(char *szTable, int nMode);
	bool unLock();

	__int64 getLastID();
	__int64 getRowCount();

	void convertEscape(std::string &str);
	bool allive_check();

private:
	MYSQL m_mysql;
	MYSQL *m_connection;
	MYSQL_RES *m_result;
	MYSQL_ROW m_row;
	bool m_flg;
};

