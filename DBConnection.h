#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include "IDBConnection.h"

// Реализация соединения с базой данных
class DBConnection : public IDBConnection {
public:
    bool open() override {
        // Реализация подключения (заглушка)
        return true; 
    }

    void close() override {
        // Реализация закрытия соединения
    }

    std::string execQuery(const std::string& query) override {
        // Выполнение запроса (заглушка)
        return "result"; 
    }
};

#endif 