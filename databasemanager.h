#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager {
public:
    // 获取数据库管理实例（单例）
    static DatabaseManager* instance();

    // 获取数据库连接
    QSqlDatabase& db();

private:
    // 私有构造函数，禁止外部创建实例
    DatabaseManager();
    // 私有析构函数
    ~DatabaseManager();

    // 静态指针，用于保存唯一的实例
    static DatabaseManager* s_instance;
    // QSqlDatabase 类型的成员变量，用于保存数据库连接
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
