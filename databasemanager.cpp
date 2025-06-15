#include "DatabaseManager.h"

// 初始化静态实例为 nullptr
DatabaseManager* DatabaseManager::s_instance = nullptr;

DatabaseManager::DatabaseManager() {
    // 创建数据库连接
    m_db = QSqlDatabase::addDatabase("QODBC");

    // 设置数据库名称和连接信息
    m_db.setDatabaseName("flight_db");  // 数据库名称
    m_db.setUserName("root");  // ODBC 连接无需用户名
    m_db.setPassword("123456");  // ODBC 连接无需密码

    // 打开数据库连接
    if (!m_db.open()) {
        qDebug() << "Database connection failed: " << m_db.lastError().text();
    } else {
        qDebug() << "Database connection successful.";
    }
}

DatabaseManager::~DatabaseManager() {
    // 在析构函数中关闭数据库连接
    m_db.close();
}

DatabaseManager* DatabaseManager::instance() {
    // 如果单例实例为空，创建一个新的实例
    if (!s_instance) {
        s_instance = new DatabaseManager();
    }
    return s_instance;
}

QSqlDatabase& DatabaseManager::db() {
    return m_db;  // 返回数据库连接
}
